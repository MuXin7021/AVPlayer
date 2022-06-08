#ifndef AUDIO_H
#define AUDIO_H

#include <QObject>
#include <QIODevice>
#include <QAudioFormat>
#include <QAudioOutput>
#include <QMutex>

class audio
{
public:
    //static XAudioPlay *Get();//单例模式
    virtual bool Start()=0;//开始
    virtual void  Play(bool isplay)=0;//是否播放
    virtual bool Write(const char *data,int datasize) = 0;//将音频写入
    virtual void Stop()=0;//停止
    virtual int GetFree() = 0;//获取剩余空间
    virtual int setVolume(int iVol) = 0;//
    virtual ~audio();
    int sampleRate = 48000;//样本率
    int sampleSize = 16;//样本大小
    int channel = 2;///通道数
protected:
    audio();
};


class XAudioPlay :public audio
{
public:

    QAudioOutput *output = NULL;
    QIODevice *io = NULL;
    QMutex mutex;
    void Stop();

    //static audio *Get();

    //首先设置播放的格式以及参数
    bool Start();

    void  Play(bool isplay);

    int GetFree();

    bool Write(const char *data, int datasize);

    int setVolume(int iVol);

    static XAudioPlay *Get();//单例模式
private:
    XAudioPlay();
};

#endif // AUDIO_H
