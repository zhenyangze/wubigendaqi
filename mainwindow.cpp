#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //当前路径
    QDir dir;

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



    //样式设置
    QString fileImagePath = QString(":/source/img/file.png");
    QPixmap fileImage(fileImagePath);
    ui->pushButton_file->setIcon(fileImage);

    //文件操作下拉
    QMenu *menu = new QMenu;
    QAction *actionOpen = new QAction("打开文件", menu);
    QAction *actionExit = new QAction("退出", menu);
    QAction *actionTest = new QAction("测试", menu);
    menu->addAction(actionOpen);
    menu->addAction(actionExit);
    menu->addAction(actionTest);
    ui->pushButton_file->setMenu(menu);


    //slot
    connect(actionOpen, SIGNAL(triggered(bool)), this, SLOT(openFile()));
    connect(actionExit, SIGNAL(triggered(bool)), this, SLOT(exit()));
    connect(actionTest, SIGNAL(triggered(bool)), this, SLOT(yiedText()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openFile(){
      WFileterForm *filterForm = new WFileterForm();
      connect(filterForm, SIGNAL(noticeMainStart()), this, SLOT(yiedText()));
      filterForm->show();
}

void MainWindow::oldFile(){

}

void MainWindow::exit(){
    this->close();
}
void MainWindow::test(){
    qDebug() << WfilePipi::filePath;
}

void MainWindow::startSend(){
    qDebug() << WfilePipi::contentList[0];
}

void MainWindow::yiedText(){
    if (WfilePipi::index >= WfilePipi::contentList.length()) {
        return;
    }
    QString showLine = WfilePipi::contentList.at(WfilePipi::index);
    if (showLine.length() <= 0) {
        return;
    }

    ui->textEdit_course->setText(showLine);
    WfilePipi::index++;
}
