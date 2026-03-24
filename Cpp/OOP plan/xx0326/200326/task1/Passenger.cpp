#include <iostream>
#include "Passenger.h"

using namespace std;

Passenger::Passenger(int id, double arrivalTime) {
    this->id = id;
    this->arrivalTime = arrivalTime;
    this->waitingTime = 0;
    this->boarded = false;
}

int Passenger::getId() const {
    return id;
}

double Passenger::getArrivalTime() const {
    return arrivalTime;
}

double Passenger::getWaitingTime() const {
    return waitingTime;
}

void Passenger::setBoardingTime(double boardingTime) {
    this->waitingTime = boardingTime - arrivalTime;
    this->boarded = true;
}

bool Passenger::hasBoarded() const {
    return boarded;
}
