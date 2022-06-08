#include "medialib.h"

mediaLib::mediaLib()
{

}

QStringList mediaLib::getAll(QStringList& list){
    QSettings* fileSetting = new QSettings("D:/PlayList.ini", QSettings::IniFormat);
    fileSetting->beginGroup("song");    // 设置查找节点
    //key中是文件名和后缀，value是文件的绝对路径
    QStringList str = fileSetting->allKeys();    // 获取所有的key
    foreach(QString key,str){
        list.append(fileSetting->value(key).toString());
    }
    fileSetting->endGroup();   // 结束掉Group
    return str;
}

void mediaLib::addToLib(QString key,QString val){
    QSettings* fileSetting = new QSettings("D:/PlayList.ini", QSettings::IniFormat);
    fileSetting->setValue("/song/"+key,val);
}

QString mediaLib::getValue(QString key){
    QSettings* fileSetting = new QSettings("D:/PlayList.ini", QSettings::IniFormat);
    return fileSetting->value("/song/"+key).toString();
}

void mediaLib::removeValue(QString key){
    QSettings* fileset=new QSettings("D:/PlayList.ini", QSettings::IniFormat);
    QString name=fileset->value("/song/"+key).toString();
    fileset->remove(name);
}
