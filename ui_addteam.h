/********************************************************************************
** Form generated from reading UI file 'addteam.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDTEAM_H
#define UI_ADDTEAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addteam
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *teamnamelineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *carnamelineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QPushButton *loadimageButton;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QComboBox *categorycomboBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *addteam)
    {
        if (addteam->objectName().isEmpty())
            addteam->setObjectName(QStringLiteral("addteam"));
        addteam->resize(220, 179);
        layoutWidget = new QWidget(addteam);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(11, 21, 205, 144));
        gridLayout_3 = new QGridLayout(layoutWidget);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        teamnamelineEdit = new QLineEdit(layoutWidget);
        teamnamelineEdit->setObjectName(QStringLiteral("teamnamelineEdit"));

        horizontalLayout->addWidget(teamnamelineEdit);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        carnamelineEdit = new QLineEdit(layoutWidget);
        carnamelineEdit->setObjectName(QStringLiteral("carnamelineEdit"));

        horizontalLayout_2->addWidget(carnamelineEdit);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        loadimageButton = new QPushButton(layoutWidget);
        loadimageButton->setObjectName(QStringLiteral("loadimageButton"));

        horizontalLayout_3->addWidget(loadimageButton);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        categorycomboBox = new QComboBox(layoutWidget);
        categorycomboBox->setObjectName(QStringLiteral("categorycomboBox"));

        horizontalLayout_4->addWidget(categorycomboBox);


        gridLayout_2->addLayout(horizontalLayout_4, 1, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(layoutWidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_3->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(addteam);
        QObject::connect(buttonBox, SIGNAL(accepted()), addteam, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), addteam, SLOT(reject()));

        QMetaObject::connectSlotsByName(addteam);
    } // setupUi

    void retranslateUi(QDialog *addteam)
    {
        addteam->setWindowTitle(QApplication::translate("addteam", "Dialog", 0));
        label->setText(QApplication::translate("addteam", "TEAM NAME", 0));
        label_2->setText(QApplication::translate("addteam", "CAR NAME", 0));
        label_3->setText(QApplication::translate("addteam", "IMAGE", 0));
        loadimageButton->setText(QApplication::translate("addteam", "LOAD", 0));
        label_4->setText(QApplication::translate("addteam", "Category", 0));
        categorycomboBox->clear();
        categorycomboBox->insertItems(0, QStringList()
         << QApplication::translate("addteam", "RC-ST", 0)
         << QApplication::translate("addteam", "RC", 0)
         << QApplication::translate("addteam", "AUTONOM", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class addteam: public Ui_addteam {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDTEAM_H
