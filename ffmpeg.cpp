#include "ffmpeg.h"
#include <QString>
#include <QMutex>
#include <QDebug>
#include <QImage>
#include <QPainter>
extern "C"{
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
#include <libavutil/imgutils.h>
#include <libswresample/swresample.h>

}

double r2d(AVRational r)
{
    return r.den == 0 ? 0 : (double)r.num / (double)r.den;
}


ffmpeg::ffmpeg()
{
    av_register_all(); //注册FFMpeg的库
    Init();
}

ffmpeg::~ffmpeg()
{

}

void ffmpeg::Init() {
    m_errorBuff[0] = '\0';
    m_pAVFormatCtx = NULL;//解封装上下文
    m_PyuvFrame = NULL;//解码后的视频帧数据
    m_PpcmFrame = NULL;//解码后的音频数据
    m_pSwsCtx = NULL;//视频转码上下文
    m_pSwrCtx = NULL;//音频重采样上下文

    m_totalMs = 0;//总时长
    m_videoStream = 0;//视频流
    m_audioStream = 1;//音频流
    m_fps = 0;//每秒的视频帧数

    m_pts = 0;//获得当前解码帧的时间

    m_sampleRate = 48000;//样本率
    m_sampleSize = 16;//样本大小
    m_channel = 2;///通道数

    //m_isPlay = false;
    video_clock=0;
    audio_clock=0;
    last_video_pts=0;
    last_video_delay=0;
    actual_delay=0;
}



void ffmpeg::myClose()
{
    m_mutex.lock();//需要上锁，以防多线程中这里在close，另一个线程中在读取，
    if (m_pAVFormatCtx) avformat_close_input(&m_pAVFormatCtx);//关闭上下文空间
    if (m_PyuvFrame) av_frame_free(&m_PyuvFrame);//关闭时释放解码后的视频帧空间
    if (m_PpcmFrame) av_frame_free(&m_PpcmFrame);//关闭时释放解码后的音频空间
    if (m_pSwsCtx)
    {
        sws_freeContext(m_pSwsCtx);//释放转码器上下文空间
        m_pSwsCtx = NULL;
    }
    if (m_pSwrCtx)
    {
        swr_free(&m_pSwrCtx);//释放音频上下文空间
    }

    m_mutex.unlock();
}


int ffmpeg::readFile(QString name) { //打开视频文件
    myClose();

    m_mutex.lock();//锁

    const char* str=name.toLocal8Bit().data();

    int ret = avformat_open_input(&m_pAVFormatCtx, str, 0, 0);//打开解封装器
    if (ret != 0)//打开错误时
    {
        m_mutex.unlock();//解锁
        av_strerror(ret, m_errorBuff, sizeof(m_errorBuff));//错误信息
        printf("open %s failed :%s\n", str , m_errorBuff);
        return ret;
    }


    avformat_find_stream_info(m_pAVFormatCtx,0);

    //解码器
    for (int i = 0; i < m_pAVFormatCtx->nb_streams; i++)
    {
        AVCodecContext* avCodecCtx = m_pAVFormatCtx->streams[i]->codec;//解码上下文

        if (avCodecCtx->codec_type == AVMEDIA_TYPE_VIDEO)//判断是否为视频
        {

            m_videoStream = i;
            m_fps = r2d(m_pAVFormatCtx->streams[i]->avg_frame_rate);//获得每秒的视频帧数
            AVCodec* avCodec = avcodec_find_decoder(avCodecCtx->codec_id);//查找解码器
            if (!avCodec)//未找到解码器
            {
                m_mutex.unlock();
                printf("video code not find\n");
                return 0;
            }
            int err = avcodec_open2(avCodecCtx, avCodec, NULL);//打开解码器
            if (err != 0)//未打开解码器
            {
                m_mutex.unlock();
                char buf[1024] = { 0 };
                av_strerror(err, buf, sizeof(buf));
                printf("not open!  %s", buf);
                return 0;
            }
            printf("open codec success!\n");

        }
        else if (avCodecCtx->codec_type == AVMEDIA_TYPE_AUDIO)//若为音频流
        {

            m_audioStream = i;//音频流
            AVCodec* avCodec = avcodec_find_decoder(avCodecCtx->codec_id);//查找解码器
            if (avcodec_open2(avCodecCtx, avCodec, NULL) < 0)
            {
                m_mutex.unlock();
                return 0;
            }
            m_sampleRate = avCodecCtx->sample_rate;//样本率
            m_channel = avCodecCtx->channels;//通道数
            switch (avCodecCtx->sample_fmt)//样本大小
            {
            case AV_SAMPLE_FMT_S16://signed 16 bits
                m_sampleSize = 16;
                break;
            case  AV_SAMPLE_FMT_S32://signed 32 bits
                m_sampleSize = 32;
            default:
                break;
            }

        }
    }//至此为打开解码器过程


    m_totalMs = m_pAVFormatCtx->duration / (AV_TIME_BASE);//获取视频的总时间

    if(m_pAVFormatCtx->duration==AV_NOPTS_VALUE){
       int hours,mins,secs,us;
       int64_t duration=m_pAVFormatCtx->duration+5000;
       secs=duration/AV_TIME_BASE;
       us=duration%AV_TIME_BASE;//1000000
       mins=secs/60;
       secs%=60;
       hours=mins/60;
       mins%=60;
       //printf("%02d:%02d:%02d.%02d\n",hours,mins,secs,(100*us)/AV_TIME_BASE);
    }
    m_mutex.unlock();
    return 0;
}


