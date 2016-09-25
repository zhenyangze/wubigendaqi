#ifndef WFILEPIPI_H
#define WFILEPIPI_H

#include <QString>
#include <QStringList>
#include <QMap>
#include <QDateTime>
#include <QMapIterator>

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

    static int ukey; //唯一key 重复发文的key不一样
    static int index; //当前索引

    static bool isStart;//编辑是否开始
    static bool isEnd;//编辑是否结束
    static bool isPricatce;// 是否是练习模式，练习模式不保存结果， 可以前后翻页


    static int userTime; //用户练习时间
    static int userKeyDownNum; //用户按键次数
    static int userWordNum; //用户输入文字数量
    static int userDeleteNum; //用户回改数
    static QMap<int, int> userCorrectNum; //错误字数 //map保存每次的数量
    static QString userOldInput; //用户老的输入数据
    static QString userNewInput; //用户新的输入数据

    static double userSpeed; //用户打字速度
    static double correct_rate; //正确率
    static double key_per_second; //每秒按键
    static double key_per_word; //每字按键
    static double current_progress;//当前进度

    static void initUserInfo();

    static int getUserCorrectNum();
};

#endif // WFILEPIPI_H
