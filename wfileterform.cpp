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
        //ui->listView->add2
    }

}
