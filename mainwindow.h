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

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void openFile();
    void oldFile();
    void exit();
    void test();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
