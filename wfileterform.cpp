#include "wfileterform.h"
#include "ui_wfileterform.h"

WFileterForm::WFileterForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WFileterForm)
{
    ui->setupUi(this);

    //居中设置
    QDesktopWidget* desktop = QApplication::desktop();
    int width = desktop->width();
    int height = desktop->height();
    move((width - this->width())/2, (height - this->height())/2);

    //输入限制
    //ui->lineEdit_linenum->setValidator(new QIntValidator(0, 100, this));
    ui->lineEdit_wordnum->setValidator(new QIntValidator(0, 1500, this));
    ui->lineEdit_time->setValidator(new QDoubleValidator(0.01, 10.00, 2));


    //控件临时
    ui->pushButton_send->setEnabled(false);
    ui->lineEdit_time->setEnabled(false);

    //读取配置文件
    this->readIni();

    //slot
    connect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(selectItemFIle(QListWidgetItem*)));
    connect(ui->checkBox_dingshi, SIGNAL(clicked(bool)), this, SLOT(checkInputTime(bool)));
    connect(ui->lineEdit_fenge, SIGNAL(textChanged(QString)), this, SLOT(saveIni()));
    connect(ui->lineEdit_time, SIGNAL(textChanged(QString)), this, SLOT(saveIni()));
    connect(ui->lineEdit_wordnum, SIGNAL(textChanged(QString)), this, SLOT(saveIni()));
    connect(ui->radioButton_order_shunxu, SIGNAL(toggled(bool)), this, SLOT(saveIni()));
    connect(ui->checkBox_dingshi, SIGNAL(toggled(bool)), this, SLOT(saveIni()));

}

WFileterForm::~WFileterForm()
{
    delete ui;
}

//添加文件列表
void WFileterForm::on_pushButton_addFile_clicked()
{
    WFileInfo *fileInfo = new WFileInfo;
    fileInfo->openFile();
    QString filePath = fileInfo->getFilePath();
    if (filePath.length() > 0) {
        bool isHas = this->fileList.contains(filePath);
        if (isHas) {
            QMessageBox::information(this, "提示", "文件已存在");
            return;
        }
        //ui->listView->add2
        QListWidgetItem *item = new QListWidgetItem;
        item->setText(filePath);
        ui->listWidget->addItem(item);
        this->fileList<<filePath;
    }

    this->saveIni();
}

//选择文件
void WFileterForm::selectItemFIle(QListWidgetItem *item){
    QString filePath = item->text();
    QFileInfo *fileInfo = new QFileInfo(filePath);
    WFileInfo *wfileInfo = new WFileInfo;
    if (fileInfo->fileName().length() > 0){
        WfilePipi::filePath = filePath;
        ui->label_select_file_name->setText(fileInfo->fileName());
        ui->pushButton_send->setEnabled(true);
        ui->plainTextEdit->setPlainText(wfileInfo->getFileContents(filePath));

    }

    this->saveIni();
}

//点击发送按钮，组合数据，传递给全局类
void WFileterForm::on_pushButton_send_clicked()
{
    this->saveIni();
    //filePath
    //WfilePipi::filePath = ui->label_select_file_name->text();

    //contents
    WFileInfo *fileInfo = new WFileInfo;
    //fileInfo->setFilePath(WfilePipi::filePath);
    WfilePipi::fileContents = fileInfo->getFileContents(WfilePipi::filePath);
    WfilePipi::fileName = fileInfo->getFileName(WfilePipi::filePath);
    //清除空格


    //isTimeLimit
    if (ui->checkBox_dingshi->isChecked()){
        WfilePipi::isLimit = true;
    } else {
        WfilePipi::isLimit = false;
    }

    //contentList

    //tempStrList 临时列表
    QString fileContents = WfilePipi::fileContents;
    QStringList tempStrList = fileContents.split(ui->lineEdit_fenge->text(), QString::SkipEmptyParts);
    int contentsLength = tempStrList.length();

    //是否随机
    if (true == ui->radioButton_order_suiji->isChecked()){
        for(int i = 0; i< contentsLength; i++){
            int randIndex = qrand() % contentsLength;
            int currentIndex = i % contentsLength;

            if (randIndex != currentIndex) {
                qSwap(tempStrList[randIndex], tempStrList[currentIndex]);
            }
        }
    }


    int wordNum = ui->lineEdit_wordnum->text().toInt();
    int wordCount = 0;
    int totalCount = 0;//除去空白字符后所有的字数
    QString lineInfo = "";
    QString tmpStr = "";
    WfilePipi::contentList.clear();
    for(int i = 0; i < contentsLength;i++){

        tmpStr = tempStrList[i];
        tmpStr = tmpStr.simplified().trimmed();
        if (tmpStr.length() == 0){
            continue;
        }

        if (wordCount >= wordNum){
            WfilePipi::contentList << lineInfo;
            lineInfo = "";
            wordCount = 0;
        }
        wordCount++;
        totalCount++;
        lineInfo += tmpStr;
    }

    if (lineInfo.length() > 0){
        WfilePipi::contentList << lineInfo;
        lineInfo = "";
    }

    //index
    WfilePipi::index = 0;

    //contentType
    WfilePipi::contentType = "单字";

    //contentCount
    WfilePipi::contentCount = WfilePipi::contentList.join("").length();

    //totaltime
    WfilePipi::totalTime = totalCount * (ui->lineEdit_time->text().toDouble());

    //emit
    emit noticeMainStart();

    //close
    this->saveIni();
    this->close();
}

//选择不限时间的按钮时，禁止时间输入框
void WFileterForm::checkInputTime(bool isSelect){
    if(isSelect == true) {
        ui->lineEdit_time->setEnabled(true);
    } else {
        ui->lineEdit_time->setEnabled(false);
    }
    this->saveIni();
}

void WFileterForm::readIni(){
    QString iniFile = QDir::currentPath() + "/filter.ini";
    QFile file(iniFile);
    if(!file.exists()){
        return;
    }
    QDataStream in(&file);
    if (!file.open(QIODevice::ReadOnly)){
        qDebug() << "读入文件错误，请检查权限";
        return;
    }

    QString inputFenge;
    QString inputWordNum;
    QString inputTime;
    bool isSuiji;
    bool isShunxu;
    bool isLimit;

    in >> this->fileList
       >> inputFenge
       >> inputWordNum
       >> inputTime
       >> isShunxu
       >> isSuiji
       >> isLimit;

    ui->lineEdit_fenge->setText(inputFenge);
    ui->lineEdit_time->setText(inputTime);
    ui->lineEdit_wordnum->setText(inputWordNum);


    ui->radioButton_order_suiji->setChecked(isSuiji);
    ui->radioButton_order_shunxu->setChecked(isShunxu);
    ui->checkBox_dingshi->setChecked(isLimit);

    for(int i = 0; i < this->fileList.length(); i++){
        QListWidgetItem *item = new QListWidgetItem;
        item->setText(this->fileList[i]);
        ui->listWidget->addItem(item);
    }

    file.close();
}

void WFileterForm::saveIni(){
    QString iniFile = QDir::currentPath() + "/filter.ini";
    QFile file(iniFile);
    QDataStream out(&file);
    if (!file.open(QIODevice::WriteOnly)){
        qDebug() << iniFile  << "写入文件错误，请检查权限";
        return;
    }

    out << this->fileList
        << ui->lineEdit_fenge->text()
        << ui->lineEdit_wordnum->text()
        << ui->lineEdit_time->text()
        << ui->radioButton_order_shunxu->isChecked()
        << ui->radioButton_order_suiji->isChecked()
        <<ui->checkBox_dingshi->isChecked();
    file.close();
}


