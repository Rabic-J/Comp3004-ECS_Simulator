#include "Timer.h"
#include <QtDebug>
#include <QtCore>
Timer::Timer(){
    timer= new QTimer(this);
}
