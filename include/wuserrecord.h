#ifndef WUSERRECORD_H
#define WUSERRECORD_H

#include <QWidget>

namespace Ui {

    class WUserRecord;

}

class WUserRecord : public QWidget {
    Q_OBJECT

    public:
        explicit WUserRecord(QWidget*parent = 0);

        ~WUserRecord();

        void showUserSpeed();

        void showUserMaxSpeed();

        void showUserSpendTime();

        void showUserStraightDay();

    private:
        Ui::WUserRecord*ui;
};

#endif // WUSERRECORD_H
