#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "defs.h"
#include <QtCore>
#include <QTime>
#include <QCoreApplication>
#include <QObject>

class Elevator:public QObject{
    Q_OBJECT;
    public:
        Elevator(int i);
        //core functionality
        void addStop(int floor); //add to list of requests
        void removeStop(int floorNum); //remove from list of requests
        void Up(); // moves elevator up
        void Down(); //moves elevator down
        void stop(); // stops elevator
        void openDoor(); // opens elevator door
        void closeDoor(); // closes elevator door
        void run();
        void moveToSafety(std::string message); //moves elevator to safe floor

        //safety
        void Emergency(); //senses emergency and keeps door open
        void lightSensor(); //senses obstact and keeps door open
        void weightSensor(); //senses overload and keeps door open

        //communication
        void ring(); //prints ring sound
        void audioMessage(std::string message); // prints audio messages
        void displayMessage(std::string message); //prints display messages
        bool emergencyCall(std::string  phoneNum); // connects with passed phone number return true, not connect returns false


        //helper functions
        int getId(); // return elevator id
        int getFloor(); //returns elevator current floor
        int getDirection(); //returns current movement direction
        int getStopNum(); // returns the number of stops remaining
        bool getdoorOpen(); // returns whether or not elevator door is open
        int* getStops(); // returns pointer arry of stops
        void updateWeight(int w); // updates weight when passengers get on or off
        void setObstacle(); // set obstacle varbale true
        void timer(int t); // used for closing doors and recviving inputs while moving

    private:
        int id;
        int floor;
        int capacity;
        bool doorOpen;
        int direction;
        int stops[FLOOR_COUNT];
        int stopNum;
        int passengerWeight;
        bool obstacle;
        bool running;
        bool emergency;
};
#endif // ELEVATOR_H
