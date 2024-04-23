#include "ecs.h"
#include <iostream>
#include <cmath>
using namespace std;

ECS::ECS(){
    //Sets up elevators
    for(int i=0;i<ELEVATOR_COUNT;i++){
        elevators[i] = new Elevator(i+1);
    };
    std::cout<<"ECS Initialized"<<std::endl;

}

void ECS::elevatorRequests(int floorNum, int direction){
    int closest=0;
    for(int i=0;i<ELEVATOR_COUNT;i++){
        if(direction==UP&&elevators[i]->getDirection()==direction&&elevators[i]->getFloor()<floorNum){
            cout<<"1ECS requested elevator "<<i+1<<" to stop at floor "<<floorNum<<endl;
            elevators[i]->addStop(floorNum);
            return;
        }else if(direction==DOWN&&elevators[i]->getDirection()==direction&&elevators[i]->getFloor()>floorNum){
            cout<<"2ECS requested elevator "<<i+1<<" to stop at floor "<<floorNum<<endl;
            elevators[i]->addStop(floorNum);
            return;
        }else{
            if(abs(floorNum-elevators[i]->getFloor())<abs(floorNum-elevators[closest]->getFloor())){
                closest=i;
            }
        }
    }
    cout<<"3ECS requested elevator "<<closest+1<<" to stop at floor "<<floorNum<<endl;
    elevators[closest]->addStop(floorNum);
}

void ECS::help(int id){
    if(!elevators[id-1]->emergencyCall("Building Services")){
        elevators[id-1]->emergencyCall("911");
    }
}

void ECS::fire(){
    cout<<"FIRE"<<endl;
    for(int i=0;i<ELEVATOR_COUNT;i++){
        elevators[i]->moveToSafety("Fire");
    }
}

void ECS::powerOutage(){
    cout<<"POWER OUTAGE"<<endl;
    for(int i=0;i<ELEVATOR_COUNT;i++){
        elevators[i]->moveToSafety("Power Outage");
    }
}

Elevator* ECS::openElevator(int floorNum){
    for(int i=0;i<ELEVATOR_COUNT;i++){
        if(elevators[i]->getdoorOpen()&&(elevators[i]->getFloor()==floorNum)){
            return elevators[i];
        }
    }
    return nullptr;
}

Elevator* ECS::getElevator(int id){
    return elevators[id-1];
}
