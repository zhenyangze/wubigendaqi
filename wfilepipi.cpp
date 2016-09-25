#include "wfilepipi.h"

QString WfilePipi::filePath = "";
QString WfilePipi::fileName = "";
QString WfilePipi::fileContents = "";
QString WfilePipi::contentType = "";
int WfilePipi::contentCount = 0;
QStringList WfilePipi::contentList = QStringList() << "";
bool WfilePipi::isLimit = false;
double WfilePipi::totalTime = 0;

int WfilePipi::ukey = 0;
int WfilePipi::index = 0;
bool WfilePipi::isStart =  false;
bool WfilePipi::isEnd = false;
bool WfilePipi::isPricatce = false;

int WfilePipi::userTime = 0;
int WfilePipi::userDeleteNum = 0;
int WfilePipi::userWordNum = 0;
int WfilePipi::userKeyDownNum = 0;
QMap<int, int> WfilePipi::userCorrectNum;
QString WfilePipi::userNewInput = "";
QString WfilePipi::userOldInput = "";

double WfilePipi::userSpeed = 0.00;
double WfilePipi::correct_rate = 0.00;
double WfilePipi::key_per_second = 0.00;
double WfilePipi::key_per_word = 0.00;
double WfilePipi::current_progress = 0.00;

WfilePipi::WfilePipi()
{

}

void WfilePipi::initUserInfo(){
    QDateTime dt = QDateTime::currentDateTime();

    WfilePipi::ukey = dt.toTime_t(); //唯一

    if (false == WfilePipi::isPricatce){
        WfilePipi::isEnd = false;
        WfilePipi::isStart = false;
    } else {
        WfilePipi::isEnd = true;
        WfilePipi::isStart = false;
    }


    WfilePipi::userTime = 0;

    WfilePipi::userTime = 0;
    WfilePipi::userDeleteNum = 0;
    WfilePipi::userWordNum = 0;
    WfilePipi::userKeyDownNum = 0;
    WfilePipi::userCorrectNum.clear();

    WfilePipi::userNewInput = "";
    WfilePipi::userOldInput = "";

    WfilePipi::userSpeed = 0.00;
    WfilePipi::correct_rate = 0.00;
    WfilePipi::key_per_second = 0.00;
    WfilePipi::key_per_word = 0.00;
    WfilePipi::current_progress = 0.00;
}

int WfilePipi::getUserCorrectNum(){
    int correctNum = 0;
    QMap<int, int> userCorrectList = WfilePipi::userCorrectNum;
    QMapIterator<int, int> it(userCorrectList);
    while(it.hasNext()){
        correctNum += it.next().value();
    }
    return correctNum;
}
