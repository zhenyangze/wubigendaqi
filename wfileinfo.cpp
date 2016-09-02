#include "wfileinfo.h"

WFileInfo::WFileInfo(QWidget *parent) : QWidget(parent)
{

}

void WFileInfo::openFile(){
    QFileDialog *fileDialog = new QFileDialog;
    QString filePath = fileDialog->getOpenFileName(this, tr("选择文件"), ".", tr("文体文件(*.txt)"));
    if (0 == filePath.length()){
        return;
    } else {
        this->filePath = filePath;
    }
}
QString WFileInfo::getFilePath(){
    return this->filePath;
}

QString WFileInfo::getFileContents(QString filePath){
    QString fileName;
    if (filePath.length() > 0){
        fileName = filePath;
    } else {
        fileName = this->filePath;
    }
    QTextCodec * code = QTextCodec::codecForName("utf8");
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this,"Warnning","can't open",QMessageBox::Yes);
    }
    QTextStream stream(&file);
    stream.setCodec(code);//对输出流的设置

    while (stream.atEnd() == 0) {
        this->fileContents = stream.readAll();
    }
    file.close();
    return this->fileContents;
}
QString WFileInfo::getFileName(QString filePath)
{
    QString fileName;
    if (filePath.length() > 0){
        fileName = filePath;
    } else {
        fileName = this->filePath;
    }

    QFileInfo *fileInfo = new QFileInfo(fileName);
    return fileInfo->baseName();
}
