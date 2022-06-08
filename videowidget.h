#ifndef VIDEOWIDGET_H
#define VIDEOWIDGET_H

#include <QVideoWidget>
#include <QDebug>

class videowidget : public QVideoWidget
{
public:
    videowidget();

private:
    void mouseDoubleClickEvent(QMouseEvent *event);
};

#endif // VIDEOWIDGET_H
