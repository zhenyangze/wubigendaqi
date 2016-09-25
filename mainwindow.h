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
#include <QTextCursor>
#include <QTextCharFormat>
#include <QWidget>
#include "wdb.h"
#include "wuserrecord.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void readDi(QString filePath = ""); //读取字典
    //void keyReleaseEvent(QKeyEvent *); //键盘按下
    bool eventFilter(QObject *, QEvent *); //事件过滤

public slots:
    void openFile(); //打开文件
    void oldFile(); //历史记录
    void exit(); //退出
    void test(); //测试
    void startSend(); //开始发送
    void yiedText(); //迭代请求
    void repeatSend(); //重新发送
    void preText(); //上一段
    void nextText(); //下一段
    void currentText(); //当前段

    void showUserRecord(); //显示用户的记录信息
    void showDi();//显示五笔拆解
    void timeUpdate(); //每一秒更新
    void setLineColor();//设置字体颜色
    void getProgress();//获取当前进度
    void startEdit(); //开始编辑
    void endEdit();//结束编辑

    void countUserWord();//统计用户输入字数
    void countUserKeyDown(); //统计用户按了多少次键
    void countUserSpeed(); //用户打字速度
    void countUserCorrect(); //统计用户正确率
    void countUserKeyDownPerSeconds(); //每秒按键数
    void countUserKeyDownPerWord(); //每字按键数

    void checkInput();// 检测输入，如果输入字数符合，则转下一段
    void saveUserData(); //保存用户记录

    void changeStyle();//改变样式

signals:
    void setStartStatus();//设置IsStart为true
    void cancelStartStatus();//设置isStart为false

private:
    Ui::MainWindow *ui;
    QLabel *label_wubi;
    QLabel *label_time;
    QLabel *label_step;
    QHash<QString, QString> diList;
    Wdb *db;


};

#endif // MAINWINDOW_H
