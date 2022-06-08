#ifndef MEDIALIB_H
#define MEDIALIB_H

#include<QMediaPlayer>
#include<QSettings>
#include<QStringList>
class mediaLib
{
private:
    mediaLib();
public:
    static mediaLib* Get()//创建单例模式
    {
        static mediaLib ml;
        return &ml;
    }
    QMediaPlayer *player;
    QMediaPlaylist *playerList;
    int  playerIndex;
    int  playerPrevious;
    int  playerMode;

    QSettings *configIniWrite; //配置文件写指针
    QSettings *configIniRead; //配置文件读指针
    QSettings *configIniDelete; //配置文件删除指针

    QStringList getAll(QStringList& list);
    void addToLib(QString key,QString val);
    QString getValue(QString key);
    void removeValue(QString );
};

#endif // MEDIALIB_H
