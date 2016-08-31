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
    ui->lineEdit_wordnum->setValidator(new QIntValidator(0, 50, this));
    ui->lineEdit_time->setValidator(new QDoubleValidator(0.01, 10.00, 2));

    //控件临时
    ui->pushButton_send->setEnabled(false);

    //读取配置文件

    //slot
    connect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(selectItemFIle(QListWidgetItem*)));
}

WFileterForm::~WFileterForm()
{
    delete ui;
}

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
}

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
}


void WFileterForm::on_pushButton_send_clicked()
{
    //filePath
    //WfilePipi::filePath = ui->label_select_file_name->text();

    //contents
    WFileInfo *fileInfo = new WFileInfo;
    //fileInfo->setFilePath(WfilePipi::filePath);
    WfilePipi::fileContents = fileInfo->getFileContents(WfilePipi::filePath);

    //isTimeLimit
    if (ui->checkBox_dingshi->isChecked()){
        WfilePipi::isLimit = true;
    } else {
        WfilePipi::isLimit = false;
    }

    //contentList

    //QString
    int contentsLength = WfilePipi::fileContents.length();
    int wordNum = ui->lineEdit_wordnum->text().toInt();
    int wordCount = 0;
    QString lineInfo = "";
    WfilePipi::contentList.clear();
    for(int i = 0; i < contentsLength;i++){
        if (wordCount >= wordNum){
            WfilePipi::contentList << lineInfo;
            lineInfo = "";
            wordCount = 0;
        }
        wordCount++;
        lineInfo += WfilePipi::fileContents.data()[i];
    }

    if (lineInfo.length() > 0){
        WfilePipi::contentList << lineInfo;
        lineInfo = "";
    }

    //index
    WfilePipi::index = 0;

    //totaltime
    WfilePipi::totalTime = contentsLength * (ui->lineEdit_time->text().toDouble());

    //emit
    emit noticeMainStart();

    //close
    this->close();
}
