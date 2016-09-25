/********************************************************************************
** Form generated from reading UI file 'wuserrecord.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WUSERRECORD_H
#define UI_WUSERRECORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_WUserRecord
{
public:
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QCustomPlot *widget;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_5;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_speed;
    QLabel *label_time;
    QLabel *label_day;
    QWidget *widget_grade;

    void setupUi(QWidget *WUserRecord)
    {
        if (WUserRecord->objectName().isEmpty())
            WUserRecord->setObjectName(QStringLiteral("WUserRecord"));
        WUserRecord->resize(465, 335);
        verticalLayout_4 = new QVBoxLayout(WUserRecord);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        groupBox = new QGroupBox(WUserRecord);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget = new QCustomPlot(groupBox);
        widget->setObjectName(QStringLiteral("widget"));

        verticalLayout->addWidget(widget);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(WUserRecord);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMaximumSize(QSize(16777215, 120));
        verticalLayout_7 = new QVBoxLayout(groupBox_2);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_5->addWidget(label);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_5->addWidget(label_3);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_5->addWidget(label_5);


        horizontalLayout->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_speed = new QLabel(groupBox_2);
        label_speed->setObjectName(QStringLiteral("label_speed"));

        verticalLayout_6->addWidget(label_speed);

        label_time = new QLabel(groupBox_2);
        label_time->setObjectName(QStringLiteral("label_time"));

        verticalLayout_6->addWidget(label_time);

        label_day = new QLabel(groupBox_2);
        label_day->setObjectName(QStringLiteral("label_day"));

        verticalLayout_6->addWidget(label_day);


        horizontalLayout->addLayout(verticalLayout_6);

        widget_grade = new QWidget(groupBox_2);
        widget_grade->setObjectName(QStringLiteral("widget_grade"));

        horizontalLayout->addWidget(widget_grade);


        verticalLayout_7->addLayout(horizontalLayout);


        verticalLayout_3->addWidget(groupBox_2);


        verticalLayout_4->addLayout(verticalLayout_3);


        retranslateUi(WUserRecord);

        QMetaObject::connectSlotsByName(WUserRecord);
    } // setupUi

    void retranslateUi(QWidget *WUserRecord)
    {
        WUserRecord->setWindowTitle(QApplication::translate("WUserRecord", "Form", 0));
        groupBox->setTitle(QApplication::translate("WUserRecord", "\346\211\223\345\255\227\351\200\237\345\272\246", 0));
        groupBox_2->setTitle(QApplication::translate("WUserRecord", "\350\241\214\344\270\272\347\273\237\350\256\241", 0));
        label->setText(QApplication::translate("WUserRecord", "\346\234\200\345\277\253\351\200\237\345\272\246\357\274\232", 0));
        label_3->setText(QApplication::translate("WUserRecord", "\347\273\203\344\271\240\346\227\266\351\225\277\357\274\232", 0));
        label_5->setText(QApplication::translate("WUserRecord", "\350\277\236\347\273\255\345\235\232\346\214\201\345\244\251\346\225\260\357\274\232", 0));
        label_speed->setText(QString());
        label_time->setText(QString());
        label_day->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WUserRecord: public Ui_WUserRecord {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WUSERRECORD_H
