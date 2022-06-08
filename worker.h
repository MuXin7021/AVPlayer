#ifndef WORKER_H
#define WORKER_H
#include <QThread>
#include <QMutex>
#include<QImage>
#include<signal.h>
extern "C"{
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
#include <libavutil/imgutils.h>
#include <libswresample/swresample.h>
}
struct vedio_frame{
    AVFrame vFrame;
    double pts;
};
struct audio_frame{
    AVFrame aFrame;
    int pts;
};


//static QList<vedio_frame> vList;
//static QList<audio_frame> aList;

class worker:public QThread
{
    Q_OBJECT
public:
    static worker* Get()//创建单例模式
    {
        static worker vt;
        return &vt;
    }
    void run();//线程的运行
    virtual ~worker();
    bool isExit = true;
    bool isVedio= false;
    int count;
    double audioPts;
    int errCount;

    QList<vedio_frame> vList;
    QMutex mutex;

    QString filename;    //当前打开的视频
    bool isChanged;      //是否更换了打开的视频

    bool isStop;        //是否停止播放视频
    bool isPause;       //是否暂停播放视频
    bool slidown;

    QMutex& get_Mutex(){
        return mutex;
    }
signals:
    void sig_Send(QImage,double); //没获取到一帧图像 就发送此信号
    void sig_End();
    void audio_send(double);
private:
    worker();

};

#endif // WORKER_H
