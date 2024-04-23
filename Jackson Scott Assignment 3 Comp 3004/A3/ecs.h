#ifndef ECS_H
#define ECS_H

#include "defs.h"
#include "elevator.h"

class ECS {

    public:
        ECS();
        void elevatorRequests(int floorNum, int direction); //sends elevator when called by floor determines which is closest or moveing in the same direction
        void help(int id); //passes the building serives number to the elvator emergncy call function, then 911 at failer
        void fire(); // tiggers the fire emergncy procedure in all elevators
        void powerOutage(); // tiggers the power out emergncy procedure in all elevators
        Elevator* openElevator(int floorNum); // doesnt open elevator returns the elavtor that in open on the passed floornum
        Elevator* getElevator(int id); //returns the elevator with the specific id

    private:
        Elevator* elevators[ELEVATOR_COUNT];
};

#endif // ECS_H
