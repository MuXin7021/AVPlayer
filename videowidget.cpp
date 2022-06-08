#include "videowidget.h"

videowidget::videowidget()
{

}

void videowidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    qDebug()<< __FUNCTION__;
    this->setFullScreen(!this->isFullScreen());
}
