#include "Player.h"
#include "ui_Player.h"

#include "ffmpeg.h"
#include "worker.h"
#include "audio.h"
#include "medialib.h"
#include <QDesktopWidget>
#include <QMutex>
#include <QAudioFormat>
#include <QAudioOutput>
#include <QFile>
#include <QDebug>
#include <QFileDialog>
#include <QIODevice>
#include <QTime>
#include <QImage>
#include <QObject>
#include <QIODevice>
#include <QAudioFormat>
#include<QAudioOutput>
#include <QMutex>
#include <QDebug>
#include <QTime>
#include <QDateTime>
#include <QOpenGLWidget>

AudioPlay::AudioPlay(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AudioPlay)
{
    ui->setupUi(this);

    ui->PushButton_Next->setShortcut(QKeySequence("Ctrl+Right"));
    ui->PushButton_Previous->setShortcut(QKeySequence("Ctrl+Left"));
    ui->PushButton_OpenFile->setShortcut(QKeySequence("Ctrl+i"));
    ui->PushButton_PlayStop->setShortcut(Qt::Key_Space);

    if(connect(worker::Get(), SIGNAL(sig_Send(QImage,double)), this, SLOT(sig_Recv(QImage,double)))){
        qDebug()<<"bind success";
    }else{
        qDebug()<<"failed";
    }

    if(connect(worker::Get(), SIGNAL(sig_End()), this, SLOT(sig_rEnd()))){
        qDebug()<<"bind success";
    }else{
        qDebug()<<"failed2";
    }

    if(connect(worker::Get(), SIGNAL(audio_send(double)), this, SLOT(audio_recv(double)))){
        qDebug()<<"bind success";
    }else{
        qDebug()<<"failed3";
    }

    ui->Slider_Volume->setValue(50);
    ui->label_Volume->setText("50%");
    // 允许文件拖拽到窗口部分
    this->setAcceptDrops(true);
    mLocation = this->geometry();
    mIsMax = false;
    mDrag = false;
    //


    // 手动添加窗口顶部处理部分
    this->installEventFilter(this); // 事件过滤器就是接收所有被发送到这个对象的事件的对象

    ui->pushButton_WindowMin->setIcon(QIcon(":/image/jianhao.png"));
    ui->pushButton_WindowMin->setIconSize(QSize(16,16));

    ui->pushButton_WindowMax->setIcon(QIcon(":/image/fangkuang.png"));
    ui->pushButton_WindowMin->setIconSize(QSize(16,16));

    ui->pushButton_WindowExit->setIcon(QIcon(":/image/guanbi.png"));
    ui->pushButton_WindowMin->setIconSize(QSize(16,16));



    ui->pushButton_WindowMin->setFlat(true);
    ui->pushButton_WindowMin->setStyleSheet("QPushButton{border:none;background:transparent;}");

    ui->pushButton_WindowMax->setFlat(true);
    ui->pushButton_WindowMax->setStyleSheet("QPushButton{border:none;background:transparent;}");

    ui->pushButton_WindowExit->setFlat(true);
    ui->pushButton_WindowExit->setStyleSheet("QPushButton{border:none;background:transparent;}");

    ui->tableWidget->setShowGrid(false);//隐藏表格线
    setStyleSheet("QMainWindow{color:#E8E8E8;background:#43CD80;}");



    // 设置窗口名称，图标
    this->setWindowTitle(QTextCodec::codecForName("GBK")->toUnicode("MediaPlayer"));
    this->setWindowIcon(QIcon(":/image/icon.png"));

    QPixmap *pixmap = new QPixmap(":/image/icon.png");
    pixmap->scaled(ui->logo->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->logo->setScaledContents(true);
    ui->logo->setPixmap(*pixmap);
    ui->label_Title->setText(QTextCodec::codecForName("GBK")->toUnicode("Player"));
    QFont ft( "Microsoft YaHei", 12, 75);
    ui->label_Title->setFont(ft);

    // 设置背景图片为bj.jpg
    this->setObjectName("mainWindow");
    this->setStyleSheet("#mainWindow{border-image:url(:/image/bj.png);}");

    this->setWindowFlags(Qt::FramelessWindowHint);//无边框

    // 设置按键图标
    ui->PushButton_PlayStop->setIcon(QIcon(":/image/bofang.png"));
    ui->PushButton_PlayStop->setIconSize(QSize(55,55));

    ui->PushButton_PlayMode->setIcon(QIcon(":/image/yinlebofangye-xunhuanbofang.png"));
    ui->PushButton_PlayMode->setIconSize(QSize(48,48));

    ui->PushButton_Previous->setIcon(QIcon(":/image/shangyishou.png"));
    ui->PushButton_Previous->setIconSize(QSize(48,48));

    ui->PushButton_Next->setIcon(QIcon(":/image/xiayishou.png"));
    ui->PushButton_Next->setIconSize(QSize(48,48));

    ui->PushButton_OpenFile->setIcon(QIcon(":/image/tianjiagequ.png"));
    ui->PushButton_OpenFile->setIconSize(QSize(48,48));

    ui->PushButton_DeleteMusic->setIcon(QIcon(":/image/shanchu.png"));
    ui->PushButton_DeleteMusic->setIconSize(QSize(48,48));


    QPixmap *pixmap1 = new QPixmap(":/image/jurassic.png");
    pixmap->scaled(QSize(16,16), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->label_Volume_2->setScaledContents(true);
    ui->label_Volume_2->setPixmap(*pixmap1);

    // 设置图标为透明

    ui->PushButton_PlayStop->setFlat(true);
    ui->PushButton_PlayStop->setStyleSheet("QPushButton{border:none;background:transparent;}");

    ui->PushButton_PlayMode->setFlat(true);
    ui->PushButton_PlayMode->setStyleSheet("QPushButton{border:none;background:transparent;}");

    ui->PushButton_Previous->setFlat(true);
    ui->PushButton_Previous->setStyleSheet("QPushButton{border:none;background:transparent;}");

    ui->PushButton_Next->setFlat(true);
    ui->PushButton_Next->setStyleSheet("QPushButton{border:none;background:transparent;}");

    ui->PushButton_OpenFile->setFlat(true);
    ui->PushButton_OpenFile->setStyleSheet("QPushButton{border:none;background:transparent;}");

    ui->PushButton_DeleteMusic->setFlat(true);
    ui->PushButton_DeleteMusic->setStyleSheet("QPushButton{border:none;background:transparent;}");

    ui->label_Volume->setStyleSheet("QLabel{border:none;background:transparent;}");

    ui->label_MusicTime->setStyleSheet("QLabel{border:none;background:transparent;}");

    ui->label_PlayTime->setStyleSheet("QLabel{border:none;background:transparent;}");

    ui->Slider_Volume->setStyleSheet("QSlider{border:none;background:transparent;}");

    ui->Slider_ProgressBar->setStyleSheet("QSlider{border:none;background:transparent;}");

    ui->label_Volume_2->setStyleSheet("QLabel{border:none;background:transparent;}");

    ui->tableWidget->verticalHeader()->setHidden(true);
    ui->tableWidget->setStyleSheet("QTableView::item:selected{color:black;background:black;}");
    ui->tableWidget->setStyleSheet("QTableWidget{border:none;background:transparent;}");


    //设置进度条的步长
    ui->Slider_ProgressBar->setMinimum(0);  // 最小值
    ui->Slider_ProgressBar->setSingleStep(1);  // 步长
    // 读取配置文件的内容：歌曲名 把前一次写入的歌曲读出来
    playList=mediaLib::Get()->getAll(fileList);
    foreach(QString s, playList){
        int rownum=ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(rownum);
        ui->tableWidget->setItem(rownum, 0, new QTableWidgetItem(s));
    }

    playMode=1;   //初始为列表循环播放

    ui->lab22->setGeometry(1,1,812,595);
    ffmpeg::get()->width=ui->lab22->width();
    ffmpeg::get()->height=ui->lab22->height();
    worker::Get()->start();
}

AudioPlay::~AudioPlay()
{
    delete ui;
}
void AudioPlay::Clear(){
    ui->lab22->clear();
}
void delay(int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void AudioPlay::sig_Recv(QImage img,double pts){
    this->ui->lab22->setPixmap(QPixmap::fromImage(img)); // 在label上播放视频图片
    ui->lab22->setScaledContents(true);

}

void AudioPlay::audio_recv(double pts){
    if(mDrag==true)return ;
    int tatal=ffmpeg::get()->m_totalMs;   //视频的总长度
    int pos=(int)pts;
    ui->Slider_ProgressBar->setMaximum(tatal+1);  // 最大值
    ui->Slider_ProgressBar->setValue(pos);
    QString nowTime=QDateTime::fromTime_t(pos).toString("mm:ss");
    QString totTime=QDateTime::fromTime_t(tatal).toString("mm:ss");
    ui->label_PlayTime->setText(nowTime);
    ui->label_MusicTime->setText(totTime);
}
void AudioPlay::sig_rEnd(){
    QString tname=worker::Get()->filename;
    foreach(QString nstr,fileList){
        if(nstr==tname){      //在播放列表中
            if(playMode==1){
                QString strn=tname.split('/').back();
                if(strn.back()=='3'){
                    Clear();
                }
                for(int i=0;i<playList.size();i++){
                    if(playList[i]==strn){
                        i=(i+1)%playList.size();
                        worker::Get()->filename=fileList[i];
                        worker::Get()->isChanged=true;
                        worker::Get()->isStop=false;
                        worker::Get()->isPause=false;
                        worker::Get()->audioPts=0;
                        //选中tableWidget的对应行
                        ui->tableWidget->selectRow(i);
                        return ;
                    }
                }
            }else if(playMode==2){   //单曲循环播放
                worker::Get()->isChanged=true;
                worker::Get()->isStop=false;
                worker::Get()->isPause=false;
                worker::Get()->audioPts=0;
                return ;
            }else{
                int npos=rand()%playList.size();
                worker::Get()->filename=fileList[npos];
                if(fileList[npos].back()=='3'){
                    Clear();
                }
                worker::Get()->isChanged=true;
                worker::Get()->isStop=false;
                worker::Get()->audioPts=0;
                worker::Get()->isPause=false;
                //选中tableWidget的对应行
                ui->tableWidget->selectRow(npos);
                return ;
            }
        }
    }
    //不再列表则暂停播放
    ui->PushButton_PlayStop->setIcon(QIcon(":/image/bofang.png"));
    ui->PushButton_PlayStop->setIconSize(QSize(55,55));
}
// 打开文件
void AudioPlay::on_PushButton_OpenFile_clicked()
{
    QString name = QFileDialog::getOpenFileName(this,QString::fromLocal8Bit("选择视频文件"),"",tr("mp4(*.mp4);;mp3(*mp3);;PNG Files(*.png);;PGM Files(*.pgm)"));
    QStringList list=name.split("/");
    mediaLib::Get()->addToLib(list.back(),name);
    foreach(QString s,playList){
        if(s==list.back()){
            QMessageBox::about(this,"视频已经在媒体库中",NULL);
            return ;
        }
    }

    playList.append(list.back());
    fileList.append(name);
    int rownum=ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(rownum);
    ui->tableWidget->setItem(rownum, 0, new QTableWidgetItem(playList.back()));
}

void AudioPlay::findFormat(QString &path, QStringList format, QList<QString>& receiveFilePath)
{
    // 判断路径是否存在
    QDir dir(path);
    if(!dir.exists())   return;

    // 定义迭代器并设置过滤器
    QDirIterator dirIterator(path, format, QDir::Files | QDir::NoSymLinks,QDirIterator::Subdirectories);
    while(dirIterator.hasNext())
    {
        dirIterator.next();
        receiveFilePath.append(dirIterator.fileInfo().absoluteFilePath());
    }
}

// 播放音乐
void AudioPlay::playMusic(int index,int Method)   //index是播放列表中的行号
{

}


// 双击触发槽函数
void AudioPlay::on_tableWidget_cellDoubleClicked(int row, int column)
{
    QString filename=ui->tableWidget->item(row,column)->text();
    QString name=mediaLib::Get()->getValue(filename);
    if(name.back()=='3'){
        Clear();
    }
    if(name!=""&&name.size()!=0){
        worker::Get()->filename=name;

        worker::Get()->isChanged=true;
        worker::Get()->isStop=false;
        worker::Get()->isPause=false;
        worker::Get()->audioPts=0;
        ui->PushButton_PlayStop->setIcon(QIcon(":/image/zanting-xian.png"));
        ui->PushButton_PlayStop->setIconSize(QSize(48,48));
    }
}


// 播放和停止槽函数
void AudioPlay::on_PushButton_PlayStop_clicked()
{
    if(worker::Get()->isStop==true){        //现在没有在播放视频
        QString name = QFileDialog::getOpenFileName(this,QString::fromLocal8Bit("选择视频文件"),"",tr("mp4(*.mp4);;MP3(*.mp3);;PNG Files(*.png);;PGM Files(*.pgm)"));
        if(name!=""&&name.size()!=0){
            for(int i=0;i<fileList.size();i++){
                if(fileList[i]==name){
                    ui->tableWidget->selectRow(i);
                }
            }

            worker::Get()->filename=name;
            worker::Get()->isChanged=true;
            worker::Get()->isStop=false;
            worker::Get()->isPause=false;
            worker::Get()->audioPts=0;
            ui->PushButton_PlayStop->setIcon(QIcon(":/image/zanting-xian.png"));
            ui->PushButton_PlayStop->setIconSize(QSize(48,48));
        }
    }else {
        if(worker::Get()->isPause==true){
            worker::Get()->isPause=false;
            ui->PushButton_PlayStop->setIcon(QIcon(":/image/zanting-xian.png"));
            ui->PushButton_PlayStop->setIconSize(QSize(48,48));
        }else{
            worker::Get()->isPause=true;
            ui->PushButton_PlayStop->setIcon(QIcon(":/image/bofang.png"));
            ui->PushButton_PlayStop->setIconSize(QSize(55,55));
        }
    }
}

// 上一曲
void AudioPlay::on_PushButton_Previous_clicked()
{
    QString tname=worker::Get()->filename;
    foreach(QString nstr,fileList){
        if(nstr==tname){      //在播放列表中
            QString strn=tname.split('/').back();
            for(int i=0;i<playList.size();i++){
                if(playList[i]==strn){
                    i=i-1;
                    if(i<0){
                        i=playList.size()-1;
                    }
                    worker::Get()->filename=fileList[i];
                    worker::Get()->isChanged=true;
                    worker::Get()->isStop=false;
                    worker::Get()->isPause=false;
                    worker::Get()->audioPts=0;
                    //选中tableWidget的对应行
                    ui->tableWidget->selectRow(i);
                    ui->PushButton_PlayStop->setIcon(QIcon(":/image/zanting-xian.png"));
                    ui->PushButton_PlayStop->setIconSize(QSize(48,48));
                    return ;
                }
            }
        }
    }
    //若当前播放的视频不在列表中，则选择列表第一个视频
    int n=fileList.size()-1;
    worker::Get()->filename=fileList[n];
    worker::Get()->isChanged=true;
    worker::Get()->isStop=false;
    worker::Get()->isPause=false;
    worker::Get()->audioPts=0;
    //选中tableWidget的对应行
    ui->tableWidget->selectRow(n);
    ui->PushButton_PlayStop->setIcon(QIcon(":/image/zanting-xian.png"));
    ui->PushButton_PlayStop->setIconSize(QSize(48,48));
}

// 下一曲
void AudioPlay::on_PushButton_Next_clicked()
{
    QString tname=worker::Get()->filename;

    foreach(QString nstr,fileList){
        if(nstr==tname){      //在播放列表中
            QString strn=tname.split('/').back();
            for(int i=0;i<playList.size();i++){
                if(playList[i]==strn){
                    i=(i+1)%playList.size();
                    worker::Get()->filename=fileList[i];
                    worker::Get()->isChanged=true;
                    worker::Get()->isStop=false;
                    worker::Get()->isPause=false;
                    worker::Get()->audioPts=0;
                    ui->tableWidget->selectRow(i);
                    ui->PushButton_PlayStop->setIcon(QIcon(":/image/zanting-xian.png"));
                    ui->PushButton_PlayStop->setIconSize(QSize(48,48));
                    return ;
                }
            }
        }
    }
    //若当前播放的视频不在列表中，则选择列表最后一个视频
    worker::Get()->filename=fileList[0];
    worker::Get()->isChanged=true;
    worker::Get()->isStop=false;
    worker::Get()->isPause=false;
    worker::Get()->audioPts=0;
    //选中tableWidget的对应行
    ui->tableWidget->selectRow(0);
    ui->PushButton_PlayStop->setIcon(QIcon(":/image/zanting-xian.png"));
    ui->PushButton_PlayStop->setIconSize(QSize(48,48));
}

// 设置音量
void AudioPlay::on_Slider_Volume_valueChanged(int value)
{
    ui->label_Volume->setText(QString::number(value)+"%");
    XAudioPlay::Get()->setVolume(value);
}


// 获取歌曲时长,歌曲改变时才会执行这个槽函数
void AudioPlay::do_getduration_slots(qint64 playtime)
{

}

// 计算时间
void AudioPlay::GetTime(qint64 playtime)
{
    int h,m,s;
    playtime /= 1000;  //获得的时间是以毫秒为单位的
    h = playtime/3600;
    m = (playtime-h*3600)/60;
    s = playtime-h*3600-m*60;

    ui->label_MusicTime->setText(QString("%1:%2:%3").arg(h,2,10,QLatin1Char('0')).arg(m,2,10,QLatin1Char('0')).arg(s,2,10,QLatin1Char('0')));  // 把int型转化为string类型后再设置为label的text

    }


// 接收歌曲位置改变，改变进度条
void AudioPlay::do_updatePosition_slots(qint64 position)
{
    int h,m,s;

    ui->Slider_ProgressBar->setValue(position);//设置滑块位置

    position /= 1000;  //获得的时间是以毫秒为单位的
    h = position/3600;
    m = (position-h*3600)/60;
    s = position-h*3600-m*60;
    //     arg(整数类型,补位数,进制,补位字符);
    ui->label_PlayTime->setText(QString("%1:%2:%3").arg(h,2,10,QLatin1Char('0')).arg(m,2,10,QLatin1Char('0')).arg(s,2,10,QLatin1Char('0')));  // 把int型转化为string类型后再设置为label的text
}

// 拖动进度松手槽函数
void AudioPlay::on_Slider_ProgressBar_sliderReleased()
{

    double pos = 0;
    mDrag=false;
    //松开时此时滑动条的位置与滑动条的总长度
    worker::Get()->isPause=true;
    worker::Get()->slidown=true;
    pos = (float)ui->Slider_ProgressBar->value() / (double)(ui->Slider_ProgressBar->maximum() + 1);

    ffmpeg::get()->Seek(pos);
    worker::Get()->isPause=false;
    ui->PushButton_PlayStop->setIcon(QIcon(":/image/zanting-xian.png"));
    ui->PushButton_PlayStop->setIconSize(QSize(48,48));
}

// 设置播放模式槽函数
void AudioPlay::on_PushButton_PlayMode_clicked()
{
    ++playMode;
    if(playMode==4)playMode=1;
    switch (playMode) {
        case 1: ui->PushButton_PlayMode->setIcon(QIcon(":/image/yinlebofangye-xunhuanbofang.png"));
                ui->PushButton_PlayMode->setIconSize(QSize(48,48));
        break ;
        case 2: ui->PushButton_PlayMode->setIcon(QIcon(":/image/danquxunhuan.png"));
                ui->PushButton_PlayMode->setIconSize(QSize(48,48));
        break;
        case 3: ui->PushButton_PlayMode->setIcon(QIcon(":/image/suijibofang.png"));
                ui->PushButton_PlayMode->setIconSize(QSize(48,48));
    }
}

// 删除歌曲
void AudioPlay::on_PushButton_DeleteMusic_clicked()
{
      int pos=ui->tableWidget->currentRow();
      if(pos>=0){
          QString str = ui->tableWidget->item(pos,0)->text();

          QSettings* fileset=new QSettings("D:/PlayList.ini", QSettings::IniFormat);
          QString name=fileset->value("/song/"+str).toString();
          fileset->remove("/song/"+str);
          ui->tableWidget->removeRow(pos);

          //将playList和fileList中对应的项也删掉
          playList.removeOne(str);
          fileList.removeOne(name);
      }
}




bool AudioPlay::eventFilter(QObject *obj, QEvent *e)
{
    if (obj == ui->centralWidget)
    {
        if(e->type() == QEvent::MouseButtonDblClick)
        {
            on_pushButton_WindowMax_clicked();
            return true;
        }
    }
    return QObject::eventFilter(obj, e);
}

void AudioPlay::mousePressEvent(QMouseEvent *e)//鼠标按下事件
{
    qDebug() << __FUNCTION__;
    if (e->button() == Qt::LeftButton)
    {
        mDrag = true;
        mDragPos = e->globalPos() - pos();
        e->accept();
    }
}

void AudioPlay::mouseMoveEvent(QMouseEvent *e)//鼠标移动事件
{
    qDebug() << __FUNCTION__;
    if (mDrag && (e->buttons() && Qt::LeftButton))
    {
        move(e->globalPos() - mDragPos);
        e->accept();
    }
}

void AudioPlay::mouseReleaseEvent(QMouseEvent *e)//鼠标释放事件
{
    qDebug() << __FUNCTION__;
    mDrag = false;
}


void AudioPlay::on_pushButton_WindowMin_clicked()
{
    showMinimized();
}

void AudioPlay::on_pushButton_WindowMax_clicked()
{
    if (mIsMax)
       {
            showFullScreen();
       }
       else
       {
            showNormal();

       }
       mIsMax = !mIsMax;

}

void AudioPlay::on_pushButton_WindowExit_clicked()
{
    qApp->exit();
}


//接受拖拽的文件
void AudioPlay::dragEnterEvent(QDragEnterEvent * event)
{
    qDebug()<<__FUNCTION__;
    event->acceptProposedAction();    //接受拖拽的文件
}

// 获取拖拽的文件名
void AudioPlay::dropEvent(QDropEvent * event)
{

}

void AudioPlay::on_Slider_Volume_actionTriggered(int action)
{

}

void AudioPlay::on_Slider_Volume_sliderMoved(int position)
{

}

void AudioPlay::on_Slider_ProgressBar_sliderPressed()
{
    mDrag=true;
}


void AudioPlay::keyPressEvent(QKeyEvent *event)
{
    if (event->modifiers() & Qt::ControlModifier)
       {
        if (event->key() == Qt::Key_W)//增加音量
        {
            QString str=ui->label_Volume->text();
            str = str.left(str.size() - 1);
            int num=str.toInt();
            num+=10;
            if(num>=100){
                num=100;
            }
            ui->label_Volume->setText(QString::number(num)+"%");
            XAudioPlay::Get()->setVolume(num);
            ui->Slider_Volume->setValue(num);
        }
        if (event->key() == Qt::Key_S)//减小音量
        {
            QString str=ui->label_Volume->text();
            str = str.left(str.size() - 1);
            int num=str.toInt();
            num-=10;
            if(num<0){
                num=0;
            }
            ui->label_Volume->setText(QString::number(num)+"%");
            XAudioPlay::Get()->setVolume(num);
            ui->Slider_Volume->setValue(num);
        }
    }
}
