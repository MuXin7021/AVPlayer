/********************************************************************************
** Form generated from reading UI file 'Player.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYER_H
#define UI_PLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AudioPlay
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout_7;
    QLabel *logo;
    QLabel *label_Title;
    QSpacerItem *horizontalSpacer_12;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton_WindowMin;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *pushButton_WindowMax;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_WindowExit;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lab22;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QSlider *Slider_ProgressBar;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_PlayTime;
    QSpacerItem *horizontalSpacer;
    QLabel *label_MusicTime;
    QHBoxLayout *horizontalLayout;
    QLabel *label_Volume_2;
    QSlider *Slider_Volume;
    QLabel *label_Volume;
    QPushButton *PushButton_Previous;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *PushButton_PlayStop;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *PushButton_Next;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *PushButton_PlayMode;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *PushButton_OpenFile;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *PushButton_DeleteMusic;
    QSpacerItem *horizontalSpacer_11;

    void setupUi(QMainWindow *AudioPlay)
    {
        if (AudioPlay->objectName().isEmpty())
            AudioPlay->setObjectName(QString::fromUtf8("AudioPlay"));
        AudioPlay->setEnabled(true);
        AudioPlay->resize(1116, 790);
        AudioPlay->setLayoutDirection(Qt::LeftToRight);
        AudioPlay->setStyleSheet(QString::fromUtf8(""));
        AudioPlay->setDockNestingEnabled(false);
        AudioPlay->setDockOptions(QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        centralWidget = new QWidget(AudioPlay);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        logo = new QLabel(centralWidget);
        logo->setObjectName(QString::fromUtf8("logo"));
        logo->setMinimumSize(QSize(40, 30));
        logo->setMaximumSize(QSize(40, 40));
        logo->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_7->addWidget(logo);

        label_Title = new QLabel(centralWidget);
        label_Title->setObjectName(QString::fromUtf8("label_Title"));
        label_Title->setMinimumSize(QSize(100, 30));
        label_Title->setMaximumSize(QSize(99999, 30));

        horizontalLayout_7->addWidget(label_Title);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_12);

        horizontalLayout_7->setStretch(0, 1);
        horizontalLayout_7->setStretch(1, 3);
        horizontalLayout_7->setStretch(2, 30);

        horizontalLayout_8->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        pushButton_WindowMin = new QPushButton(centralWidget);
        pushButton_WindowMin->setObjectName(QString::fromUtf8("pushButton_WindowMin"));
        pushButton_WindowMin->setMinimumSize(QSize(30, 30));
        pushButton_WindowMin->setMaximumSize(QSize(30, 30));

        horizontalLayout_6->addWidget(pushButton_WindowMin);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_8);

        pushButton_WindowMax = new QPushButton(centralWidget);
        pushButton_WindowMax->setObjectName(QString::fromUtf8("pushButton_WindowMax"));
        pushButton_WindowMax->setMinimumSize(QSize(30, 30));
        pushButton_WindowMax->setMaximumSize(QSize(30, 30));

        horizontalLayout_6->addWidget(pushButton_WindowMax);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);

        pushButton_WindowExit = new QPushButton(centralWidget);
        pushButton_WindowExit->setObjectName(QString::fromUtf8("pushButton_WindowExit"));
        pushButton_WindowExit->setMinimumSize(QSize(30, 30));
        pushButton_WindowExit->setMaximumSize(QSize(30, 30));

        horizontalLayout_6->addWidget(pushButton_WindowExit);


        horizontalLayout_8->addLayout(horizontalLayout_6);

        horizontalLayout_8->setStretch(0, 7);
        horizontalLayout_8->setStretch(1, 1);

        verticalLayout_6->addLayout(horizontalLayout_8);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));

        gridLayout->addLayout(verticalLayout_7, 0, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        lab22 = new QLabel(centralWidget);
        lab22->setObjectName(QString::fromUtf8("lab22"));

        horizontalLayout_4->addWidget(lab22);


        verticalLayout_4->addLayout(horizontalLayout_4);


        verticalLayout_5->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        Slider_ProgressBar = new QSlider(centralWidget);
        Slider_ProgressBar->setObjectName(QString::fromUtf8("Slider_ProgressBar"));
        Slider_ProgressBar->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {  \n"
"border: 1px solid #4A708B;  \n"
"background: #C0C0C0;  \n"
"height: 5px;  \n"
"border-radius: 1px;  \n"
"padding-left:-1px;  \n"
"padding-right:-1px;  \n"
"}    \n"
"\n"
"QSlider::sub-page:horizontal {  \n"
"background: qlineargradient(x1:0, y1:0, x2:0, y2:1,   \n"
"    stop:0 #B1B1B1, stop:1 #c4c4c4);  \n"
"background: qlineargradient(x1: 0, y1: 0.2, x2: 1, y2: 1,  \n"
"    stop: 0 #5DCCFF, stop: 1 #1874CD);  \n"
"border: 1px solid #4A708B;  \n"
"height: 10px;  \n"
"border-radius: 2px;  \n"
"}  \n"
"  \n"
"QSlider::add-page:horizontal {  \n"
"background: #575757;  \n"
"border: 0px solid #777;  \n"
"height: 10px;  \n"
"border-radius: 2px;  \n"
"}  \n"
"  \n"
"QSlider::handle:horizontal   \n"
"{  \n"
"    background: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5,   \n"
"    stop:0.6 #45ADED, stop:0.778409 rgba(255, 255, 255, 255));  \n"
"  \n"
"    width: 11px;  \n"
"    margin-top: -3px;  \n"
"    margin-bottom: -3px;  \n"
"    border-radius: 5px;  \n"
""
                        "}  \n"
"  \n"
"QSlider::handle:horizontal:hover {  \n"
"    background: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0.6 #2A8BDA,   \n"
"    stop:0.778409 rgba(255, 255, 255, 255));  \n"
"  \n"
"    width: 11px;  \n"
"    margin-top: -3px;  \n"
"    margin-bottom: -3px;  \n"
"    border-radius: 5px;  \n"
"}  \n"
"  \n"
"QSlider::sub-page:horizontal:disabled {  \n"
"background: #00009C;  \n"
"border-color: #999;  \n"
"}  \n"
"  \n"
"QSlider::add-page:horizontal:disabled {  \n"
"background: #eee;  \n"
"border-color: #999;  \n"
"}  \n"
"  \n"
"QSlider::handle:horizontal:disabled {  \n"
"background: #eee;  \n"
"border: 1px solid #aaa;  \n"
"border-radius: 4px;  \n"
"} \n"
""));
        Slider_ProgressBar->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(Slider_ProgressBar);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_PlayTime = new QLabel(centralWidget);
        label_PlayTime->setObjectName(QString::fromUtf8("label_PlayTime"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_PlayTime->sizePolicy().hasHeightForWidth());
        label_PlayTime->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(label_PlayTime);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label_MusicTime = new QLabel(centralWidget);
        label_MusicTime->setObjectName(QString::fromUtf8("label_MusicTime"));
        sizePolicy.setHeightForWidth(label_MusicTime->sizePolicy().hasHeightForWidth());
        label_MusicTime->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(label_MusicTime);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_Volume_2 = new QLabel(centralWidget);
        label_Volume_2->setObjectName(QString::fromUtf8("label_Volume_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(label_Volume_2->sizePolicy().hasHeightForWidth());
        label_Volume_2->setSizePolicy(sizePolicy1);
        label_Volume_2->setMinimumSize(QSize(48, 48));
        label_Volume_2->setMaximumSize(QSize(48, 48));
        label_Volume_2->setStyleSheet(QString::fromUtf8(""));
        label_Volume_2->setFrameShape(QFrame::StyledPanel);
        label_Volume_2->setTextFormat(Qt::RichText);
        label_Volume_2->setAlignment(Qt::AlignCenter);
        label_Volume_2->setTextInteractionFlags(Qt::LinksAccessibleByMouse);

        horizontalLayout->addWidget(label_Volume_2);

        Slider_Volume = new QSlider(centralWidget);
        Slider_Volume->setObjectName(QString::fromUtf8("Slider_Volume"));
        Slider_Volume->setMinimumSize(QSize(130, 0));
        Slider_Volume->setMaximumSize(QSize(130, 16777215));
        Slider_Volume->setStyleSheet(QString::fromUtf8(""));
        Slider_Volume->setMaximum(100);
        Slider_Volume->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(Slider_Volume);

        label_Volume = new QLabel(centralWidget);
        label_Volume->setObjectName(QString::fromUtf8("label_Volume"));
        sizePolicy1.setHeightForWidth(label_Volume->sizePolicy().hasHeightForWidth());
        label_Volume->setSizePolicy(sizePolicy1);
        label_Volume->setMinimumSize(QSize(40, 48));
        label_Volume->setMaximumSize(QSize(40, 48));
        label_Volume->setStyleSheet(QString::fromUtf8(""));
        label_Volume->setFrameShape(QFrame::StyledPanel);
        label_Volume->setTextFormat(Qt::RichText);
        label_Volume->setAlignment(Qt::AlignCenter);
        label_Volume->setTextInteractionFlags(Qt::LinksAccessibleByMouse);

        horizontalLayout->addWidget(label_Volume);

        PushButton_Previous = new QPushButton(centralWidget);
        PushButton_Previous->setObjectName(QString::fromUtf8("PushButton_Previous"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(PushButton_Previous->sizePolicy().hasHeightForWidth());
        PushButton_Previous->setSizePolicy(sizePolicy2);
        PushButton_Previous->setMaximumSize(QSize(48, 48));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(12);
        PushButton_Previous->setFont(font);
        PushButton_Previous->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(PushButton_Previous);

        horizontalSpacer_4 = new QSpacerItem(24, 35, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        PushButton_PlayStop = new QPushButton(centralWidget);
        PushButton_PlayStop->setObjectName(QString::fromUtf8("PushButton_PlayStop"));
        sizePolicy2.setHeightForWidth(PushButton_PlayStop->sizePolicy().hasHeightForWidth());
        PushButton_PlayStop->setSizePolicy(sizePolicy2);
        PushButton_PlayStop->setMaximumSize(QSize(48, 48));
        PushButton_PlayStop->setFont(font);
        PushButton_PlayStop->setFocusPolicy(Qt::NoFocus);
        PushButton_PlayStop->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(PushButton_PlayStop);

        horizontalSpacer_5 = new QSpacerItem(23, 35, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        PushButton_Next = new QPushButton(centralWidget);
        PushButton_Next->setObjectName(QString::fromUtf8("PushButton_Next"));
        sizePolicy2.setHeightForWidth(PushButton_Next->sizePolicy().hasHeightForWidth());
        PushButton_Next->setSizePolicy(sizePolicy2);
        PushButton_Next->setMaximumSize(QSize(48, 48));
        PushButton_Next->setFont(font);
        PushButton_Next->setFocusPolicy(Qt::NoFocus);
        PushButton_Next->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(PushButton_Next);

        horizontalSpacer_6 = new QSpacerItem(24, 35, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        PushButton_PlayMode = new QPushButton(centralWidget);
        PushButton_PlayMode->setObjectName(QString::fromUtf8("PushButton_PlayMode"));
        sizePolicy2.setHeightForWidth(PushButton_PlayMode->sizePolicy().hasHeightForWidth());
        PushButton_PlayMode->setSizePolicy(sizePolicy2);
        PushButton_PlayMode->setMaximumSize(QSize(48, 48));
        PushButton_PlayMode->setFont(font);
        PushButton_PlayMode->setFocusPolicy(Qt::NoFocus);
        PushButton_PlayMode->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(PushButton_PlayMode);

        horizontalSpacer_3 = new QSpacerItem(40, 35, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout_3->addLayout(horizontalLayout);


        verticalLayout_5->addLayout(verticalLayout_3);

        verticalLayout_5->setStretch(0, 7);
        verticalLayout_5->setStretch(1, 1);

        horizontalLayout_5->addLayout(verticalLayout_5);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableWidget = new QTableWidget(centralWidget);
        if (tableWidget->columnCount() < 1)
            tableWidget->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setEnabled(true);
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy3);
        tableWidget->setMinimumSize(QSize(0, 610));
        tableWidget->setMaximumSize(QSize(16777215, 16777215));
        tableWidget->setContextMenuPolicy(Qt::DefaultContextMenu);
        tableWidget->setAcceptDrops(true);
        tableWidget->setAutoFillBackground(true);
        tableWidget->setStyleSheet(QString::fromUtf8("QHeaderView::section {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"                                      stop:0 #616161, stop: 0.5 #505050,\n"
"                                      stop: 0.6 #434343, stop:1 #656565);\n"
"    color: white;\n"
"    padding-left: 4px;\n"
"    border: 1px solid #6c6c6c;\n"
"}\n"
"\n"
"QHeaderView::section:checked\n"
"{\n"
"    background-color: red;\n"
"}\n"
"\n"
"/* style the sort indicator */\n"
"QHeaderView::down-arrow {\n"
"    image: url(down_arrow.png);\n"
"}\n"
"\n"
"QHeaderView::up-arrow {\n"
"    image: url(up_arrow.png);\n"
"}\n"
""));
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setDragEnabled(true);
        tableWidget->setAlternatingRowColors(false);
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setGridStyle(Qt::DashLine);
        tableWidget->setColumnCount(1);
        tableWidget->horizontalHeader()->setMinimumSectionSize(27);
        tableWidget->horizontalHeader()->setDefaultSectionSize(300);

        verticalLayout->addWidget(tableWidget);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_10 = new QSpacerItem(13, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_10);

        PushButton_OpenFile = new QPushButton(centralWidget);
        PushButton_OpenFile->setObjectName(QString::fromUtf8("PushButton_OpenFile"));
        sizePolicy2.setHeightForWidth(PushButton_OpenFile->sizePolicy().hasHeightForWidth());
        PushButton_OpenFile->setSizePolicy(sizePolicy2);
        PushButton_OpenFile->setMinimumSize(QSize(48, 48));
        PushButton_OpenFile->setMaximumSize(QSize(48, 48));
        PushButton_OpenFile->setFont(font);
        PushButton_OpenFile->setFocusPolicy(Qt::NoFocus);
        PushButton_OpenFile->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_3->addWidget(PushButton_OpenFile);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_9);

        PushButton_DeleteMusic = new QPushButton(centralWidget);
        PushButton_DeleteMusic->setObjectName(QString::fromUtf8("PushButton_DeleteMusic"));
        sizePolicy2.setHeightForWidth(PushButton_DeleteMusic->sizePolicy().hasHeightForWidth());
        PushButton_DeleteMusic->setSizePolicy(sizePolicy2);
        PushButton_DeleteMusic->setMinimumSize(QSize(0, 35));
        PushButton_DeleteMusic->setMaximumSize(QSize(48, 48));
        PushButton_DeleteMusic->setFont(font);
        PushButton_DeleteMusic->setFocusPolicy(Qt::NoFocus);
        PushButton_DeleteMusic->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_3->addWidget(PushButton_DeleteMusic);

        horizontalSpacer_11 = new QSpacerItem(13, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_11);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalLayout->setStretch(0, 7);

        horizontalLayout_5->addLayout(verticalLayout);

        horizontalLayout_5->setStretch(0, 3);
        horizontalLayout_5->setStretch(1, 1);

        gridLayout->addLayout(horizontalLayout_5, 0, 1, 1, 1);


        verticalLayout_6->addLayout(gridLayout);


        gridLayout_2->addLayout(verticalLayout_6, 0, 0, 2, 2);

        AudioPlay->setCentralWidget(centralWidget);

        retranslateUi(AudioPlay);

        QMetaObject::connectSlotsByName(AudioPlay);
    } // setupUi

    void retranslateUi(QMainWindow *AudioPlay)
    {
        AudioPlay->setWindowTitle(QCoreApplication::translate("AudioPlay", "AudioPlay", nullptr));
        logo->setText(QString());
        label_Title->setText(QString());
        pushButton_WindowMin->setText(QString());
        pushButton_WindowMax->setText(QString());
        pushButton_WindowExit->setText(QString());
        lab22->setText(QString());
        label_PlayTime->setText(QCoreApplication::translate("AudioPlay", "00:00", nullptr));
        label_MusicTime->setText(QCoreApplication::translate("AudioPlay", "00:00", nullptr));
        label_Volume_2->setText(QString());
        label_Volume->setText(QString());
        PushButton_Previous->setText(QString());
        PushButton_PlayStop->setText(QString());
        PushButton_Next->setText(QString());
        PushButton_PlayMode->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("AudioPlay", "\346\222\255\346\224\276\345\210\227\350\241\250", nullptr));
        PushButton_OpenFile->setText(QString());
        PushButton_DeleteMusic->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AudioPlay: public Ui_AudioPlay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYER_H
