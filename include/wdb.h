#ifndef WDB_H
#define WDB_H

#include <QSqlDatabase>

class Wdb : public QObject {
    Q_OBJECT

    private:
        QSqlDatabase database;

    public:
        explicit Wdb(QObject*parent = 0);

        bool connect(QString dbname);

        bool saveResult();

        QMap <int, double> getRecentRecord(); // 最近记录

        double getMaxSpeed(); // 获取最大speed

        int getSpeedTime(); // 获取练习时间

        int getStraightDay(); // 获取持续时间

        bool createUserHistoryTable();

        void close();

    signals:

    public slots:
};

#endif // WDB_H
