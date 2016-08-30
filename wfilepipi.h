#ifndef WFILEPIPI_H
#define WFILEPIPI_H

#include <QString>
#include <QStringList>

class WfilePipi
{
public:
    WfilePipi();
    static QString filePath;
    static QString fileContents;
    static QStringList contentList;
    static double totalTime;
};

#endif // WFILEPIPI_H
