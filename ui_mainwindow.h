/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_open;
    QAction *action_old;
    QAction *action_exit;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_jishi;
    QLabel *label_speed;
    QLabel *label_huigai;
    QLabel *label_correct;
    QLabel *label_anjian_second;
    QLabel *label_anjian_zi;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_index;
    QLabel *label_title;
    QLabel *label_type;
    QLabel *label_wordnum;
    QPushButton *pushButton_file;
    QTextEdit *textEdit_course;
    QPlainTextEdit *plainTextEdit_input;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_wubi;
    QSpacerItem *horizontalSpacer;
    QLabel *label_time;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(485, 336);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QStringLiteral(":/source/img/icon.icns"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        action_open = new QAction(MainWindow);
        action_open->setObjectName(QStringLiteral("action_open"));
        action_old = new QAction(MainWindow);
        action_old->setObjectName(QStringLiteral("action_old"));
        action_exit = new QAction(MainWindow);
        action_exit->setObjectName(QStringLiteral("action_exit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, -1, 0, -1);
        label_jishi = new QLabel(centralWidget);
        label_jishi->setObjectName(QStringLiteral("label_jishi"));
        label_jishi->setMinimumSize(QSize(60, 0));
        label_jishi->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_jishi);

        label_speed = new QLabel(centralWidget);
        label_speed->setObjectName(QStringLiteral("label_speed"));
        label_speed->setMinimumSize(QSize(60, 0));
        label_speed->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_speed);

        label_huigai = new QLabel(centralWidget);
        label_huigai->setObjectName(QStringLiteral("label_huigai"));
        label_huigai->setMinimumSize(QSize(60, 0));
        label_huigai->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_huigai);

        label_correct = new QLabel(centralWidget);
        label_correct->setObjectName(QStringLiteral("label_correct"));
        label_correct->setMinimumSize(QSize(60, 0));
        label_correct->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_correct);

        label_anjian_second = new QLabel(centralWidget);
        label_anjian_second->setObjectName(QStringLiteral("label_anjian_second"));
        label_anjian_second->setMinimumSize(QSize(60, 0));
        label_anjian_second->setTextFormat(Qt::AutoText);
        label_anjian_second->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_anjian_second);

        label_anjian_zi = new QLabel(centralWidget);
        label_anjian_zi->setObjectName(QStringLiteral("label_anjian_zi"));
        label_anjian_zi->setMinimumSize(QSize(60, 0));
        label_anjian_zi->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_anjian_zi);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_index = new QLabel(centralWidget);
        label_index->setObjectName(QStringLiteral("label_index"));
        label_index->setMinimumSize(QSize(60, 0));
        label_index->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_index);

        label_title = new QLabel(centralWidget);
        label_title->setObjectName(QStringLiteral("label_title"));
        label_title->setMinimumSize(QSize(150, 0));
        label_title->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_title);

        label_type = new QLabel(centralWidget);
        label_type->setObjectName(QStringLiteral("label_type"));
        label_type->setMinimumSize(QSize(60, 0));
        label_type->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_type);

        label_wordnum = new QLabel(centralWidget);
        label_wordnum->setObjectName(QStringLiteral("label_wordnum"));
        label_wordnum->setMinimumSize(QSize(60, 0));
        label_wordnum->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_wordnum);

        pushButton_file = new QPushButton(centralWidget);
        pushButton_file->setObjectName(QStringLiteral("pushButton_file"));
        pushButton_file->setEnabled(true);
        pushButton_file->setMinimumSize(QSize(60, 0));
        pushButton_file->setMaximumSize(QSize(16777215, 18));
        pushButton_file->setAutoFillBackground(false);
        pushButton_file->setFlat(true);

        horizontalLayout_2->addWidget(pushButton_file);


        verticalLayout->addLayout(horizontalLayout_2);

        textEdit_course = new QTextEdit(centralWidget);
        textEdit_course->setObjectName(QStringLiteral("textEdit_course"));
        textEdit_course->setEnabled(true);
        textEdit_course->setMinimumSize(QSize(0, 0));
        textEdit_course->setMaximumSize(QSize(16777215, 140));
        QFont font;
        font.setPointSize(16);
        textEdit_course->setFont(font);
        textEdit_course->setAcceptDrops(true);
        textEdit_course->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit_course->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit_course->setReadOnly(true);

        verticalLayout->addWidget(textEdit_course);

        plainTextEdit_input = new QPlainTextEdit(centralWidget);
        plainTextEdit_input->setObjectName(QStringLiteral("plainTextEdit_input"));
        plainTextEdit_input->setMinimumSize(QSize(0, 70));
        plainTextEdit_input->setMaximumSize(QSize(16777215, 70));
        plainTextEdit_input->setFont(font);
        plainTextEdit_input->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(plainTextEdit_input);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_wubi = new QLabel(centralWidget);
        label_wubi->setObjectName(QStringLiteral("label_wubi"));
        label_wubi->setMinimumSize(QSize(70, 0));
        label_wubi->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_wubi);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        label_time = new QLabel(centralWidget);
        label_time->setObjectName(QStringLiteral("label_time"));

        horizontalLayout_3->addWidget(label_time);


        verticalLayout->addLayout(horizontalLayout_3);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        action_open->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266", 0));
        action_old->setText(QApplication::translate("MainWindow", "\345\216\206\345\217\262\350\256\260\345\275\225", 0));
        action_exit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", 0));
