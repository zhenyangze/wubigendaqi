#ifndef WFILTERCENTENCE_H
#define WFILTERCENTENCE_H

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
class WfilterCentence;
}

class WfilterCentence : public QWidget
{
    Q_OBJECT

public:
    explicit WfilterCentence(QWidget *parent = 0);
    ~WfilterCentence();
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
    Ui::WfilterCentence *ui;
    QList<QString> fileList;
    QString iniFile;
};

#endif // WFILTERCENTENCE_H
