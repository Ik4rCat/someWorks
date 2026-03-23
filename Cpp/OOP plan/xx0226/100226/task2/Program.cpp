#include <iostream>
#include "Apartment.h"
#include <limits>

using namespace std;

int main() {
    Apartment apartment;
    vector<WallpaperRoll> availableWallpapers;
    
    int numWallpaperTypes;
    cout << "Enter number of wallpaper types: ";
    cin >> numWallpaperTypes;
    
    for (int i = 0; i < numWallpaperTypes; i++) {
        string name;
        double width, length, price;
        
        cout << "\nWallpaper type " << (i + 1) << ":" << endl;
        cout << "  Name: ";
        cin >> name;
        cout << "  Width (m): ";
        cin >> width;
        cout << "  Length (m): ";
        cin >> length;
        cout << "  Price per roll ($): ";
        cin >> price;
        
        WallpaperRoll wallpaper(name, width, length, price);
        availableWallpapers.push_back(wallpaper);
    }
    
    int numRooms;
    cout << "\nEnter number of rooms: ";
    cin >> numRooms;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    for (int i = 0; i < numRooms; i++) {
        string name;
        double length, width, height;
        bool wallpaperCeiling;
        int wallpaperIndex;
        
        cout << "\nRoom " << (i + 1) << ":" << endl;
        cout << "  Name: ";
        getline(cin, name);
        cout << "  Length (m): ";
        cin >> length;
        cout << "  Width (m): ";
        cin >> width;
        cout << "  Height (m): ";
        cin >> height;
        cout << "  Wallpaper ceiling? (1-yes, 0-no): ";
        cin >> wallpaperCeiling;
        
        cout << "  Available wallpaper types:" << endl;
        for (size_t j = 0; j < availableWallpapers.size(); j++) {
            cout << "    " << (j + 1) << ". " << availableWallpapers[j].getName() << endl;
        }
        cout << "  Select wallpaper type (1-" << availableWallpapers.size() << "): ";
        cin >> wallpaperIndex;
        
        Room room(name, length, width, height, wallpaperCeiling, availableWallpapers[wallpaperIndex - 1]);
        apartment.addRoom(room);
    }
    
    apartment.displaySummary();
    
    return 0;
}