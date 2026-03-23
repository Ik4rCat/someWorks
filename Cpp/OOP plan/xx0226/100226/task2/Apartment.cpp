#include <iostream>
#include "Apartment.h"

using namespace std;

Apartment::Apartment() {
}

void Apartment::addRoom(Room room) {
    rooms.push_back(room);
}

int Apartment::getNumberOfRooms() const {
    return rooms.size();
}

Room Apartment::getRoom(int index) const {
    return rooms[index];
}

double Apartment::getTotalCost() const {
    double totalCost = 0.0;
    for (size_t i = 0; i < rooms.size(); i++) {
        WallpaperRoll wallpaper = rooms[i].getWallpaper();
        int requiredRolls = rooms[i].getRequiredRolls();
        totalCost += requiredRolls * wallpaper.getPrice();
    }
    return totalCost;
}

void Apartment::displaySummary() const {
    cout << "\n===== WALLPAPER PURCHASE SUMMARY =====" << endl;
    cout << "\nRequired rolls by room:" << endl;
    
    for (size_t i = 0; i < rooms.size(); i++) {
        Room room = rooms[i];
        WallpaperRoll wallpaper = room.getWallpaper();
        int requiredRolls = room.getRequiredRolls();
        
        cout << "  " << room.getName() << ": " 
             << requiredRolls << " rolls of " << wallpaper.getName() 
             << " ($" << (requiredRolls * wallpaper.getPrice()) << ")" << endl;
    }
    
    cout << "\nTotal cost: $" << getTotalCost() << endl;
}
