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
    this->setWindowTitle(tr("霹雳五笔跟打器"));
    ui->textEdit_course->setHtml("");



    //样式设置

    //状态栏

    //文件操作下拉
    QMenu *menu = new QMenu;
    QAction *actionOpen = new QAction("文件", menu);
    QAction *actionRepeat = new QAction("重发", menu);

    QAction *actionExit = new QAction("退出", menu);
    QAction *actionTest = new QAction("测试", menu);

    menu->addAction(actionOpen);
    menu->addAction(actionExit);
    menu->addAction(actionTest);
    menu->addAction(actionRepeat);
    ui->pushButton_file->setMenu(menu);

    //字典
    this->readDi();

    //slot
    connect(actionOpen, SIGNAL(triggered(bool)), this, SLOT(openFile()));
    connect(actionExit, SIGNAL(triggered(bool)), this, SLOT(exit()));
    connect(actionTest, SIGNAL(triggered(bool)), this, SLOT(test()));
    connect(actionRepeat, SIGNAL(triggered(bool)), this, SLOT(repeatSend()));
    connect(ui->textEdit_course, SIGNAL(textChanged()), this, SLOT(showDi()));
    connect(ui->plainTextEdit_input, SIGNAL(textChanged()), this, SLOT(showDi()));
    connect(ui->plainTextEdit_input, SIGNAL(textChanged()), this, SLOT(setLineColor()));
    connect(ui->textEdit_course, SIGNAL(textChanged()), this, SLOT(getProgress()));
    connect(ui->plainTextEdit_input, SIGNAL(textChanged()), this, SLOT(getProgress()));

    //timer
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timeUpdate()));
    //关联定时器计满信号和相应的槽函数
    timer->start();
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
    //qDebug() << WfilePipi::filePath;
    //this->setLineColor();
    this->yiedText();
}

void MainWindow::startSend(){
    //qDebug() << WfilePipi::contentList[0];
}

void MainWindow::repeatSend()
{
    WfilePipi::index = 0;
    this->yiedText();
}

void MainWindow::yiedText(){

    if (WfilePipi::index >= WfilePipi::contentList.length()) {
        return;
    }
    QString showLine = WfilePipi::contentList.at(WfilePipi::index);
    if (showLine.length() <= 0) {
        return;
    }

    if (WfilePipi::index == 0 && WfilePipi::fileName.length() > 0) {
        ui->label_title->setText(WfilePipi::fileName); //文章标题
        ui->label_type->setText(WfilePipi::contentType);
    }
    ui->textEdit_course->setHtml(showLine);

    ui->plainTextEdit_input->setPlainText("");

    WfilePipi::index++;

     //显示当前段
    ui->label_index->setText("No." + QString::number(WfilePipi::index));

    //计算总数
    this->getProgress();
}

void MainWindow::showDi(){
    QString sourceText = ui->textEdit_course->document()->toPlainText();
    QString userText = ui->plainTextEdit_input->document()->toPlainText();
    if (sourceText.length() <= userText.length()){
        return;
    }
    QString currentWord = sourceText.at(userText.length());
    currentWord = currentWord.trimmed();
    if (0 == currentWord.length()){
        return;
    }
    QString wubi = this->diList[currentWord];
    ui->label_wubi->setText(currentWord + ": " + wubi);

}

void MainWindow::readDi(QString filePath){
    if (filePath.length() == 0){
        filePath = ":/source/data/di.txt";
    }
    WFileInfo *fileInfo = new WFileInfo;
    QString contents = fileInfo->getFileContents(filePath);
    QStringList contentsList = contents.split("\n", QString::SkipEmptyParts);
    for(int i = 0; i< contentsList.length(); i++){
        QString currentLine = contentsList[i];
        currentLine = currentLine.simplified();
        currentLine = currentLine.trimmed();
        if (0 == currentLine.length()){
            continue;
        }
        QStringList currentLineList = currentLine.split(" ");
        if (currentLineList.length() > 1){
            for(int j = 1; j < currentLineList.length(); j++){
                this->diList[currentLineList.at(j)] = currentLineList.at(0);
            }
        }
    }
    //qDebug() <<this->diList.count();
}

void MainWindow::timeUpdate(){
    QDateTime time = QDateTime::currentDateTime();
    //获取系统现在的时间
    QString timeStr = time.toString("yyyy-MM-dd hh:mm:ss ddd"); //设置显示格式
    ui->label_time->setText(timeStr);
}

void MainWindow::setLineColor(){
    int index = WfilePipi::index - 1;
    if (index <= 0) {
        index = 0;
    }
    QString showLine = WfilePipi::contentList.at(index);

    QString userText = ui->plainTextEdit_input->document()->toPlainText();
    if (showLine.length() == 0 || userText.length() == 0){
        return;
    }
    //设置进度颜色
    QString showColorContents = "";
    for(int i = 0; i < userText.length() && i < showLine.length(); i++){
        if (userText.data()[i] == showLine.at(i)){
            showColorContents += showLine.at(i);
        } else {
            showColorContents += "<span style='color:red;'>" + QString(showLine.at(i)) + "</span>";
        }
    }
    showColorContents = "<span style='background-color:#ccc;float;'>" + showColorContents + "</span>";
    if (userText.length() <= showLine.length()){
        showColorContents += showLine.right(showLine.length() - userText.length());
    }
    if (showColorContents.length() > 0){
        ui->textEdit_course->setHtml(showColorContents);
    }

}
void MainWindow::getProgress(){
    //当WfilePipi::index > 0, 并且输入框内容发生变化时。
    if (WfilePipi::index <= 0){
        return;
    }
    int totalCount = WfilePipi::contentCount;
    if (totalCount <= 0){
        return;
    }
    float allReady = 0.00;

    for (int i = 0; i< WfilePipi::index - 1; i++){
        QString tmpStr = WfilePipi::contentList.at(i);
        allReady += tmpStr.length();
    }

    allReady += ui->plainTextEdit_input->toPlainText().length();
    qDebug() << WfilePipi::index << allReady;
    if (allReady >= totalCount){
        allReady = totalCount;
    }

    float progress;
    progress = allReady * 100 / totalCount;
    qDebug() << totalCount << allReady;
    QString showProgress = QString::number(progress, 'f', 2);
    ui->label_wordnum->setText(showProgress + "%");
}
