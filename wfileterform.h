#ifndef WFILETERFORM_H
#define WFILETERFORM_H

#include <QWidget>

namespace Ui {
class WFileterForm;
}

class WFileterForm : public QWidget
{
    Q_OBJECT

public:
    explicit WFileterForm(QWidget *parent = 0);
    ~WFileterForm();

private:
    Ui::WFileterForm *ui;
};

#endif // WFILETERFORM_H
