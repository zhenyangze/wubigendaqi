#ifndef WFILEPIPI_H
#define WFILEPIPI_H

#include <QString>
#include <QStringList>

class WfilePipi
{
public:
    WfilePipi();
    static QString filePath; //文件路径
    static QString fileContents; //文件内容
    static QStringList contentList; //单个列表
    static bool isLimit; //是否时间限制
    static double totalTime; //总时间
    static int index; //当前索引
};

#endif // WFILEPIPI_H
