#include "wdb.h"

Wdb::Wdb(QObject *parent) : QObject(parent)
{

}
void Wdb::close(){
    if (this->database.isOpen()){
        this->database.close();
    }
}

bool Wdb::connect(QString dbname){
    this->database = QSqlDatabase::addDatabase("QSQLITE");
    this->database.setDatabaseName(dbname);

    if (!this->database.open()){
        return false;
    }
    //初始化数据
    this->createUserHistoryTable();

    return true;
}

//保存用户记录
bool Wdb::saveResult(){
    QSqlQuery sqlQuery;

    /*
id key
耗时 按键数 打字数 回改数 错误字数

打字速度  正确率 每秒按键 每字按键

类型 标题  当前段数  进度

插入时间
     */

    QString sql = "insert into wubi_user_record(ukey,  spend_time,  key_count,  word_count,  delete_count,  correct_count,  speed,  correct_rate,  key_per_second,  key_per_word,  type,  title,  current_position,  current_progress,  ctime) values(:ukey,  :spend_time,  :key_count,  :word_count,  :delete_count,  :correct_count,  :speed,  :correct_rate,  :key_per_second,  :key_per_word,  :type,  :title,  :current_position,  :current_progress,  :ctime);";

    sqlQuery.prepare(sql);
    sqlQuery.bindValue(":ukey", WfilePipi::ukey); //ukey
    sqlQuery.bindValue(":spend_time", WfilePipi::userTime); //耗时
    sqlQuery.bindValue(":key_count", WfilePipi::userKeyDownNum);  //按键数
    sqlQuery.bindValue(":word_count", WfilePipi::userWordNum); //打字数
    sqlQuery.bindValue(":delete_count", WfilePipi::userDeleteNum); //回改数
    sqlQuery.bindValue(":correct_count", WfilePipi::getUserCorrectNum()); //错误字数
    sqlQuery.bindValue(":speed", WfilePipi::userSpeed); //打字速度
    sqlQuery.bindValue(":correct_rate", WfilePipi::correct_rate);  //正确率
    sqlQuery.bindValue(":key_per_second", WfilePipi::key_per_second); //每秒按键
    sqlQuery.bindValue(":key_per_word", WfilePipi::key_per_word); //每字按键
    sqlQuery.bindValue(":type", WfilePipi::contentType); //类型
    sqlQuery.bindValue(":title", WfilePipi::fileName); //标题
    sqlQuery.bindValue(":current_position", WfilePipi::index - 1); //第几段
    sqlQuery.bindValue(":current_progress", WfilePipi::current_progress); //当前进度

    QDateTime dt = QDateTime::currentDateTime();
    sqlQuery.bindValue(":ctime", dt.toTime_t()); //插入时间

    if (sqlQuery.exec()){
        return true;
    } else {
        return false;
    }
}

//最近记录
QMap<int, double> Wdb::getRecentRecord(){
    QSqlQuery sqlQuery;
    QMap<int, double> recordList;

    int time;
    double speed;

    QString sql = "select ukey, speed from wubi_user_record group by ukey order by id desc limit 30;";
    sqlQuery.prepare(sql);
    if (sqlQuery.exec()){
        while(sqlQuery.next())
        {
            time = sqlQuery.value(0).toInt();
            speed = sqlQuery.value(1).toDouble();
            recordList.insert(time, speed);
        }
    }
    return recordList;
}

//最大速度
double Wdb::getMaxSpeed(){
    QSqlQuery sqlQuery;
    double maxSpeed = 0.00;
    QString sql = "select max(speed) from wubi_user_record limit 1;";
    sqlQuery.prepare(sql);
    if (sqlQuery.exec()){
        while(sqlQuery.next())
        {
            maxSpeed = sqlQuery.value(0).toDouble();
        }
    }

    return maxSpeed;
}

//花费时间
int Wdb::getSpeedTime(){
    QSqlQuery sqlQuery;
    int spendTime = 0;
    QString sql = "select max(spend_time) from wubi_user_record group by ukey;";
    sqlQuery.prepare(sql);
    if (sqlQuery.exec()){
        while(sqlQuery.next())
        {
            spendTime += sqlQuery.value(0).toInt();
        }
    }

    return spendTime;
}

//持续时间
int Wdb::getStraightDay(){
    QSqlQuery sqlQuery;
    int preCtime = 0;
    int currentCtime = 0;
    QList<QString> dateList;
    QString currentDate = "";
    QString sql = "select ctime,date(ctime, 'unixepoch', 'localtime') as cdate from wubi_user_record GROUP by ukey order by ctime desc limit 1000;";
    sqlQuery.prepare(sql);
    if (sqlQuery.exec()){
        while(sqlQuery.next())
        {
            currentCtime = sqlQuery.value(0).toInt();
            currentDate = sqlQuery.value(1).toString();

            if (preCtime == 0){
                preCtime = currentCtime;
            }

            //判断
            if ((preCtime - currentCtime) < 3600){
                if (dateList.indexOf(currentDate) < 0){
                    dateList << currentDate;
                }
            }
        }
    }

    return dateList.length();
}

//创建用户记录表
bool Wdb::createUserHistoryTable(){
    QSqlQuery sqlQuery;
    QFile file(":/source/data/db_user_record.txt");

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        return false;
    }

    QTextStream in(&file);
    QString  sql;

    while(!in.atEnd()){
        sql += in.readLine();
    }

    sqlQuery.prepare(sql);
    file.close();

    if (sqlQuery.exec()){
        return true;
    } else {
        return false;
    }
}
