#include <iostream>
#include "Elevator.h"

using namespace std;

int main() {
    Elevator elevator;
    
    elevator.setRange(1, 15);
    elevator.turnOn();
    
    cout << "Elevator working: " << (elevator.getState() ? "Yes" : "No") << endl;
    cout << "Current floor: " << elevator.getCurrentFloor() << endl;
    
    elevator.callElevator(5);
    elevator.callElevator(10);
    elevator.callElevator(20);
    
    elevator.turnOff();
    cout << "Elevator working: " << (elevator.getState() ? "Yes" : "No") << endl;
    
    return 0;
}