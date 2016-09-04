#ifndef WFILTERSTATEMENT_H
#define WFILTERSTATEMENT_H

#include <QWidget>
#include "wfilterword.h"

#include <QWidget>
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
#include <QFile>
#include <QDataStream>
#include <QIODevice>
#include "wfileinfo.h"
#include "wfilepipi.h"

namespace Ui {
class WFilterStatement;
}

class WFilterStatement : public QWidget
{
    Q_OBJECT

public:
    explicit WFilterStatement(QWidget *parent = 0);
    ~WFilterStatement();

public slots:
    void selectItemFIle(QListWidgetItem *item);

    void on_pushButton_addFile_clicked();

    void on_pushButton_send_clicked();
    void checkInputTime(bool isSelect);
    void readIni();
    void saveIni();

signals:
    void noticeMainStart();
private:
    Ui::WFilterStatement *ui;
    QList<QString> fileList;
    QString iniFile;
};

#endif // WFILTERSTATEMENT_H