//读取视频的一帧
AVPacket ffmpeg::readPacket()
{
    AVPacket pkt;
    memset(&pkt, 0, sizeof(AVPacket));
    m_mutex.lock();
    if (!m_pAVFormatCtx)
    {
        m_mutex.unlock();
        return pkt;
    }
    int err = av_read_frame(m_pAVFormatCtx, &pkt);//读取视频帧
    if (err != 0)//读取失败
    {
        av_strerror(err, m_errorBuff, sizeof(m_errorBuff));
    }
    m_mutex.unlock();
    return pkt;
}



//读取到每帧数据后需要对其进行解码,返回它的pts
double ffmpeg::decodePacket(const AVPacket* pkt)
{
    m_mutex.lock();
    if (!m_pAVFormatCtx)//若未打开视频
    {
        m_mutex.unlock();
        return -1;

    }
    if (m_PyuvFrame == NULL)//申请解码的对象空间
    {
        m_PyuvFrame = av_frame_alloc();
    }
    if (m_PpcmFrame == NULL)
    {
        m_PpcmFrame = av_frame_alloc();
    }
    AVFrame* frame = m_PyuvFrame;//此时的frame是解码后的视频流
    if (pkt->stream_index == m_audioStream)//若为音频
    {
        frame = m_PpcmFrame;//此时frame是解码后的音频流
    }
    int ret = avcodec_send_packet(m_pAVFormatCtx->streams[pkt->stream_index]->codec, pkt);//xiang jie ma qi 发送之前读取的pkt
    if (ret != 0)
    {
        m_mutex.unlock();
        return -1;
    }

    ret = avcodec_receive_frame(m_pAVFormatCtx->streams[pkt->stream_index]->codec, frame);//解码pkt后存入yuv中
    if (ret != 0)
    {
        m_mutex.unlock();
        return -1;
    }

    m_mutex.unlock();

    double p = frame->pts * r2d(m_pAVFormatCtx->streams[pkt->stream_index]->time_base);//当前解码的显示时间
    if (pkt->stream_index == m_audioStream)//为音频流时设置pts
        m_pts = p;

    return p;
}


