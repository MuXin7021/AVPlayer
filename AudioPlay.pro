#-------------------------------------------------
#
# Project created by QtCreator 2021-12-01T15:24:43
#
#-------------------------------------------------

QT       += core gui multimedia multimediawidgets
RC_ICONS = logo.ico
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Player
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    Player.cpp \
    audio.cpp \
    ffmpeg.cpp \
        main.cpp \
    medialib.cpp \
    videowidget.cpp \
    worker.cpp

HEADERS += \
    Player.h \
    audio.h \
    ffmpeg.h \
    medialib.h \
    videowidget.h \
    worker.h

FORMS += \
    Player.ui

RESOURCES += \
    ui.qrc

DISTFILES +=

INCLUDEPATH="D:\x64\include"

LIBS += -LD:\x64\lib -lavutil -lavformat -lavcodec -lavdevice  -lavfilter -lpostproc -lswscale -lswresample
#LIBS += -LD:\x64\lib -lavcodec -lavformat -lavdevice -lavutil  -lavfilter -lpostproc -lswscale -lswresample

