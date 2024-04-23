#ifndef FLOOR_H
#define FLOOR_H


#include <iostream>
#include <string>
#include "ecs.h"


using namespace std;

class Floor {
    public:
        Floor(int i);
        void callElevator(int floor, int direction,ECS* system); //signals to ecs to send elevator
        int getFloorNumber();//returns floor number

    private:
        int floorNumber;
};

#endif // FLOOR_H
