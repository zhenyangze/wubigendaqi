#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //当前路径
    QDir dir;

    //创建目录
    QString dataPath = QCoreApplication::applicationDirPath() + "/data";
    QString stylePath = QCoreApplication::applicationDirPath() + "/style";
    if(!dir.exists(dataPath)){
        dir.mkdir(dataPath);
    }
    if(!dir.exists(stylePath)){
        dir.mkdir(stylePath);
    }

    //数据 库加载
    this->db = new Wdb;
    this->db->connect(dataPath + "/user.db");

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
    this->changeStyle();

    //状态栏

    //文件操作下拉
    QMenu *menu = new QMenu;
    QAction *actionOpen = new QAction("文件", menu);
    QAction *actionRepeat = new QAction("重发", menu);

    QAction *actionExit = new QAction("退出", menu);
    //QAction *actionTest = new QAction("测试", menu);

    menu->addAction(actionOpen);
    menu->addAction(actionRepeat);
    menu->addAction(actionExit);
    //menu->addAction(actionTest);
    ui->pushButton_file->setMenu(menu);

    //字典
    this->readDi();

    //事件过滤
    ui->plainTextEdit_input->installEventFilter(this);

    //slot
    connect(actionOpen, SIGNAL(triggered(bool)), this, SLOT(openFile())); //选择文件
    connect(actionExit, SIGNAL(triggered(bool)), this, SLOT(exit())); //退出
    //connect(actionTest, SIGNAL(triggered(bool)), this, SLOT(test()));
    connect(actionRepeat, SIGNAL(triggered(bool)), this, SLOT(repeatSend())); //重新发文
    connect(ui->textEdit_course, SIGNAL(textChanged()), this, SLOT(showDi())); //查询五笔
    connect(ui->plainTextEdit_input, SIGNAL(textChanged()), this, SLOT(showDi())); //查询五笔
    connect(ui->plainTextEdit_input, SIGNAL(textChanged()), this, SLOT(setLineColor())); //设置字体颜色
    connect(ui->textEdit_course, SIGNAL(textChanged()), this, SLOT(getProgress()));//更新进度
    connect(ui->plainTextEdit_input, SIGNAL(textChanged()), this, SLOT(getProgress())); //更新进度
    connect(ui->plainTextEdit_input, SIGNAL(textChanged()), this, SLOT(countUserWord()));// 统计用户输入字数
    connect(ui->plainTextEdit_input, SIGNAL(textChanged()), this, SLOT(countUserSpeed()));// 统计用户打字速度
    connect(ui->plainTextEdit_input, SIGNAL(textChanged()), this, SLOT(countUserCorrect()));// 统计用户错误率
    connect(ui->plainTextEdit_input, SIGNAL(textChanged()), this, SLOT(checkInput()));// 检测输入
    //connect(ui->plainTextEdit_input, SIGNAL(2)

    //timer
    QTimer *timer = new QTimer(this);
    this->timeUpdate();
    connect(timer,SIGNAL(timeout()),this,SLOT(timeUpdate()));
    connect(timer, SIGNAL(timeout()), this, SLOT(countUserSpeed()));
    connect(timer, SIGNAL(timeout()), this, SLOT(countUserKeyDownPerSeconds()));
    connect(timer, SIGNAL(timeout()), this, SLOT(countUserKeyDownPerWord()));
    //关联定时器计满信号和相应的槽函数
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    this->db->close();//关闭数据库

    delete ui;
}

