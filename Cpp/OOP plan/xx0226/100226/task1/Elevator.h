#pragma once

#include <iostream>
using namespace std;

class Elevator {
private:
    int lowerFloor;
    int upperFloor;
    int currentFloor;
    bool isWorking;

public:
    Elevator();
    void setRange(int lower, int upper);
    void turnOn();
    void turnOff();
    bool getState() const;
    int getCurrentFloor() const;
    void callElevator(int floor);
};
