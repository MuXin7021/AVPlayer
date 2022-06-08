#include "worker.h"
#include "ffmpeg.h"
#include"audio.h"
#include <QList>
#include <QDebug>
#include <QTime>

worker::worker()
{
    filename="";
    isStop=true;
    isPause=false;
    isChanged=false;
    isExit=false;
    audioPts=0;
    errCount=0;
    vList.clear();
    slidown=false;
}
worker::~worker()
{

}

void worker::run() {  //该线程负责的工作就是读取视频的每一帧，然后解码，将解码的Frame放到v/a List 中给主线程使用
    char out[10000] = {0};
    int countN=0;
    while(!isExit){
        while(!isStop){
            if (isPause==true)//如果为暂停状态，不处理
            {
                if(slidown==true){
                    vList.clear();
                    slidown=false;
                    msleep(200);
                }
                msleep(50);
                continue;
            }

            if(isChanged==true){  //播放的视频改变了
                isChanged=false;

                while(ffmpeg::get()->readFile(filename)<0){
                    msleep(10);
                }

                memset(out,0,sizeof(out));

                //清空视频队列
                vList.clear();
                XAudioPlay::Get()->Start();
                audioPts=0;
                msleep(20);
                continue;
            }

            while (vList.size() > 0)//确定list中是否有视频帧
            {
                AVFrame vfr = vList.front().vFrame;//每次取出list中的第一个AVPack包
                double pts=vList.front().pts;
                if (pts > audioPts)//若视屏包大于音频包的pts，结束
                {
                    break;
                }
                QImage img=ffmpeg::get()->toRGB(&vfr);
                vList.pop_front();//从list链表中删除
                emit sig_Send(img,pts);
            }

            int free = XAudioPlay::Get()->GetFree();//此时缓冲区的空间大小
            if (free < 10000)
            {
                msleep(1);
                continue;
            }
            AVPacket pkt = ffmpeg::get()->readPacket();
            ++countN;
            if (pkt.size <= 0)//未打开视频
            {
                ++errCount;
                if(errCount>=15){
                    isStop=true;
                    errCount=0;
                    emit sig_End();
                    continue;
                }
                msleep(5);
                continue;
            }
            if (pkt.stream_index == ffmpeg::get()->m_audioStream)
            {
                audioPts = ffmpeg::get()->decodePacket(&pkt);//解码音频
                av_packet_unref(&pkt);//释放pkt包S
                int len = ffmpeg::get()->toPCM(out,ffmpeg::get()->m_PpcmFrame);//重采样音频
                XAudioPlay::Get()->Write(out, len);//写入音频
                emit audio_send(audioPts);
                continue;
            }else if(pkt.stream_index == ffmpeg::get()->m_videoStream){
                vedio_frame* vf=new vedio_frame();
                vf->pts=ffmpeg::get()->decodePacket(&pkt);

                vf->vFrame=*ffmpeg::get()->m_PyuvFrame;
                vList.push_back(*vf);
            }
            av_packet_unref(&pkt);//清理该AVPacket包
        }
    }
}
