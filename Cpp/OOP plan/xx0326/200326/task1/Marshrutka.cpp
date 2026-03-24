#include <iostream>
#include "Marshrutka.h"

using namespace std;

Marshrutka::Marshrutka(int id, double arrivalTime, int maxCapacity) {
    this->id = id;
    this->arrivalTime = arrivalTime;
    this->capacity = maxCapacity;
    this->freeSeats = rand() % (maxCapacity / 2) + maxCapacity / 2;
}

int Marshrutka::getId() const {
    return id;
}

double Marshrutka::getArrivalTime() const {
    return arrivalTime;
}

int Marshrutka::getFreeSeats() const {
    return freeSeats;
}

int Marshrutka::getCapacity() const {
    return capacity;
}

void Marshrutka::boardPassenger() {
    if (freeSeats > 0) {
        freeSeats--;
    }
}

bool Marshrutka::hasFreeSeats() const {
    return freeSeats > 0;
}
