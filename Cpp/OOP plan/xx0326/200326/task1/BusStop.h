#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include "Passenger.h"
#include "Marshrutka.h"

using namespace std;

class BusStop {
private:
    string name;
    bool isFinalStop;
    queue<Passenger*> passengerQueue;
    vector<Passenger*> allPassengers;
    vector<Marshrutka*> marshrutkas;
    
    double avgPassengerInterval;
    double avgMarshrutkaInterval;
    double currentTime;
    int maxPassengersAtStop;
    
    int passengerCounter;
    int marshrutkaCounter;
    
    double totalWaitingTime;
    int passengersServed;

public:
    BusStop(string name, bool isFinalStop, double avgPassengerInterval, double avgMarshrutkaInterval);
    ~BusStop();
    
    void simulate(double simulationTime);
    void generatePassenger();
    void generateMarshrutka();
    void processMarshrutka(Marshrutka* marshrutka);
    
    double getAverageWaitingTime() const;
    double getMaxPassengersAtStop() const;
    int getCurrentQueueSize() const;
    
    void setMaxPassengers(int max);
    int calculateRequiredInterval(int maxPassengers) const;
    
    void displayStatistics() const;
};
