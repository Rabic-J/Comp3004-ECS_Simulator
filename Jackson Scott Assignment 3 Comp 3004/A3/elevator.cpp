#include "elevator.h"
#include <iostream>

using namespace std;

Elevator::Elevator(int i){
    this->id=i;
    this->floor=1;
    this->capacity=299;
    this->doorOpen=false;
    this->direction=0;
    this->stopNum=0;
    this->passengerWeight=0;
    this->obstacle=false;
    this->running=false;
    this->emergency=false;
    std::cout<<"Elevator Initialized ID#"<<i<<std::endl;
}

void Elevator::addStop(int floorNum){
    stops[floorNum-1]=1;
    stopNum=stopNum+1;
    cout<<"Elevator "<<this->id<<": Stop at floor "<<floorNum<<" added"<<endl;
    if(running==false){
        if(floorNum>floor) direction=UP;
        if(floorNum<floor) direction=DOWN;
        running=true;
        run();
    }
}

void Elevator::removeStop(int floorNum){
    stops[floorNum-1]=0;
    stopNum=stopNum-1;
    cout<<"Elevator "<<this->id<<": Stop at floor "<<floorNum<<" removed"<<endl;
    if(stopNum==0){
        direction=0;
        running=false;
    }
}

void Elevator::Up(){
    floor++;
    ring();
    cout<<"Elevator "<<id<<": Moved up 1 floor"<<endl;
    timer(2);
    displayMessage("Floor "+to_string(floor));
}

void Elevator::Down(){
    floor--;
    ring();
    cout<<"Elevator "<<id<<": Moved down 1 floor"<<endl;
    timer(2);
    displayMessage("Floor "+to_string(floor));
}

void Elevator::stop(){
    //add timer here
    cout<<"Elevator "<<id<<": Stopped"<<endl;
}

void Elevator::openDoor(){
    doorOpen=true;
    cout<<"Elevator "<<id<<": Door opened "<<floor<<endl;
    ring();
    timer(8);
    weightSensor();
    lightSensor();
    Emergency();
    closeDoor();
}

void Elevator::closeDoor(){
    if(doorOpen){
        doorOpen=false;
        timer(2);
        cout<<"Elevator "<<id<<": Door closed"<<endl;
        ring();
    }
}

void Elevator::run(){
    while(stopNum!=0){
        if(stops[floor-1]==1){
            stop();
            removeStop(floor);
            openDoor();
        }
        if(stopNum>0&&direction==DOWN&&floor==1){
            direction=UP;
        }else if(stopNum>0&&direction==UP&&floor==FLOOR_COUNT){
             direction=DOWN;
        }
        if(direction==UP){
            Up();
        }else if(direction==DOWN){
            Down();
        }
    }
}

void Elevator::moveToSafety(std::string message){

    displayMessage(message+" in the building moving to safe floor");
    audioMessage(message+" in the building moving to safe floor");
    stop();
    for(int i=0;i<FLOOR_COUNT;i++){
        stops[i]=0;
    }
    stopNum=0;
    direction=0;
    if(running==true){
        running=false;
        addStop(floor-2);
    }
    emergency=true;
}

void Elevator::Emergency(){
    while(passengerWeight>0&&emergency){
        displayMessage("Saftey hazard present please exit elevator");
        audioMessage("Saftey hazard present please exit elevator");
        timer(5);
    }
}

void Elevator::lightSensor(){
    int count=0;
    while(obstacle){
        displayMessage("Obstacle present please remove");
        if(count>3){
            audioMessage("Obstacle present please remove");
        }
        count++;
        timer(5);
    }
}

void Elevator::weightSensor(){
    int count=0;
    while(passengerWeight>capacity){
        displayMessage("Weight capacity met please disembark");
        if(count>3){
            audioMessage("Weight capacity met please disembark");
        }
        count++;
        timer(5);
    }
}

void Elevator::ring(){
    cout<<"Elevator "<<id<<": **RING**"<<endl;
}

void Elevator::audioMessage(std::string message){
    cout<<"Elevator "<<id<<" Audio: "<<message<<endl;
}

void Elevator::displayMessage(std::string message){
    cout<<"Elevator "<<id<<" Display: "<<message<<endl;
}

bool Elevator::emergencyCall(std::string phoneNum){
    displayMessage("Calling "+phoneNum);
    timer(10);
    if(phoneNum!="911") {
        displayMessage("Failed to connect "+phoneNum);
        return false;
    }else{
        displayMessage("Connected to "+phoneNum);
        return true;
    }
}

int Elevator::getId(){
    return id;
}

int Elevator::getFloor(){
    return floor;
}

int Elevator::getDirection(){
    return direction;
}

int Elevator::getStopNum(){
    return stopNum;
}

bool Elevator::getdoorOpen(){
    return doorOpen;
}

int* Elevator::getStops(){
    return stops;
}

void Elevator::updateWeight(int w){
    passengerWeight=passengerWeight+w;
    weightSensor();
}

void Elevator::setObstacle(){
    obstacle=!obstacle;
}

void Elevator::timer(int t){
    QTime dieTime = QTime::currentTime().addSecs(t);
    while(QTime::currentTime()<dieTime){
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    }
}



