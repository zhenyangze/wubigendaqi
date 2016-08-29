#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //居中设置
    QDesktopWidget* desktop = QApplication::desktop();
    int width = desktop->width();
    int height = desktop->height();
    move((width - this->width())/2, (height - this->height())/2);


    this->setMaximumSize(this->size());
    this->setMinimumSize(this->size());

    this->setWindowTitle(tr("五笔跟打练习"));
    ui->horizontalLayout_2->setMargin(5);

    ui->textEdit_course->setText("");

    //slot
    connect(ui->action_exit, SIGNAL(triggered(bool)), this, SLOT(exit()));
    connect(ui->action_open, SIGNAL(triggered(bool)), this, SLOT(openFile()));
    connect(ui->action_old, SIGNAL(triggered(bool)), this, SLOT(oldFile()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openFile(){
//    WFileInfo *fileInfo = new WFileInfo;
//    fileInfo->openFile();
//    QString filePath = fileInfo->getFilePath();
//    if (filePath.length() > 0) {
//        QString fileContents = fileInfo->getFileContents();
//        ui->textEdit_course->setText(fileContents);
//    }
}

void MainWindow::oldFile(){

}

void MainWindow::exit(){
    QApplication *app;
    app->closeAllWindows();
}
