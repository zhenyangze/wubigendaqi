#include "wfileterform.h"
#include "ui_wfileterform.h"

WFileterForm::WFileterForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WFileterForm)
{
    ui->setupUi(this);
}

WFileterForm::~WFileterForm()
{
    delete ui;
}
