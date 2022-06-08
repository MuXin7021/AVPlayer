#include "Player.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AudioPlay w;
    w.show();

    return a.exec();
}
