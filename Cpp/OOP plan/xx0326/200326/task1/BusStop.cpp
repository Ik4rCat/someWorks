#include <iostream>
#include <cstdlib>
#include <ctime>
#include "BusStop.h"

using namespace std;

BusStop::BusStop(string name, bool isFinalStop, double avgPassengerInterval, double avgMarshrutkaInterval) {
    this->name = name;
    this->isFinalStop = isFinalStop;
    this->avgPassengerInterval = avgPassengerInterval;
    this->avgMarshrutkaInterval = avgMarshrutkaInterval;
    this->currentTime = 0;
    this->maxPassengersAtStop = 0;
    this->passengerCounter = 0;
    this->marshrutkaCounter = 0;
    this->totalWaitingTime = 0;
    this->passengersServed = 0;
    
    srand(time(nullptr));
}

BusStop::~BusStop() {
    for (Passenger* p : allPassengers) {
        delete p;
    }
    for (Marshrutka* m : marshrutkas) {
        delete m;
    }
}

void BusStop::generatePassenger() {
    passengerCounter++;
    Passenger* passenger = new Passenger(passengerCounter, currentTime);
    passengerQueue.push(passenger);
    allPassengers.push_back(passenger);
    
    if (passengerQueue.size() > maxPassengersAtStop) {
        maxPassengersAtStop = passengerQueue.size();
    }
}

void BusStop::generateMarshrutka() {
    marshrutkaCounter++;
    Marshrutka* marshrutka = new Marshrutka(marshrutkaCounter, currentTime);
    marshrutkas.push_back(marshrutka);
    processMarshrutka(marshrutka);
}

void BusStop::processMarshrutka(Marshrutka* marshrutka) {
    while (!passengerQueue.empty() && marshrutka->hasFreeSeats()) {
        Passenger* passenger = passengerQueue.front();
        passengerQueue.pop();
        passenger->setBoardingTime(currentTime);
        marshrutka->boardPassenger();
        totalWaitingTime += passenger->getWaitingTime();
        passengersServed++;
    }
}

void BusStop::simulate(double simulationTime) {
    double nextPassengerTime = avgPassengerInterval;
    double nextMarshrutkaTime = avgMarshrutkaInterval;
    
    while (currentTime < simulationTime) {
        if (nextPassengerTime <= nextMarshrutkaTime) {
            currentTime = nextPassengerTime;
            generatePassenger();
            nextPassengerTime += avgPassengerInterval + (rand() % 10 - 5);
        } else {
            currentTime = nextMarshrutkaTime;
            generateMarshrutka();
            nextMarshrutkaTime += avgMarshrutkaInterval + (rand() % 10 - 5);
        }
    }
}

double BusStop::getAverageWaitingTime() const {
    if (passengersServed == 0) return 0;
    return totalWaitingTime / passengersServed;
}

double BusStop::getMaxPassengersAtStop() const {
    return maxPassengersAtStop;
}

int BusStop::getCurrentQueueSize() const {
    return passengerQueue.size();
}

void BusStop::setMaxPassengers(int max) {
    this->maxPassengersAtStop = max;
}

int BusStop::calculateRequiredInterval(int maxPassengers) const {
    if (avgPassengerInterval == 0) return 0;
    return (avgPassengerInterval * maxPassengers) + 5;
}

void BusStop::displayStatistics() const {
    cout << "\n===== BUS STOP STATISTICS: " << name << " =====" << endl;
    cout << "Stop type: " << (isFinalStop ? "Final" : "Intermediate") << endl;
    cout << "Total passengers arrived: " << passengerCounter << endl;
    cout << "Passengers served: " << passengersServed << endl;
    cout << "Current queue size: " << getCurrentQueueSize() << endl;
    cout << "Max passengers at stop: " << maxPassengersAtStop << endl;
    cout << "Average waiting time: " << getAverageWaitingTime() << " minutes" << endl;
    cout << "Required interval for max " << maxPassengersAtStop << " people: " 
         << calculateRequiredInterval(maxPassengersAtStop) << " minutes" << endl;
}
