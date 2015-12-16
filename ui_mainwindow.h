/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_7;
    QTableWidget *RC_STrankingTable;
    QTableWidget *RCrankingTable;
    QTableWidget *AUTONOMrankingTable;
    QLabel *fullrankingLabel;
    QSplitter *splitter_5;
    QSplitter *splitter_4;
    QListWidget *nextteamList;
    QListWidget *laterteamList;
    QSplitter *splitter_3;
    QFrame *frame;
    QGridLayout *gridLayout_3;
    QPushButton *readyButton;
    QPushButton *walkoverButton;
    QPushButton *nextButton;
    QPushButton *startButton;
    QPushButton *stopButton;
    QSplitter *splitter_2;
    QSplitter *splitter;
    QFrame *frame_2;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout;
    QPushButton *addroundButton;
    QVBoxLayout *verticalLayout;
    QCheckBox *rcstCheck;
    QCheckBox *rcCheck;
    QCheckBox *autoCheck;
    QFrame *frame_4;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *number_of_lapsEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *number_of_sensorsEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *messageEdit;
    QPushButton *resultsWindowButton;
    QPushButton *ConnectWithMasterButton;
    QFrame *frame_3;
    QGridLayout *gridLayout_2;
    QPushButton *addteamButton;
    QPushButton *load_session_Button;
    QPushButton *deleteTeamButton;
    QPushButton *loadteamsButton;
    QPushButton *save_session_Button;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(715, 583);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/logo.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setIconSize(QSize(64, 64));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_5 = new QGridLayout(centralWidget);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setSpacing(6);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_7->setSizeConstraint(QLayout::SetMaximumSize);
        RC_STrankingTable = new QTableWidget(centralWidget);
        if (RC_STrankingTable->columnCount() < 2)
            RC_STrankingTable->setColumnCount(2);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        RC_STrankingTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font);
        RC_STrankingTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        RC_STrankingTable->setObjectName(QStringLiteral("RC_STrankingTable"));
        RC_STrankingTable->setFrameShape(QFrame::StyledPanel);
        RC_STrankingTable->setFrameShadow(QFrame::Plain);
        RC_STrankingTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        RC_STrankingTable->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);

        gridLayout_7->addWidget(RC_STrankingTable, 2, 0, 1, 1);

        RCrankingTable = new QTableWidget(centralWidget);
        if (RCrankingTable->columnCount() < 2)
            RCrankingTable->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font);
        RCrankingTable->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font);
        RCrankingTable->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        RCrankingTable->setObjectName(QStringLiteral("RCrankingTable"));
        RCrankingTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        RCrankingTable->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        RCrankingTable->setSortingEnabled(false);

        gridLayout_7->addWidget(RCrankingTable, 2, 1, 1, 1);

        AUTONOMrankingTable = new QTableWidget(centralWidget);
        if (AUTONOMrankingTable->columnCount() < 2)
            AUTONOMrankingTable->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font);
        AUTONOMrankingTable->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font);
        AUTONOMrankingTable->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        AUTONOMrankingTable->setObjectName(QStringLiteral("AUTONOMrankingTable"));
        AUTONOMrankingTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        AUTONOMrankingTable->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        AUTONOMrankingTable->setSortingEnabled(false);

        gridLayout_7->addWidget(AUTONOMrankingTable, 2, 2, 1, 1);

        fullrankingLabel = new QLabel(centralWidget);
        fullrankingLabel->setObjectName(QStringLiteral("fullrankingLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(fullrankingLabel->sizePolicy().hasHeightForWidth());
        fullrankingLabel->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setFamily(QStringLiteral("MS PGothic"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        fullrankingLabel->setFont(font1);
        fullrankingLabel->setFocusPolicy(Qt::ClickFocus);
#ifndef QT_NO_WHATSTHIS
        fullrankingLabel->setWhatsThis(0u);
#endif // QT_NO_WHATSTHIS
        fullrankingLabel->setLayoutDirection(Qt::LeftToRight);

        gridLayout_7->addWidget(fullrankingLabel, 0, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout_7, 1, 0, 1, 1);

        splitter_5 = new QSplitter(centralWidget);
        splitter_5->setObjectName(QStringLiteral("splitter_5"));
        splitter_5->setOrientation(Qt::Horizontal);
        splitter_4 = new QSplitter(splitter_5);
        splitter_4->setObjectName(QStringLiteral("splitter_4"));
        splitter_4->setOrientation(Qt::Vertical);
        nextteamList = new QListWidget(splitter_4);
        nextteamList->setObjectName(QStringLiteral("nextteamList"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(nextteamList->sizePolicy().hasHeightForWidth());
        nextteamList->setSizePolicy(sizePolicy2);
        nextteamList->setMinimumSize(QSize(0, 57));
        nextteamList->setMaximumSize(QSize(16777215, 57));
        splitter_4->addWidget(nextteamList);
        laterteamList = new QListWidget(splitter_4);
        laterteamList->setObjectName(QStringLiteral("laterteamList"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(laterteamList->sizePolicy().hasHeightForWidth());
        laterteamList->setSizePolicy(sizePolicy3);
        laterteamList->setMaximumSize(QSize(16777215, 16777215));
        laterteamList->setFrameShape(QFrame::StyledPanel);
        laterteamList->setFrameShadow(QFrame::Sunken);
        laterteamList->setDragEnabled(true);
        laterteamList->setDragDropOverwriteMode(false);
        laterteamList->setDragDropMode(QAbstractItemView::InternalMove);
        laterteamList->setDefaultDropAction(Qt::MoveAction);
        laterteamList->setAlternatingRowColors(true);
        laterteamList->setMovement(QListView::Snap);
        splitter_4->addWidget(laterteamList);
        splitter_5->addWidget(splitter_4);
        splitter_3 = new QSplitter(splitter_5);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setOrientation(Qt::Vertical);
        frame = new QFrame(splitter_3);
        frame->setObjectName(QStringLiteral("frame"));
        QSizePolicy sizePolicy4(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy4);
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        readyButton = new QPushButton(frame);
        readyButton->setObjectName(QStringLiteral("readyButton"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(readyButton->sizePolicy().hasHeightForWidth());
        readyButton->setSizePolicy(sizePolicy5);
        readyButton->setMaximumSize(QSize(16777215, 16777215));
        readyButton->setAutoRepeatDelay(300);
        readyButton->setAutoRepeatInterval(100);

        gridLayout_3->addWidget(readyButton, 0, 1, 1, 1);

        walkoverButton = new QPushButton(frame);
        walkoverButton->setObjectName(QStringLiteral("walkoverButton"));
        QSizePolicy sizePolicy6(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(walkoverButton->sizePolicy().hasHeightForWidth());
        walkoverButton->setSizePolicy(sizePolicy6);
        walkoverButton->setMinimumSize(QSize(70, 0));
        walkoverButton->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_3->addWidget(walkoverButton, 0, 4, 1, 1);

        nextButton = new QPushButton(frame);
        nextButton->setObjectName(QStringLiteral("nextButton"));
        sizePolicy6.setHeightForWidth(nextButton->sizePolicy().hasHeightForWidth());
        nextButton->setSizePolicy(sizePolicy6);
        nextButton->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_3->addWidget(nextButton, 0, 0, 1, 1);

        startButton = new QPushButton(frame);
        startButton->setObjectName(QStringLiteral("startButton"));
        sizePolicy6.setHeightForWidth(startButton->sizePolicy().hasHeightForWidth());
        startButton->setSizePolicy(sizePolicy6);
        startButton->setMaximumSize(QSize(16777215, 16777215));
        startButton->setAutoRepeatDelay(300);
        startButton->setAutoRepeatInterval(100);

        gridLayout_3->addWidget(startButton, 0, 2, 1, 1);

        stopButton = new QPushButton(frame);
        stopButton->setObjectName(QStringLiteral("stopButton"));
        sizePolicy6.setHeightForWidth(stopButton->sizePolicy().hasHeightForWidth());
        stopButton->setSizePolicy(sizePolicy6);
        stopButton->setMaximumSize(QSize(16777215, 16777215));
        stopButton->setAutoRepeatDelay(300);
        stopButton->setAutoRepeatInterval(100);

        gridLayout_3->addWidget(stopButton, 0, 3, 1, 1);

        splitter_3->addWidget(frame);
        splitter_2 = new QSplitter(splitter_3);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Vertical);
        frame_2 = new QFrame(splitter);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        QSizePolicy sizePolicy7(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy7);
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_6 = new QGridLayout(frame_2);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        addroundButton = new QPushButton(frame_2);
        addroundButton->setObjectName(QStringLiteral("addroundButton"));
        sizePolicy1.setHeightForWidth(addroundButton->sizePolicy().hasHeightForWidth());
        addroundButton->setSizePolicy(sizePolicy1);
        addroundButton->setMinimumSize(QSize(30, 30));

        gridLayout->addWidget(addroundButton, 0, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        rcstCheck = new QCheckBox(frame_2);
        rcstCheck->setObjectName(QStringLiteral("rcstCheck"));
        sizePolicy6.setHeightForWidth(rcstCheck->sizePolicy().hasHeightForWidth());
        rcstCheck->setSizePolicy(sizePolicy6);

        verticalLayout->addWidget(rcstCheck);

        rcCheck = new QCheckBox(frame_2);
        rcCheck->setObjectName(QStringLiteral("rcCheck"));
        QSizePolicy sizePolicy8(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(rcCheck->sizePolicy().hasHeightForWidth());
        rcCheck->setSizePolicy(sizePolicy8);

        verticalLayout->addWidget(rcCheck);

        autoCheck = new QCheckBox(frame_2);
        autoCheck->setObjectName(QStringLiteral("autoCheck"));
        sizePolicy6.setHeightForWidth(autoCheck->sizePolicy().hasHeightForWidth());
        autoCheck->setSizePolicy(sizePolicy6);

        verticalLayout->addWidget(autoCheck);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        gridLayout_6->addLayout(gridLayout, 0, 0, 1, 1);

        splitter->addWidget(frame_2);
        frame_4 = new QFrame(splitter);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        sizePolicy4.setHeightForWidth(frame_4->sizePolicy().hasHeightForWidth());
        frame_4->setSizePolicy(sizePolicy4);
        frame_4->setFrameShape(QFrame::Box);
        frame_4->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(frame_4);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(frame_4);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy8.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy8);
        label_2->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout->addWidget(label_2);

        number_of_lapsEdit = new QLineEdit(frame_4);
        number_of_lapsEdit->setObjectName(QStringLiteral("number_of_lapsEdit"));
        sizePolicy4.setHeightForWidth(number_of_lapsEdit->sizePolicy().hasHeightForWidth());
        number_of_lapsEdit->setSizePolicy(sizePolicy4);
        number_of_lapsEdit->setMinimumSize(QSize(0, 0));
        number_of_lapsEdit->setMaximumSize(QSize(16777215, 20));

        horizontalLayout->addWidget(number_of_lapsEdit);


        gridLayout_4->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(frame_4);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy8.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy8);
        label_3->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_2->addWidget(label_3);

        number_of_sensorsEdit = new QLineEdit(frame_4);
        number_of_sensorsEdit->setObjectName(QStringLiteral("number_of_sensorsEdit"));
        QSizePolicy sizePolicy9(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
        sizePolicy9.setHorizontalStretch(0);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(number_of_sensorsEdit->sizePolicy().hasHeightForWidth());
        number_of_sensorsEdit->setSizePolicy(sizePolicy9);
        number_of_sensorsEdit->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_2->addWidget(number_of_sensorsEdit);


        gridLayout_4->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(frame_4);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);

        messageEdit = new QLineEdit(frame_4);
        messageEdit->setObjectName(QStringLiteral("messageEdit"));

        horizontalLayout_3->addWidget(messageEdit);


        gridLayout_4->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        resultsWindowButton = new QPushButton(frame_4);
        resultsWindowButton->setObjectName(QStringLiteral("resultsWindowButton"));
        QSizePolicy sizePolicy10(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
        sizePolicy10.setHorizontalStretch(0);
        sizePolicy10.setVerticalStretch(0);
        sizePolicy10.setHeightForWidth(resultsWindowButton->sizePolicy().hasHeightForWidth());
        resultsWindowButton->setSizePolicy(sizePolicy10);

        gridLayout_4->addWidget(resultsWindowButton, 3, 0, 1, 1);

        ConnectWithMasterButton = new QPushButton(frame_4);
        ConnectWithMasterButton->setObjectName(QStringLiteral("ConnectWithMasterButton"));
        sizePolicy10.setHeightForWidth(ConnectWithMasterButton->sizePolicy().hasHeightForWidth());
        ConnectWithMasterButton->setSizePolicy(sizePolicy10);
        ConnectWithMasterButton->setAutoRepeatDelay(2000);
        ConnectWithMasterButton->setAutoRepeatInterval(1000);

        gridLayout_4->addWidget(ConnectWithMasterButton, 4, 0, 1, 1);

        splitter->addWidget(frame_4);
        splitter_2->addWidget(splitter);
        frame_3 = new QFrame(splitter_2);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setFrameShape(QFrame::Box);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame_3);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        addteamButton = new QPushButton(frame_3);
        addteamButton->setObjectName(QStringLiteral("addteamButton"));
        sizePolicy6.setHeightForWidth(addteamButton->sizePolicy().hasHeightForWidth());
        addteamButton->setSizePolicy(sizePolicy6);
        addteamButton->setMinimumSize(QSize(0, 0));

        gridLayout_2->addWidget(addteamButton, 0, 0, 1, 1);

        load_session_Button = new QPushButton(frame_3);
        load_session_Button->setObjectName(QStringLiteral("load_session_Button"));
        sizePolicy6.setHeightForWidth(load_session_Button->sizePolicy().hasHeightForWidth());
        load_session_Button->setSizePolicy(sizePolicy6);

        gridLayout_2->addWidget(load_session_Button, 4, 0, 1, 1);

        deleteTeamButton = new QPushButton(frame_3);
        deleteTeamButton->setObjectName(QStringLiteral("deleteTeamButton"));
        sizePolicy6.setHeightForWidth(deleteTeamButton->sizePolicy().hasHeightForWidth());
        deleteTeamButton->setSizePolicy(sizePolicy6);

        gridLayout_2->addWidget(deleteTeamButton, 1, 0, 1, 1);

        loadteamsButton = new QPushButton(frame_3);
        loadteamsButton->setObjectName(QStringLiteral("loadteamsButton"));
        sizePolicy6.setHeightForWidth(loadteamsButton->sizePolicy().hasHeightForWidth());
        loadteamsButton->setSizePolicy(sizePolicy6);

        gridLayout_2->addWidget(loadteamsButton, 3, 0, 1, 1);

        save_session_Button = new QPushButton(frame_3);
        save_session_Button->setObjectName(QStringLiteral("save_session_Button"));
        sizePolicy6.setHeightForWidth(save_session_Button->sizePolicy().hasHeightForWidth());
        save_session_Button->setSizePolicy(sizePolicy6);

        gridLayout_2->addWidget(save_session_Button, 2, 0, 1, 1);

        splitter_2->addWidget(frame_3);
        splitter_3->addWidget(splitter_2);
        splitter_5->addWidget(splitter_3);

        gridLayout_5->addWidget(splitter_5, 0, 0, 1, 1);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_5->addWidget(pushButton, 2, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        splitter_5->raise();
        pushButton->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 715, 21));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        QTableWidgetItem *___qtablewidgetitem = RC_STrankingTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "TEAM NAME", 0));
        QTableWidgetItem *___qtablewidgetitem1 = RC_STrankingTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "TIME", 0));
        QTableWidgetItem *___qtablewidgetitem2 = RCrankingTable->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "TEAM NAME", 0));
        QTableWidgetItem *___qtablewidgetitem3 = RCrankingTable->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "TIME", 0));
        QTableWidgetItem *___qtablewidgetitem4 = AUTONOMrankingTable->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "TEAM NAME", 0));
        QTableWidgetItem *___qtablewidgetitem5 = AUTONOMrankingTable->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "TIME", 0));
        fullrankingLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">FULL RANKING</p></body></html>", 0));
        readyButton->setText(QApplication::translate("MainWindow", "READY", 0));
        walkoverButton->setText(QApplication::translate("MainWindow", "WALKOVER", 0));
        nextButton->setText(QApplication::translate("MainWindow", "NEXT", 0));
        startButton->setText(QApplication::translate("MainWindow", "START", 0));
        stopButton->setText(QApplication::translate("MainWindow", "STOP", 0));
        addroundButton->setText(QApplication::translate("MainWindow", "ADD ROUND", 0));
        rcstCheck->setText(QApplication::translate("MainWindow", "RC-ST", 0));
        rcCheck->setText(QApplication::translate("MainWindow", "RC", 0));
        autoCheck->setText(QApplication::translate("MainWindow", "AUTONOM", 0));
        label_2->setText(QApplication::translate("MainWindow", "Number of laps", 0));
        label_3->setText(QApplication::translate("MainWindow", "Number of sensors", 0));
        label->setText(QApplication::translate("MainWindow", "Comment for Public", 0));
        resultsWindowButton->setText(QApplication::translate("MainWindow", "RESULTS WINDOW FOR PUBLIC", 0));
        ConnectWithMasterButton->setText(QApplication::translate("MainWindow", "CONNECT WITH MASTER", 0));
        addteamButton->setText(QApplication::translate("MainWindow", "ADD TEAM", 0));
        load_session_Button->setText(QApplication::translate("MainWindow", "LOAD LAST SESSION", 0));
        deleteTeamButton->setText(QApplication::translate("MainWindow", "DELETE TEAM", 0));
        loadteamsButton->setText(QApplication::translate("MainWindow", "LOAD TEAMS", 0));
        save_session_Button->setText(QApplication::translate("MainWindow", "SAVE SESSION", 0));
        pushButton->setText(QApplication::translate("MainWindow", "SAFETY BUTTON", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
