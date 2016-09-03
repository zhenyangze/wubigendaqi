#ifndef WFILEPIPI_H
#define WFILEPIPI_H

#include <QString>
#include <QStringList>

class WfilePipi
{
public:
    WfilePipi();
    static QString filePath; //文件路径
    static QString fileName; //文件名称
    static QString fileContents; //文件内容
    static QString contentType; //文字类型 字 词 句 文章
    static int contentCount; //格式化后的字数
    static QStringList contentList; //单个列表
    static bool isLimit; //是否时间限制
    static double totalTime; //总时间
    static int index; //当前索引

    static bool isStart;//是否开始
};

#endif // WFILEPIPI_H
