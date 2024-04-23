#include "passenger.h"

Passenger::Passenger(int i){
  this->id=i;
  this->weight=100;
  this->floor=1;
  this->elevator=0;
  std::cout<<"Passenger #"<<i<<" Initialized"<<std::endl;
};

void Passenger::enterElevator(Elevator* el){
    if(el==nullptr){
        cout<<"No open elevator to enter on floor "<<floor<<endl;
    }else{
        elevator=el->getId();
        cout<<"Passenger # "<<id<<" entered elevator "<<el->getId()<<endl;
        el->updateWeight(weight);
    }
}

void Passenger::exitElevator(Elevator* el){
    if(elevator==0){
        cout<<"Passenger # "<<id<<" not in a elevator"<<endl;
    }else if(!el->getdoorOpen()){
        cout<<"Passenger # "<<id<<" elevator door not open"<<endl;
    }else{
        cout<<"Passenger # "<<id<<" exited elevator "<<elevator<<" to floor "<<el->getFloor()<<endl;
        floor=el->getFloor();
        elevator=0;
        el->updateWeight(-weight);
    }
}

void Passenger::callButton(Floor* floor,int direction,ECS* system){
    std::cout<<"Passenger "<<this->id<<" pressed the called button  on floor "<<floor->getFloorNumber()<<std::endl;
    floor->callElevator(floor->getFloorNumber(), direction,system);
}

void Passenger::floorButton(Elevator* el, int selectedFloor){
    if(elevator==0){
        cout<<"Passenger # "<<id<<" not in a elevator"<<endl;
    }else{
        el->addStop(selectedFloor+1);
    }
}

void Passenger::openButton(Elevator* el){
    if(elevator==0){
        cout<<"Passenger # "<<id<<" not in a elevator"<<endl;
    }else{
        el->openDoor();
    }

}

void Passenger::closeButton(Elevator* el){
    if(elevator==0){
        cout<<"Passenger # "<<id<<" not in a elevator"<<endl;
    }else{
        el->closeDoor();
    }
}

void Passenger::helpButton(ECS* ecs,Elevator* el){
    if(elevator==0){
        cout<<"Passenger # "<<id<<" not in a elevator"<<endl;
    }else{
        ecs->help(el->getId());
    }
}

void Passenger::fireButton(Elevator* el){
    el->moveToSafety("Fire");
}

int Passenger::getFloor(){
    return floor;
}

int Passenger::getElevator(){
    return elevator;
}

int Passenger::getWeight(){
    return weight;
}
