#pragma once

#include <iostream>
#include <string>

using namespace std;

class Passenger {
private:
    int id;
    double arrivalTime;
    double waitingTime;
    bool boarded;

public:
    Passenger(int id, double arrivalTime);
    int getId() const;
    double getArrivalTime() const;
    double getWaitingTime() const;
    void setBoardingTime(double boardingTime);
    bool hasBoarded() const;
};
