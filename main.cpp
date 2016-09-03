#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();
    a.setStyleSheet("QLabel {color:white;}QPushButton{color:white;}");
    return a.exec();
}
