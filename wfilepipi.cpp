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

WfilePipi::WfilePipi()
{

}