#ifndef QT_NO_TOOLTIP
        label_jishi->setToolTip(QApplication::translate("MainWindow", "\345\275\223\345\211\215\346\211\223\345\255\227\346\227\266\351\227\264", 0));
#endif // QT_NO_TOOLTIP
        label_jishi->setText(QApplication::translate("MainWindow", "00:00:00", 0));
#ifndef QT_NO_TOOLTIP
        label_speed->setToolTip(QApplication::translate("MainWindow", "\346\211\223\345\255\227\351\200\237\345\272\246(\345\255\227/\345\210\206)", 0));
#endif // QT_NO_TOOLTIP
        label_speed->setText(QApplication::translate("MainWindow", "0.00", 0));
#ifndef QT_NO_TOOLTIP
        label_huigai->setToolTip(QApplication::translate("MainWindow", "\345\233\236\346\224\271\346\225\260", 0));
#endif // QT_NO_TOOLTIP
        label_huigai->setText(QApplication::translate("MainWindow", "0", 0));
#ifndef QT_NO_TOOLTIP
        label_correct->setToolTip(QApplication::translate("MainWindow", "\346\255\243\347\241\256\347\216\207", 0));
#endif // QT_NO_TOOLTIP
        label_correct->setText(QApplication::translate("MainWindow", "0.00%", 0));
#ifndef QT_NO_TOOLTIP
        label_anjian_second->setToolTip(QApplication::translate("MainWindow", "\346\257\217\347\247\222\346\214\211\351\224\256\346\225\260", 0));
#endif // QT_NO_TOOLTIP
        label_anjian_second->setText(QApplication::translate("MainWindow", "0.00", 0));
#ifndef QT_NO_TOOLTIP
        label_anjian_zi->setToolTip(QApplication::translate("MainWindow", "\346\257\217\345\255\227\346\214\211\351\224\256\346\225\260", 0));
#endif // QT_NO_TOOLTIP
        label_anjian_zi->setText(QApplication::translate("MainWindow", "0.00", 0));
#ifndef QT_NO_TOOLTIP
        label_index->setToolTip(QApplication::translate("MainWindow", "\345\275\223\345\211\215\346\256\265\346\225\260", 0));
#endif // QT_NO_TOOLTIP
        label_index->setText(QApplication::translate("MainWindow", "<html><head/><body><p>No.0</p></body></html>", 0));
#ifndef QT_NO_TOOLTIP
        label_title->setToolTip(QApplication::translate("MainWindow", "\346\226\207\347\253\240\346\240\207\351\242\230", 0));
#endif // QT_NO_TOOLTIP
        label_title->setText(QApplication::translate("MainWindow", "\346\240\207\351\242\230", 0));
#ifndef QT_NO_TOOLTIP
        label_type->setToolTip(QApplication::translate("MainWindow", "\346\226\207\347\253\240\347\261\273\345\236\213", 0));
#endif // QT_NO_TOOLTIP
        label_type->setText(QApplication::translate("MainWindow", "\347\261\273\345\236\213", 0));
#ifndef QT_NO_TOOLTIP
        label_wordnum->setToolTip(QApplication::translate("MainWindow", "\345\275\223\345\211\215\350\277\233\345\272\246", 0));
#endif // QT_NO_TOOLTIP
        label_wordnum->setText(QApplication::translate("MainWindow", "0.00%", 0));
        pushButton_file->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256", 0));
#ifndef QT_NO_TOOLTIP
        plainTextEdit_input->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        label_wubi->setToolTip(QApplication::translate("MainWindow", "\344\272\224\347\254\224\346\213\206\350\247\243", 0));
#endif // QT_NO_TOOLTIP
        label_wubi->setText(QApplication::translate("MainWindow", "\344\272\224\347\254\224\346\213\206\350\247\243", 0));
        label_time->setText(QApplication::translate("MainWindow", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
