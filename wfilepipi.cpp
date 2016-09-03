#include "wfilepipi.h"

QString WfilePipi::filePath = "";
QString WfilePipi::fileName = "";
QString WfilePipi::fileContents = "";
QString WfilePipi::contentType = "";
int WfilePipi::contentCount = 0;
QStringList WfilePipi::contentList = QStringList() << "";
bool WfilePipi::isLimit = false;
double WfilePipi::totalTime = 0;

int WfilePipi::index = 0;
bool WfilePipi::isStart =  false;
bool WfilePipi::isEnd = false;

int WfilePipi::userTime = 0;
int WfilePipi::userDeleteNum = 0;
int WfilePipi::userWordNum = 0;
int WfilePipi::userKeyDownNum = 0;
QMap<int, int> WfilePipi::userCorrectNum;
QString WfilePipi::userNewInput = "";
QString WfilePipi::userOldInput = "";

WfilePipi::WfilePipi()
{

}

void WfilePipi::initUserInfo(){
    WfilePipi::isEnd = false;
    WfilePipi::isStart = false;
    WfilePipi::userTime = 0;

    WfilePipi::userTime = 0;
    WfilePipi::userDeleteNum = 0;
    WfilePipi::userWordNum = 0;
    WfilePipi::userKeyDownNum = 0;
    WfilePipi::userCorrectNum.clear();

    WfilePipi::userNewInput = "";
    WfilePipi::userOldInput = "";
}
