#ifndef PASSENGER_H
#define PASSENGER_H


#include <iostream>
#include <string>
#include "ecs.h"
#include "floor.h"
#include "elevator.h"



using namespace std;

class Passenger {

    public:
        Passenger(int i);
        void enterElevator(Elevator* el);//passenger enter a elevator updating the elevator object
        void exitElevator(Elevator* el);//passenger exits a elevator updating the elevator object
        void callButton(Floor* floor,int direction,ECS* system);//passenger signals to floor to call elevator
        void floorButton(Elevator* el,int selectedFloor); //passenger selects target floor once inelevator
        void openButton(Elevator* el);// signal to open the door
        void closeButton(Elevator* el);// signal to close door earlier
        void helpButton(ECS* esc, Elevator* el); // signal to ecs that the help is needed
        void fireButton(Elevator* el); // single to elevator that there is a fire

        //helper
        int getFloor();//returns passenger floor
        int getElevator(); //returnpassenger elevator id
        int getWeight();// returns passenger weigth


    private:
        int id;
        int weight; //this is for the elevator to check whether the total weight exceeds max capacity
        int floor;
        int elevator;

};

#endif // PASSENGER_H
