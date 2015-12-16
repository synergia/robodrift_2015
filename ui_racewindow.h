/********************************************************************************
** Form generated from reading UI file 'racewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RACEWINDOW_H
#define UI_RACEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_racewindow
{
public:
    QFrame *frame_2;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *labelCategory;
    QHBoxLayout *horizontalLayout;
    QLabel *labelTeamName;
    QLabel *labelCarName;
    QGridLayout *gridLayout_3;
    QLabel *labelNextTeam;
    QFrame *frame;
    QLabel *labelTime;
    QLabel *labelInfo;
    QLabel *labelTimeDiffrence;
    QPushButton *sensorButton;

    void setupUi(QDialog *racewindow)
    {
        if (racewindow->objectName().isEmpty())
            racewindow->setObjectName(QStringLiteral("racewindow"));
        racewindow->resize(442, 350);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(racewindow->sizePolicy().hasHeightForWidth());
        racewindow->setSizePolicy(sizePolicy);
        frame_2 = new QFrame(racewindow);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(0, 0, 422, 343));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy1);
        gridLayout_4 = new QGridLayout(frame_2);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        labelCategory = new QLabel(frame_2);
        labelCategory->setObjectName(QStringLiteral("labelCategory"));
        QFont font;
        font.setPointSize(48);
        font.setBold(true);
        font.setWeight(75);
        labelCategory->setFont(font);
        labelCategory->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(labelCategory, 0, 0, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelTeamName = new QLabel(frame_2);
        labelTeamName->setObjectName(QStringLiteral("labelTeamName"));
        labelTeamName->setFont(font);
        labelTeamName->setFrameShape(QFrame::Box);

        horizontalLayout->addWidget(labelTeamName);

        labelCarName = new QLabel(frame_2);
        labelCarName->setObjectName(QStringLiteral("labelCarName"));
        labelCarName->setFont(font);
        labelCarName->setFrameShape(QFrame::Box);

        horizontalLayout->addWidget(labelCarName);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 2);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        labelNextTeam = new QLabel(frame_2);
        labelNextTeam->setObjectName(QStringLiteral("labelNextTeam"));
        QFont font1;
        font1.setPointSize(36);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        labelNextTeam->setFont(font1);
        labelNextTeam->setFrameShape(QFrame::Box);

        gridLayout_3->addWidget(labelNextTeam, 0, 0, 1, 1);


        gridLayout->addLayout(gridLayout_3, 5, 0, 1, 1);

        frame = new QFrame(frame_2);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(frame, 2, 1, 4, 1);

        labelTime = new QLabel(frame_2);
        labelTime->setObjectName(QStringLiteral("labelTime"));
        labelTime->setFont(font);
        labelTime->setFrameShape(QFrame::WinPanel);

        gridLayout->addWidget(labelTime, 2, 0, 1, 1);

        labelInfo = new QLabel(frame_2);
        labelInfo->setObjectName(QStringLiteral("labelInfo"));
        labelInfo->setFont(font);
        labelInfo->setFrameShape(QFrame::WinPanel);

        gridLayout->addWidget(labelInfo, 4, 0, 1, 1);

        labelTimeDiffrence = new QLabel(frame_2);
        labelTimeDiffrence->setObjectName(QStringLiteral("labelTimeDiffrence"));
        labelTimeDiffrence->setFont(font);
        labelTimeDiffrence->setFrameShape(QFrame::WinPanel);

        gridLayout->addWidget(labelTimeDiffrence, 3, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        sensorButton = new QPushButton(frame_2);
        sensorButton->setObjectName(QStringLiteral("sensorButton"));

        gridLayout_2->addWidget(sensorButton, 1, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_2, 0, 0, 1, 1);


        retranslateUi(racewindow);

        QMetaObject::connectSlotsByName(racewindow);
    } // setupUi

    void retranslateUi(QDialog *racewindow)
    {
        racewindow->setWindowTitle(QApplication::translate("racewindow", "Dialog", 0));
        labelCategory->setText(QApplication::translate("racewindow", "TextLabel", 0));
        labelTeamName->setText(QApplication::translate("racewindow", "TextLabel", 0));
        labelCarName->setText(QApplication::translate("racewindow", "TextLabel", 0));
        labelNextTeam->setText(QApplication::translate("racewindow", "TextLabel", 0));
        labelTime->setText(QApplication::translate("racewindow", "TextLabel", 0));
        labelInfo->setText(QApplication::translate("racewindow", "TextLabel", 0));
        labelTimeDiffrence->setText(QApplication::translate("racewindow", "TextLabel", 0));
        sensorButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class racewindow: public Ui_racewindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RACEWINDOW_H
