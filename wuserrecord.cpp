#include "wuserrecord.h"
#include "ui_wuserrecord.h"

WUserRecord::WUserRecord(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WUserRecord)
{
    ui->setupUi(this);
    this->setWindowTitle("用户记录");

    this->showUserSpeed();
    this->showUserMaxSpeed();
    this->showUserSpendTime();
    this->showUserStraightDay();
}

WUserRecord::~WUserRecord()
{
    delete ui;
}

void WUserRecord::showUserSpeed(){
    double minx = 0.0;
    double miny = 0.0;
    double maxx = 0.0;
    double maxy = 0.0;
    // set locale to english, so we get english month names:
    ui->widget->setLocale(QLocale(QLocale::Chinese, QLocale::China));
    // create multiple graphs:

    for (int gi=0; gi<1; ++gi)
    {
      ui->widget->addGraph();
      QColor color(20+200/4.0*gi,70*(1.6-gi/4.0), 150, 150);
      ui->widget->graph()->setLineStyle(QCPGraph::lsLine);
      ui->widget->graph()->setPen(QPen(color.lighter(200)));
      ui->widget->graph()->setBrush(QBrush(color));
      // generate random walk data:
      Wdb *db = new Wdb();
      QMap<int, double> recordList = db->getRecentRecord();
      QVector<QCPGraphData> timeData(recordList.count());


      QMap<int, double>::iterator it;
      double time;
      double speed;
      int i = 0;
      for(it = recordList.begin(); it != recordList.end(); ++it){
          time = (double)it.key();
          speed = it.value();

          timeData[i].key = time;
          timeData[i].value = speed;

          if (minx <= 0){
              minx = time;
          }

          if (miny <= 0){
              miny = speed;
          }

          if(time < minx){
              minx = time;
          }
          if (time > maxx){
              maxx = time;
          }

          if (speed < miny){
              miny = speed;
          }

          if (speed > maxy){
              maxy = speed;
          }

          i++;
      }
      ui->widget->graph()->data()->set(timeData);
    }
    // configure bottom axis to show date instead of number:
    QSharedPointer<QCPAxisTickerDateTime> dateTicker(new QCPAxisTickerDateTime);
    dateTicker->setDateTimeFormat("MM/dd");
    ui->widget->xAxis->setTicker(dateTicker);
    // configure left axis text labels:


    // set axis ranges to show all data:
    if (maxx <= 0){
        double now = QDateTime::currentDateTime().toTime_t();
        minx = now;
        maxx = now + 3600 * 5;
    }

    if (maxy <= 0){
        maxy = 150;
    }
    ui->widget->xAxis->setRange(minx - 3800, maxx + 3800);
    ui->widget->yAxis->setRange(miny, maxy);

}

void WUserRecord::showUserMaxSpeed(){
    Wdb *db = new Wdb();
    double speed = db->getMaxSpeed();
    ui->label_speed->setText(QString::number(speed));
}

void WUserRecord::showUserSpendTime(){
    Wdb *db = new Wdb();
    int time = db->getSpeedTime();
    int day = (int)(time / (3600 * 24));
    int hour = (int)((time / 3600)) % 24;
    int minute = (int)(time / 60) % 60;

    QString showInfo = "";
    if(day > 0){
        showInfo += QString::number(day) + "天";
    }
    if(hour > 0){
        showInfo += QString::number(hour) + "小时";
    }
    if(minute > 0){
        showInfo += QString::number(minute) + "分钟";
    }
    if (showInfo.length() == 0){
        showInfo = "0";
    }
    ui->label_time->setText(showInfo);
}

void WUserRecord::showUserStraightDay(){
    Wdb *db = new Wdb();
    int day = db->getStraightDay();
    ui->label_day->setText(QString::number(day));
}
