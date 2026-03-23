#include <iostream>
#include "Elevator.h"

Elevator::Elevator() {
    lowerFloor = 1;
    upperFloor = 10;
    currentFloor = 1;
    isWorking = false;
}

void Elevator::setRange(int lower, int upper) {
    lowerFloor = lower;
    upperFloor = upper;
    if (currentFloor < lowerFloor) {
        currentFloor = lowerFloor;
    }
    if (currentFloor > upperFloor) {
        currentFloor = upperFloor;
    }
}

void Elevator::turnOn() {
    isWorking = true;
}

void Elevator::turnOff() {
    isWorking = false;
}

bool Elevator::getState() const {
    return isWorking;
}

int Elevator::getCurrentFloor() const {
    return currentFloor;
}

void Elevator::callElevator(int floor) {
    if (!isWorking) {
        cout << "Elevator is not working" << endl;
        return;
    }
    if (floor < lowerFloor || floor > upperFloor) {
        cout << "Floor " << floor << " is out of range" << endl;
        return;
    }
    currentFloor = floor;
    cout << "Elevator moved to floor " << currentFloor << endl;
}