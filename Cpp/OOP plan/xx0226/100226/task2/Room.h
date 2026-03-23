#pragma once

#include <iostream>
#include <string>
#include "WallpaperRoll.h"

using namespace std;

class Room {
private:
    string name;
    double length;
    double width;
    double height;
    bool wallpaperCeiling;
    WallpaperRoll wallpaper;

public:
    Room();
    Room(string name, double length, double width, double height, bool wallpaperCeiling, WallpaperRoll wallpaper);
    
    string getName() const;
    
    WallpaperRoll getWallpaper() const;
    
    double getLength() const;
    double getWidth() const;
    double getHeight() const;
    double getWallArea() const;
    double getCeilingArea() const;
    double getTotalArea() const;
    
    int getRequiredRolls() const;

    bool getWallpaperCeiling() const;

    void setName(string name);
    void setDimensions(double length, double width, double height);
    void setWallpaperCeiling(bool wallpaperCeiling);
    void setWallpaper(WallpaperRoll wallpaper);
};
