#include "wfilterdanzi.h"

WFilterDanzi::WFilterDanzi()
{

}

void WFilterDanzi::setFileContents(QString fileContents){
    this->fileContents = fileContents;
}

void WFilterDanzi::setFileList(QStringList fileList) {
    this->fileList = fileList;
}

void WFilterDanzi::setFilePath(QString filePath) {
    this->filePath = filePath;
}

void WFilterDanzi::setInputFenge(QString inputFenge) {
    this->inputFenge = inputFenge;
}

void WFilterDanzi::setInputLineNum(int inputLineNum){
    this->inputLineNum = inputLineNum;
}

void WFilterDanzi::setInputWordNum(int inputWordNum){
    this->inputLineNum = inputWordNum;
}

void WFilterDanzi::setInputWordTime(double inputWordTime){
    this->inputWordTime = inputWordTime;
}

void WFilterDanzi::setIsLimitTime(bool isLimitTime){
    this->isLimitTime = isLimitTime;
}

void WFilterDanzi::setIsRand(bool isRand){
    this->isRand = isRand;
}

QString WFilterDanzi::getCurrentContents(){
    return this->currentContents;
}
QString WFilterDanzi::getFileContents(){
    return this->fileContents;
}

QStringList WFilterDanzi::getFileList(){
    return this->fileList;
}

QString WFilterDanzi::getFilePath(){
    return this->filePath;
}

QString WFilterDanzi::getInputFenge(){
    return this->inputFenge;
}

int WFilterDanzi::getInputLineNum(){
    return this->inputLineNum;
}

int WFilterDanzi::getInputWordNum(){
    return this->inputWordNum;
}

double WFilterDanzi::getInputWordTime(){
    return this->inputWordTime;
}

bool WFilterDanzi::getIsLimitTime(){
    return this->isLimitTime;
}

bool WFilterDanzi::getIsRand(){
    return this->isRand;
}

int WFilterDanzi::getTotalWordNum(){
    return this->totalWordNum;
}
