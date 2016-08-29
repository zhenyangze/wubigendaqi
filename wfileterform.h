#ifndef WFILETERFORM_H
#define WFILETERFORM_H

#include <QWidget>
#include <QDesktopWidget>
#include "wfileinfo.h"
#include <QString>

namespace Ui {
class WFileterForm;
}

class WFileterForm : public QWidget
{
    Q_OBJECT

public:
    explicit WFileterForm(QWidget *parent = 0);
    ~WFileterForm();

private slots:
    void on_pushButton_clicked();

private:
    Ui::WFileterForm *ui;
};

#endif // WFILETERFORM_H
