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

    //单词
    WfilterWord *ww = new WfilterWord();
    ui->tabWidget->addTab(ww, "单字");
    connect(ww, SIGNAL(noticeMainStart()), this, SLOT(receiveNotice()));

    //词组
    WFilterStatement *ws = new WFilterStatement();
    ui->tabWidget->addTab(ws, "词组");
    connect(ws, SIGNAL(noticeMainStart()), this, SLOT(receiveNotice()));

    //词组
    WfilterCentence *wc = new WfilterCentence();
    ui->tabWidget->addTab(wc, "句子");
    connect(wc, SIGNAL(noticeMainStart()), this, SLOT(receiveNotice()));

}

WFileterForm::~WFileterForm()
{
    delete ui;
}

void WFileterForm::receiveNotice(){
    emit noticeMainStart();
    this->close();
}


