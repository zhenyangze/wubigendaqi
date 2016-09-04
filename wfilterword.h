#ifndef WFILTERWORD_H
#define WFILTERWORD_H

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
class WfilterWord;
}

class WfilterWord : public QWidget
{
    Q_OBJECT
private:
    QList<QString> fileList;
public:
    explicit WfilterWord(QWidget *parent = 0);
    ~WfilterWord();

private:
    Ui::WfilterWord *ui;
    QString iniFile;

public slots:
    void selectItemFIle(QListWidgetItem *item);

    void on_pushButton_addFile_clicked();

    void on_pushButton_send_clicked();
    void checkInputTime(bool isSelect);
    void readIni();
    void saveIni();

signals:
    void noticeMainStart();
};

#endif // WFILTERWORD_H
