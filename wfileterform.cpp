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

    //读取配置文件

}

WFileterForm::~WFileterForm()
{
    delete ui;
}

void WFileterForm::on_pushButton_clicked()
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

void WFileterForm::on_listWidget_activated(const QModelIndex &index)
{
//    qDebug() << index;
}

void WFileterForm::on_listWidget_itemActivated(QListWidgetItem *item)
{
    qDebug() << item->text();
}
