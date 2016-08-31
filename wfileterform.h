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
#include <QIntValidator>
#include <QDoubleValidator>
#include <QPixmap>
#include <QDir>
#include <QFileInfo>
#include "wfilepipi.h"


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

public slots:
    void selectItemFIle(QListWidgetItem *item);

    void on_pushButton_addFile_clicked();

    void on_pushButton_send_clicked();

private:
    Ui::WFileterForm *ui;
signals:
    void noticeMainStart();
};

#endif // WFILETERFORM_H
