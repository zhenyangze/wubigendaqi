/********************************************************************************
** Form generated from reading UI file 'wfileterform.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WFILETERFORM_H
#define UI_WFILETERFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WFileterForm
{
public:
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;

    void setupUi(QWidget *WFileterForm)
    {
        if (WFileterForm->objectName().isEmpty())
            WFileterForm->setObjectName(QStringLiteral("WFileterForm"));
        WFileterForm->resize(422, 363);
        horizontalLayout = new QHBoxLayout(WFileterForm);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tabWidget = new QTabWidget(WFileterForm);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));

        horizontalLayout->addWidget(tabWidget);


        retranslateUi(WFileterForm);

        QMetaObject::connectSlotsByName(WFileterForm);
    } // setupUi

    void retranslateUi(QWidget *WFileterForm)
    {
        WFileterForm->setWindowTitle(QApplication::translate("WFileterForm", "\350\275\275\346\226\207\350\247\204\345\210\231", 0));
    } // retranslateUi

};

namespace Ui {
    class WFileterForm: public Ui_WFileterForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WFILETERFORM_H
