#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDesktopWidget>
#include "wfileinfo.h"
#include <QString>
#include "wfileterform.h"
#include <QDir>
#include <QPixmap>
#include <QMenu>
#include <QAction>
//#include "wpipe.h"
#include <QDebug>
#include "wfilepipi.h"
#include <QFile>
#include <QHash>
#include <QDateTime>
#include <QTimer>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QProcess>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void readDi(QString filePath = "");

public slots:
    void openFile(); //打开文件
    void oldFile(); //历史记录
    void exit(); //退出
    void test(); //测试
    void startSend(); //开始发送
    void yiedText(); //迭代请求
    void repeatSend(); //重新发送
    void showDi();//显示五笔拆解
    void timeUpdate(); //每一秒更新

private:
    Ui::MainWindow *ui;
    QLabel *label_wubi;
    QLabel *label_time;
    QLabel *label_step;
    QHash<QString, QString> diList;

};

#endif // MAINWINDOW_H