QImage ffmpeg::toRGB( AVFrame *vFrame)
{
    if (!m_pAVFormatCtx || !vFrame)//未打开视频文件或者未解码
    {
        QImage image;
        return image;
    }

    AVCodecContext* videoCtx = m_pAVFormatCtx->streams[m_videoStream]->codec;
    AVFrame *pFrameRGB = av_frame_alloc();

    double w_lab=width;
    double h_lab=height;
    double w_img=videoCtx->width;
    double h_img=videoCtx->height;

    double rate_w=w_img/w_lab;
    double rate_h=h_img/h_lab;
    double rate=rate_h>rate_w?rate_h:rate_w;

    int w_new=static_cast<int>(w_img/rate);
    int h_new=static_cast<int>(h_img/rate);


    unsigned char *out_buffer = (unsigned char *)av_malloc((size_t)av_image_get_buffer_size(AV_PIX_FMT_RGB32, int(w_new),int(h_new), 1));
    av_image_fill_arrays(pFrameRGB->data, pFrameRGB->linesize, out_buffer,
        AV_PIX_FMT_RGB32, int(w_new), int(h_new), 1);


    //第7个参数SWS_BICUBIC
    SwsContext * img_convert_ctx = sws_getContext(int(w_img), int(h_img), videoCtx->pix_fmt,
        w_new, h_new, AV_PIX_FMT_RGB32, SWS_BICUBIC, nullptr, nullptr, nullptr);



    sws_scale(img_convert_ctx, (const unsigned char* const*)vFrame->data, vFrame->linesize, 0, int(h_img),
                        pFrameRGB->data, pFrameRGB->linesize);


    QImage img((uchar*)pFrameRGB->data[0],int(w_new),int(h_new),QImage::Format_RGB32);


    return img;

    //return true;
}


int ffmpeg::toPCM(char* out,AVFrame* af)
{
    m_mutex.lock();
    if (!m_pAVFormatCtx || !af || !out)//文件未打开，解码器未打开，无数据
    {
        m_mutex.unlock();
        return 0;
    }
    AVCodecContext *avCodecCtx_Audio = m_pAVFormatCtx->streams[m_audioStream]->codec;//音频解码器上下文
    if(m_pSwrCtx == NULL)
    {
        m_pSwrCtx = swr_alloc();//初始化
        swr_alloc_set_opts(m_pSwrCtx,avCodecCtx_Audio->channel_layout,AV_SAMPLE_FMT_S16,
              avCodecCtx_Audio->sample_rate,
              avCodecCtx_Audio->channels,
              avCodecCtx_Audio->sample_fmt,
              avCodecCtx_Audio->sample_rate, 0,0);

        swr_init(m_pSwrCtx);
    }
    uint8_t  *data[1];
    data[0] = (uint8_t *)out;
    int len = swr_convert(m_pSwrCtx, data, 10000, (const uint8_t **)af->data, af->nb_samples);
    if(len <= 0)
    {
        m_mutex.unlock();
        return 0;
    }

    int outsize = av_samples_get_buffer_size(NULL, avCodecCtx_Audio->channels,
        af->nb_samples,AV_SAMPLE_FMT_S16,0);

    m_mutex.unlock();

    return outsize;
}

bool ffmpeg::Seek(double pos){
        if (!m_pAVFormatCtx)//未打开视频
        {
            return false;
        }
        int64_t stamp = 0;
        stamp = pos * m_pAVFormatCtx->streams[m_videoStream]->duration;//当前它实际的位置
        int re = av_seek_frame(m_pAVFormatCtx, m_videoStream, stamp,
            AVSEEK_FLAG_BACKWARD | AVSEEK_FLAG_FRAME);//将视频移至到当前点击滑动条位置
        avcodec_flush_buffers(m_pAVFormatCtx->streams[m_videoStream]->codec);//刷新缓冲,清理掉
        if (re > 0)
            return true;
        return false;
}

double ffmpeg::getVideoPTS(AVFrame *frame,const AVPacket* pkt){
    double pts=frame->best_effort_timestamp;
    if (pts==AV_NOPTS_VALUE){
        pts=0;
    }
    pts*=av_q2d(m_pAVFormatCtx->streams[pkt->stream_index]->time_base);

    return pts;
}

double ffmpeg::getAudioPTS(AVFrame *frame, const AVPacket *pkt,int dataSize,int bufSize){
    double pts=frame->pts;
    if(pkt->pts==AV_NOPTS_VALUE){
        pts=0;
    }
    audio_clock=av_q2d(m_pAVFormatCtx->streams[pkt->stream_index]->time_base)*pkt->pts;
    audio_clock+=static_cast<double>(dataSize)/(2*frame->sample_rate*frame->channels);
    return pts;
}