//选择发文文件
void MainWindow::openFile(){
      WFileterForm *filterForm = new WFileterForm();
      connect(filterForm, SIGNAL(noticeMainStart()), this, SLOT(yiedText()));
      filterForm->setStyleSheet("QLabel {color:#4f4f4f;}QPushButton{color:#4f4f4f;}");
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

//重新发文
void MainWindow::repeatSend()
{
    QDateTime dt = QDateTime::currentDateTime();
    WfilePipi::ukey = dt.toTime_t(); //保证唯一
    WfilePipi::index = 0;
    this->yiedText();
}

//按段发文
void MainWindow::yiedText(){

    if (WfilePipi::index >= WfilePipi::contentList.length()) {
        return;
    }
    QString showLine = WfilePipi::contentList.at(WfilePipi::index);
    if (showLine.length() <= 0) {
        return;
    }

    //发文初始
    if (WfilePipi::index == 0 && WfilePipi::fileName.length() > 0) {
        WfilePipi::initUserInfo(); //初始用户信息
        ui->label_title->setText(WfilePipi::fileName); //文章标题
        ui->label_type->setText(WfilePipi::contentType);
    }
    ui->textEdit_course->setHtml(showLine);

    ui->plainTextEdit_input->setPlainText("");

    WfilePipi::userOldInput = "";

    WfilePipi::index++;

     //显示当前段
    ui->label_index->setText("No." + QString::number(WfilePipi::index));

    //计算总数
    this->getProgress();
}

//显示五笔
void MainWindow::showDi(){
    QString sourceText = ui->textEdit_course->document()->toPlainText();
    QString userText = ui->plainTextEdit_input->document()->toPlainText();
    if (sourceText.length() <= userText.length()){
        return;
    }

    QString currentWord;
    if(WfilePipi::contentType == "词组"){
        int currentIndex = WfilePipi::index - 1;
        if (currentIndex < 0){
            currentIndex = 0;
        }
        QString showLineStr = WfilePipi::contentList.at(currentIndex);
        QStringList showLineList = showLineStr.split(QRegExp("\\s+"), QString::SkipEmptyParts);

        QStringList userTextList = userText.split(QRegExp("\\s+"), QString::SkipEmptyParts);
        if(showLineList.length() > userTextList.length()) {
            currentWord = showLineList.at(userTextList.length());
        } else {
            return;
        }
    } else {
        currentWord = sourceText.at(userText.length());
    }

    currentWord = currentWord.trimmed();
    if (0 == currentWord.length()){
        return;
    }
    QString wubi = this->diList[currentWord];
    ui->label_wubi->setText(currentWord + ": " + wubi);

}

//读取五笔字典
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

//更新界面中的时间
void MainWindow::timeUpdate(){
    QDateTime time = QDateTime::currentDateTime();
    //获取系统现在的时间
    QString timeStr = time.toString("yyyy-MM-dd hh:mm:ss"); //设置显示格式
    ui->label_time->setText(timeStr);

    //更新用户练习时间
    if (true == WfilePipi::isStart){
        WfilePipi::userTime++;
    }
    QString hour = "0" + QString::number(WfilePipi::userTime/3600);
    QString minute = "0" + QString::number((WfilePipi::userTime/60 ) % 60);
    QString second = "0" + QString::number(WfilePipi::userTime % 60);
    ui->label_jishi->setText(hour.right(2) + ":" + minute.right(2) + ":" + second.right(2));

    //更新样式
    if (true == WfilePipi::isStart){
        ui->label_jishi->setStyleSheet("border:1px solid green;max-height:16;background-color: #ccc;");
    } else {
        QString secondStr = time.toString("ss");
        int second = secondStr.toInt();
        int styleNum = second % 2;
        QString style ;
        if (styleNum == 0){
            style = "border:1px solid #ccc;max-height:16;background-color: #ccc;";
        } else {
            style = "border:1px solid red;max-height:16;background-color: #ccc;";
        }
        ui->label_jishi->setStyleSheet(style);
    }
}

//当用户输入错误的字时，对原始字加颜色标示
void MainWindow::setLineColor(){
    int index = WfilePipi::index - 1;
    if (index <= 0) {
        index = 0;
    }

    if(WfilePipi::contentList.length() == 0){
        return;
    }
    QString showLine = WfilePipi::contentList.at(index);

    QString userText = ui->plainTextEdit_input->document()->toPlainText();
    if (showLine.length() == 0 || userText.length() == 0){
        return;
    }
    //设置进度颜色
    QString showColorContents = "";
    int correctNum = 0;
    for(int i = 0; i < userText.length() && i < showLine.length(); i++){
        if (userText.data()[i] == showLine.at(i)){
            showColorContents += showLine.at(i);
        } else {
            showColorContents += "<span style='color:red;'>" + QString(showLine.at(i)) + "</span>";
            correctNum++;
        }
    }
    WfilePipi::userCorrectNum[WfilePipi::index - 1] = correctNum;
    showColorContents = "<span style='background-color:#ccc;float;'>" + showColorContents + "</span>";
    if (userText.length() <= showLine.length()){
        showColorContents += showLine.right(showLine.length() - userText.length());
    }
    if (showColorContents.length() > 0){
        ui->textEdit_course->setHtml(showColorContents);
    }

}

//获取当前用户的进度，用百分比表示
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

    QString currenShowLine = WfilePipi::contentList.at(WfilePipi::index-1);
    if (ui->plainTextEdit_input->toPlainText().length() > currenShowLine.length()){
        return;
    }
    allReady += ui->plainTextEdit_input->toPlainText().length();

    if (allReady >= totalCount){
        allReady = totalCount;
    }

    float progress;
    progress = allReady * 100 / totalCount;

    //判断是否需要严格校验
    if (allReady == totalCount){
        WfilePipi::isStart = false;
        WfilePipi::isEnd = true;
    }

    QString showProgress = QString::number(progress, 'f', 2);
    ui->label_wordnum->setText(showProgress + "%");
    WfilePipi::current_progress = showProgress.toDouble();
}

