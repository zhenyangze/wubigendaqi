#include "ui_wfileterform.h"
#include "wfileterform.h"

#include "wfiltercentence.h"

#include "wfilterstatement.h"
#include <QScreen>

#include "wfilterword.h"

WFileterForm::WFileterForm(QWidget*parent) : QWidget(parent), ui(new Ui::WFileterForm) {
    ui->setupUi(this);

    // 居中设置
    QScreen* desktop = QApplication::primaryScreen();
    int width = desktop->geometry().width();
    int height = desktop->geometry().height();

    move((width - this->width()) / 2, (height - this->height()) / 2);

    // 单词
    WfilterWord*ww = new WfilterWord();

    ui->tabWidget->addTab(ww, "单字");
    connect(ww, SIGNAL(noticeMainStart()), this, SLOT(receiveNotice()));

    // 词组
    WFilterStatement*ws = new WFilterStatement();

    ui->tabWidget->addTab(ws, "词组");
    connect(ws, SIGNAL(noticeMainStart()), this, SLOT(receiveNotice()));

    // 词组
    WfilterCentence*wc = new WfilterCentence();

    ui->tabWidget->addTab(wc, "句子");
    connect(wc, SIGNAL(noticeMainStart()), this, SLOT(receiveNotice()));
}

WFileterForm::~WFileterForm() {
    delete ui;
}

void WFileterForm::receiveNotice() {
    emit noticeMainStart();

    this->close();
}
