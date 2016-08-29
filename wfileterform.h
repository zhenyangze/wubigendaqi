#ifndef WFILETERFORM_H
#define WFILETERFORM_H

#include <QWidget>
#include <QDesktopWidget>
#include "wfileinfo.h"
#include <QString>
#include <QListWidgetItem>
#include <QDebug>
//#include <QList>
#include <QStringList>
#include <QMessageBox>

namespace Ui {
class WFileterForm;
}

class WFileterForm : public QWidget
{
    Q_OBJECT
private:
    QList<QString> fileList;
public:
    explicit WFileterForm(QWidget *parent = 0);
    ~WFileterForm();

private slots:
    void on_pushButton_clicked();

    void on_listWidget_activated(const QModelIndex &index);

    void on_listWidget_itemActivated(QListWidgetItem *item);



private:
    Ui::WFileterForm *ui;
};

#endif // WFILETERFORM_H
