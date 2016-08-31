#ifndef WFILTERDANZI_H
#define WFILTERDANZI_H

#include <QString>
#include <QStringList>



class WFilterDanzi
{
private:
    QStringList fileList;//文件列表
    QString filePath = QString(""); //当前选择的文件
    QString fileContents = ""; //当前选择文件的内容
    QString inputFenge = ""; //分隔符号
    int inputWordNum = int(0); //每行字数
    int inputLineNum = int(0);//一次显示几行
    bool isRand = true; //是否随机显示
    bool isLimitTime = false;//是否时间限制
    double inputWordTime = 0;//每个字的时间

    QString currentContents;//当前显示的内容
    //int currentIndex = int(0); //当前请求的次数
    int totalWordNum = int(0); //统计的字数


public:
    WFilterDanzi();
    void setFileList(QStringList fileList);
    QStringList getFileList();

    void setFilePath(QString filePath);
    QString getFilePath();

    void setFileContents(QString fileContents);
    QString getFileContents();

    void setInputFenge(QString inputFenge);
    QString getInputFenge();

    void setInputWordNum(int inputWordNum);
    int getInputWordNum();

    void setInputLineNum(int inputLineNum);
    int getInputLineNum();

    void setIsRand(bool isRand);
    bool getIsRand();

    void setIsLimitTime(bool isLimitTime);
    bool getIsLimitTime();

    void setInputWordTime(double inputWordTime);
    double getInputWordTime();

    QString getCurrentContents();

    int getTotalWordNum();
};

#endif // WFILTERDANZI_H
