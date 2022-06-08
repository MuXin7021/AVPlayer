#include "audio.h"

#include <QObject>
#include <QIODevice>
#include <QAudioFormat>
#include<QAudioOutput>
#include <QMutex>
#include <QDebug>
#include <QOpenGLWidget>
//#include<QtOpenGLWidgets/QOpenGLWidget>
audio::audio()
{

}

audio::~audio()
{

}

XAudioPlay::XAudioPlay()
{

}


XAudioPlay* XAudioPlay::Get()
{
    static XAudioPlay ap;
    return &ap;
}

void XAudioPlay::Stop()
{
    mutex.lock();
    if (output)//为打开AudioOutput
    {
        output->stop();
        delete output;
        output = NULL;
        io = NULL;
    }
    mutex.unlock();
}

bool XAudioPlay::Start()
{
    Stop();
    mutex.lock();
    QAudioFormat fmt;//设置音频输出格式
    //fmt.setSampleRate(48000);//1秒的音频采样率
    //44100比48000好
    fmt.setSampleRate(43000);//1秒的音频采样率
    fmt.setSampleSize(16);//声音样本的大小
    fmt.setChannelCount(2);//声道
    fmt.setCodec("audio/pcm");//解码格式
    fmt.setByteOrder(QAudioFormat::LittleEndian);
    //fmt.setSampleType(QAudioFormat::UnSignedInt);//设置音频类型
    fmt.setSampleType(QAudioFormat::SignedInt);

    output = new QAudioOutput(fmt);
    io = output->start();//播放开始
    mutex.unlock();
    return true;
}

void XAudioPlay::Play(bool isplay)
{
    mutex.lock();
    if (!output)
    {
        mutex.unlock();
        return;
    }

    if (isplay)
    {
        output->resume();//恢复播放
    }
    else
    {
        output->suspend();//暂停播放
    }
    mutex.unlock();
}


int XAudioPlay::GetFree()
{
    mutex.lock();
    if (!output)
    {
        mutex.unlock();
        return 0;
    }
    int free = output->bytesFree();//剩余的空间

    mutex.unlock();

    return free;
}

bool XAudioPlay::Write(const char *data, int datasize)
{
    mutex.lock();
    if (io){
        io->write(data, datasize);//将获取的音频写入到缓冲区中
        qDebug()<<"write in successed";
    }
    mutex.unlock();
    return true;
}

int XAudioPlay::setVolume(int iVol){
    if(output){
        double k=static_cast<double>(iVol) / 100.0;
        output->setVolume(k);
    }
    //return 1;
}
