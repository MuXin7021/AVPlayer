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
    void searchMusic(QString dirPath);
    void findFormat(QString &path, QStringList format, QList<QString>& receiveFilePath);
    void playMusic(int index);
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

    void on_commandLinkButton_clicked();

private:
    Ui::AudioPlay *ui;
    QMediaPlayer *player;
    QMediaPlaylist *playerList;
    int  playerIndex;
    int  playerPrevious;
    int  playerMode;
    QSettings *configIniWrite; //配置文件写指针
    QSettings *configIniRead; //配置文件读指针
    QSettings *configIniDelete; //配置文件删除指针
    videowidget *videoPlayWidget; //定义一个视频播放界面

    bool mDrag;             //是否在拖动
    QPoint mDragPos;        //拖动起始点
    bool mIsMax;            //当前是否最大化
    QRect mLocation;        //最大化后恢复时的位置


protected:
    bool eventFilter(QObject *obj, QEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

    void dragEnterEvent(QDragEnterEvent * event);
    void dropEvent(QDropEvent * event);

};

#endif // AUDIOPLAY_H
