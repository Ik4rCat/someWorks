#pragma once

#include <iostream>
#include <cstdlib>

using namespace std;

class Marshrutka {
private:
    int id;
    double arrivalTime;
    int freeSeats;
    int capacity;

public:
    Marshrutka(int id, double arrivalTime, int maxCapacity = 15);
    int getId() const;
    double getArrivalTime() const;
    int getFreeSeats() const;
    int getCapacity() const;
    void boardPassenger();
    bool hasFreeSeats() const;
};
