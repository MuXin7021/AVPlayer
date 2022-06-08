#ifndef FFMPEG_H
#define FFMPEG_H
#include <QString>
#include <QMutex>
#include <QImage>
#include "worker.h"
extern "C"{
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
#include <libavutil/imgutils.h>
#include <libswresample/swresample.h>
}


class ffmpeg
{
public:
    AVFormatContext *m_pAVFormatCtx;    //解封装上下文
    SwsContext  *m_pSwsCtx;             //视频转码上下文
    SwrContext  *m_pSwrCtx;             //音频重采样上下文
    AVFrame *m_PyuvFrame;           //解码后的视频数据
    AVFrame *m_PpcmFrame;           //解码后的音频数据

    QMutex m_mutex;
    int m_totalMs;               //总时长
    double totalTime;
    int m_videoStream;           //视频流
    int m_audioStream;           //音频流
    double m_fps;                   //每秒的视频帧数

    double m_pts;                   //获得当前解码帧的时间

    int m_sampleRate;            //样本率
    int m_sampleSize;            //样本大小
    int m_channel;               //通道数
    //bool m_isPlay;               //是否在播放
    char m_errorBuff[1024];

    int width=0;
    int height=0;

    double video_clock;
    double audio_clock;
    double last_video_pts;
    double last_video_delay;
    double actual_delay;

public:
    static ffmpeg* get(){
        static ffmpeg fmg;
        return &fmg;
    }
    ~ffmpeg();
    void Init();
    void myClose();
    int readFile(QString);
    AVPacket readPacket();
    double decodePacket(const AVPacket* pkt);
    QImage toRGB(AVFrame *m_PyuvFrame);
    int toPCM(char* out ,AVFrame* af);
    double getVideoPTS(AVFrame*frame,const AVPacket* pkt);
    double getAudioPTS(AVFrame*frame,const AVPacket* pkt,int dataSize,int bufSize);
    bool Seek(double pos);
private:
     ffmpeg();
};

#endif // FFMPEG_H
