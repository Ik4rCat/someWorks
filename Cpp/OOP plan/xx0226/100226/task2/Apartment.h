#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "Room.h"
#include "WallpaperRoll.h"

using namespace std;

class Apartment {
private:
    vector<Room> rooms;

public:
    Apartment();
    void addRoom(Room room);
    int getNumberOfRooms() const;
    Room getRoom(int index) const;
    double getTotalCost() const;
    void displaySummary() const;
};
