#ifndef WDB_H
#define WDB_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMap>
#include <QFile>
#include <QTextStream>
#include <QIODevice>
#include "wfilepipi.h"

class Wdb : public QObject
{
    Q_OBJECT
private:
    QSqlDatabase database;

public:
    explicit Wdb(QObject *parent = 0);
    bool connect(QString dbname);
    bool saveResult();

    bool createUserHistoryTable();

    void close();

signals:

public slots:
};

#endif // WDB_H
