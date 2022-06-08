#ifndef AUDIOPLAY_H
#define AUDIOPLAY_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QFile>
#include <QFileInfo>
#include <QDirIterator>
#include <QDebug>
#include <QMediaPlaylist>
#include <QTableWidgetItem>
#include <QFileDialog>
#include <QMediaMetaData>
#include <QMediaRecorder>
#include <QSettings>
#include <QTableWidgetItem>
#include <QMessageBox>
#include <QTextCodec>
#include "videowidget.h"
#include <QMouseEvent>
#include <QEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QPixmap>
#include <QSlider>
#include <QKeyEvent>
#include <QDesktopServices>
#include <QUrl>


namespace Ui {
class AudioPlay;
}

class AudioPlay : public QMainWindow
{
    Q_OBJECT

public:
    explicit AudioPlay(QWidget *parent = 0);
    ~AudioPlay();
    void findFormat(QString &path, QStringList format, QList<QString>& receiveFilePath);
    void playMusic(int index,int Method);
    void GetTime(qint64 playtime);
private slots:
    void on_tableWidget_cellDoubleClicked(int row, int column);

    void on_PushButton_OpenFile_clicked();

    void on_PushButton_PlayStop_clicked();

    void on_PushButton_Previous_clicked();

    void on_PushButton_Next_clicked();

    void on_Slider_Volume_valueChanged(int value);

    void do_getduration_slots(qint64 playtime);

    void do_updatePosition_slots(qint64 position);

    void on_Slider_ProgressBar_sliderReleased();

    void on_PushButton_PlayMode_clicked();

    void on_PushButton_DeleteMusic_clicked();

    void on_pushButton_WindowMin_clicked();

    void on_pushButton_WindowMax_clicked();

    void on_pushButton_WindowExit_clicked();

    void on_Slider_Volume_actionTriggered(int action);

    void on_Slider_Volume_sliderMoved(int position);

    void on_Slider_ProgressBar_sliderPressed();

    void keyPressEvent(QKeyEvent*);

public slots:
    void sig_Recv(QImage,double );
    void sig_rEnd();
    void audio_recv(double);
private:
    Ui::AudioPlay *ui;

    bool Playing=false;     //是否正在播放
    QStringList playList;
    QStringList fileList;
    //videowidget *videoPlayWidget; //定义一个视频播放界面

    bool mDrag;             //是否在拖动
    QPoint mDragPos;        //拖动起始点
    bool mIsMax;            //当前是否最大化
    QRect mLocation;        //最大化后恢复时的位置
    int playMode;           //1表示列表循环播放，2表示单曲循环播放，3表示随机播放，如果当前播放视频不再媒体库中，则停止播放

protected:
    bool eventFilter(QObject *obj, QEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void Clear();
    void dragEnterEvent(QDragEnterEvent * event);
    void dropEvent(QDropEvent * event);

};

#endif // AUDIOPLAY_H
