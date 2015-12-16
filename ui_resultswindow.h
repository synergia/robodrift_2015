/********************************************************************************
** Form generated from reading UI file 'resultswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESULTSWINDOW_H
#define UI_RESULTSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_resultswindow
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QLabel *comment_Label;
    QLabel *next_teams_Label;
    QFrame *frame_2;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QTableWidget *tableWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QTableWidget *tableWidget_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QTableWidget *tableWidget_3;

    void setupUi(QDialog *resultswindow)
    {
        if (resultswindow->objectName().isEmpty())
            resultswindow->setObjectName(QStringLiteral("resultswindow"));
        resultswindow->resize(850, 554);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(resultswindow->sizePolicy().hasHeightForWidth());
        resultswindow->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(resultswindow);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(50);
        gridLayout->setVerticalSpacing(0);
        gridLayout->setContentsMargins(0, 50, 0, 50);
        frame = new QFrame(resultswindow);
        frame->setObjectName(QStringLiteral("frame"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        comment_Label = new QLabel(frame);
        comment_Label->setObjectName(QStringLiteral("comment_Label"));
        sizePolicy1.setHeightForWidth(comment_Label->sizePolicy().hasHeightForWidth());
        comment_Label->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(48);
        font.setBold(true);
        font.setWeight(75);
        comment_Label->setFont(font);

        verticalLayout->addWidget(comment_Label);

        next_teams_Label = new QLabel(frame);
        next_teams_Label->setObjectName(QStringLiteral("next_teams_Label"));
        QFont font1;
        font1.setPointSize(36);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        next_teams_Label->setFont(font1);

        verticalLayout->addWidget(next_teams_Label);

        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy2);
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(frame_2);
        label->setObjectName(QStringLiteral("label"));
        QFont font2;
        font2.setPointSize(24);
        font2.setBold(true);
        font2.setWeight(75);
        label->setFont(font2);

        verticalLayout_2->addWidget(label);

        tableWidget = new QTableWidget(frame_2);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QFont font3;
        font3.setPointSize(20);
        font3.setBold(true);
        font3.setItalic(true);
        font3.setWeight(75);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font3);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font3);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy3);
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
        tableWidget->horizontalHeader()->setMinimumSectionSize(50);
        tableWidget->verticalHeader()->setDefaultSectionSize(80);
        tableWidget->verticalHeader()->setMinimumSectionSize(30);

        verticalLayout_2->addWidget(tableWidget);


        gridLayout_2->addLayout(verticalLayout_2, 0, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font2);

        verticalLayout_3->addWidget(label_2);

        tableWidget_2 = new QTableWidget(frame_2);
        if (tableWidget_2->columnCount() < 2)
            tableWidget_2->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font3);
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font3);
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        tableWidget_2->setObjectName(QStringLiteral("tableWidget_2"));
        QFont font4;
        font4.setPointSize(16);
        tableWidget_2->setFont(font4);
        tableWidget_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_2->horizontalHeader()->setMinimumSectionSize(50);
        tableWidget_2->verticalHeader()->setMinimumSectionSize(30);

        verticalLayout_3->addWidget(tableWidget_2);


        gridLayout_2->addLayout(verticalLayout_3, 0, 1, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_3 = new QLabel(frame_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font2);

        verticalLayout_4->addWidget(label_3);

        tableWidget_3 = new QTableWidget(frame_2);
        if (tableWidget_3->columnCount() < 2)
            tableWidget_3->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font3);
        tableWidget_3->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font3);
        tableWidget_3->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        tableWidget_3->setObjectName(QStringLiteral("tableWidget_3"));
        tableWidget_3->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_3->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_3->horizontalHeader()->setMinimumSectionSize(50);
        tableWidget_3->verticalHeader()->setMinimumSectionSize(30);

        verticalLayout_4->addWidget(tableWidget_3);


        gridLayout_2->addLayout(verticalLayout_4, 0, 2, 1, 1);


        verticalLayout->addWidget(frame_2);


        gridLayout->addWidget(frame, 0, 0, 1, 1);


        retranslateUi(resultswindow);

        QMetaObject::connectSlotsByName(resultswindow);
    } // setupUi

    void retranslateUi(QDialog *resultswindow)
    {
        resultswindow->setWindowTitle(QApplication::translate("resultswindow", "Dialog", 0));
        comment_Label->setText(QApplication::translate("resultswindow", "TextLabel", 0));
        next_teams_Label->setText(QString());
        label->setText(QApplication::translate("resultswindow", "RC-STANDARD", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("resultswindow", "TEAM", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("resultswindow", "TIME", 0));
        label_2->setText(QApplication::translate("resultswindow", "RC-ROBODRIFT", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("resultswindow", "TEAM", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("resultswindow", "TIME", 0));
        label_3->setText(QApplication::translate("resultswindow", "AUTONOM-ROBODRIFT", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_3->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("resultswindow", "TEAM", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_3->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QApplication::translate("resultswindow", "TIME", 0));
    } // retranslateUi

};

namespace Ui {
    class resultswindow: public Ui_resultswindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESULTSWINDOW_H
