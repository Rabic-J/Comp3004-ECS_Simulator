#include "floor.h"

Floor::Floor(int i){
    this->floorNumber=i;
    std::cout<<"Floor#"<<i<<" Initialized"<<std::endl;
}

void Floor::callElevator(int floorNum, int direction,ECS* system){
    cout<<"Floor "<<this->floorNumber<<" called an elevator"<<endl;
    system->elevatorRequests(floorNum,direction);
}

int Floor::getFloorNumber(){
    return floorNumber;
}
