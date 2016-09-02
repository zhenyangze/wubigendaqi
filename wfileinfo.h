#ifndef WFILEINFO_H
#define WFILEINFO_H

#include <QWidget>
#include <QFileDialog>
#include <QString>
#include <QMessageBox>
#include <QTextStream>
#include <QTextCodec>
#include <QFileInfo>
#include <QFile>

class WFileInfo : public QWidget
{
    Q_OBJECT
private:
    QString filePath;
    QString fileContents;

public:
    explicit WFileInfo(QWidget *parent = 0);
    void openFile();
    void setFilePath(QString filePath);
    QString getFilePath();
    QString getFileContents(QString filePath = "");
    QString getFileName(QString filePath = "");

signals:

public slots:
};

#endif // WFILEINFO_H