//统计用户输入字数
//输入多少统计多少
void MainWindow::countUserWord(){
    QString userInput = ui->plainTextEdit_input->toPlainText();
    if (true == WfilePipi::isStart){
        if (userInput.length() > WfilePipi::userOldInput.length()){
            WfilePipi::userWordNum += (userInput.length() - WfilePipi::userOldInput.length());
        } else if(userInput.length() < WfilePipi::userOldInput.length()){
            WfilePipi::userDeleteNum += (WfilePipi::userOldInput.length() - userInput.length());
        }
        WfilePipi::userOldInput = userInput;
    }
}

//统计用户按了多少次键，输入法中delete也算是按键
void MainWindow::countUserKeyDown(){
    if (true == WfilePipi::isStart){
        WfilePipi::userKeyDownNum++;
    }
}

//统计用户打字速度
void MainWindow::countUserSpeed(){
    //更新speed记录
    double userSpeed;
    QString userSpeedStr = "0.00";
    if(WfilePipi::userTime > 0){
        userSpeed = (WfilePipi::userWordNum + 0.00) / WfilePipi::userTime * 60;
        //根据打字速度调整输入框样式
        //未完
        userSpeedStr = QString::number(userSpeed, 'f', 2);
        WfilePipi::userSpeed = userSpeedStr.toDouble(); //记录
    }
    ui->label_speed->setText(userSpeedStr);
    ui->label_huigai->setText(QString::number(WfilePipi::userDeleteNum));
}

//统计正确率
void MainWindow::countUserCorrect(){
    if (WfilePipi::isStart != true){
        return;
    }
    int correctNum = WfilePipi::getUserCorrectNum();
    double percent = 0.00;
    if (WfilePipi::userWordNum > 0){
        percent = (1 - (correctNum + 0.00)/WfilePipi::userWordNum) * 100;
    }
    QString percentStr = QString::number(percent, 'f', 2);
    ui->label_correct->setText(percentStr + "%");
    WfilePipi::correct_rate = percentStr.toDouble();
}

//检测输入,输入长度大于当前显示则转下一段
void MainWindow::checkInput(){
    int userInputLength = ui->plainTextEdit_input->toPlainText().length();
    if (userInputLength <= 0 || WfilePipi::contentList.length() == 0 || WfilePipi::index == 0){
        return;
    }
    QString currentLine = WfilePipi::contentList.at(WfilePipi::index - 1);
    int currentLineNum = currentLine.length();
    if(true == WfilePipi::isStart &&  userInputLength>= currentLineNum){
        WfilePipi::isStart = false;
        //此时保存用户记录
        this->saveUserData();

        this->yiedText();
    }
}

//每秒按键数
void MainWindow::countUserKeyDownPerSeconds(){
    double percent = 0.00;
    if (WfilePipi::userTime > 0){
        percent = (WfilePipi::userKeyDownNum + 0.00) / WfilePipi::userTime;
    }
    QString percentStr = QString::number(percent, 'f', 2);
    ui->label_anjian_second->setText(percentStr);
    WfilePipi::key_per_second = percentStr.toDouble();
}

//每个字按键数
void MainWindow::countUserKeyDownPerWord(){
    double percent = 0.00;
    if (WfilePipi::userWordNum > 0){
        percent = (WfilePipi::userKeyDownNum + 0.00) / WfilePipi::userWordNum;
    }
    QString percentStr = QString::number(percent, 'f', 2);
    ui->label_anjian_zi->setText(percentStr);
    WfilePipi::key_per_word = percentStr.toDouble();
}

void MainWindow::saveUserData(){
    if(WfilePipi::index > 0){
        this->db->saveResult();
    }
}

//触发开始编辑事件
void MainWindow::startEdit(){
    if(WfilePipi::index > 0 && false == WfilePipi::isEnd){
        WfilePipi::isStart = true;
        this->countUserKeyDown();
        this->countUserKeyDownPerSeconds();
        this->countUserKeyDownPerWord();
    }
}

//触发结束编辑事件
void MainWindow::endEdit(){
    WfilePipi::isStart = false;
}


//事件过滤
bool MainWindow::eventFilter(QObject *obj, QEvent *e){
    if(obj == ui->plainTextEdit_input){
        if (e->type() == QEvent::KeyRelease){
            emit startEdit();
        }

        if (e->type() == QEvent::FocusOut){
            emit endEdit();
        }

    }
    return false;
}

//改变样式
void MainWindow::changeStyle(){
   QString stylePath = "";
    if (QFile::exists(QCoreApplication::applicationDirPath() + "/style/style.qss")){
        stylePath = QCoreApplication::applicationDirPath() + "/style/style.qss";
    } else {
        stylePath = ":/source/style/style_default.qss";
        QFile::copy(stylePath, QCoreApplication::applicationDirPath() + "/style/style.qss");
    }

    QFile file(stylePath);

    file.open(QFile::ReadOnly);

    this->setStyleSheet(file.readAll());

    file.close();
}
