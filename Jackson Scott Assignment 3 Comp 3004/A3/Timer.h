#ifndef TIMER_H
#define TIMER_H
#include <QtCore>

class Timer: public QObject{

    Q_OBJECT

    public:
    Timer();
    QTimer *timer;

public slots:
    void myslot();
};

#endif // TIMER_H
