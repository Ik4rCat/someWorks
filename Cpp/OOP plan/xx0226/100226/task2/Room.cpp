#include <iostream>
#include "Room.h"

Room::Room() {
    name = "Room";
    length = 5.0;
    width = 4.0;
    height = 2.7;
    wallpaperCeiling = false;
}

Room::Room(string name, double length, double width, double height, bool wallpaperCeiling, WallpaperRoll wallpaper) {
    this->name = name;
    this->length = length;
    this->width = width;
    this->height = height;
    this->wallpaperCeiling = wallpaperCeiling;
    this->wallpaper = wallpaper;
}

string Room::getName() const {
    return name;
}


WallpaperRoll Room::getWallpaper() const {
    return wallpaper;
}


double Room::getWallArea() const {
    return 2 * (length + width) * height;
}

double Room::getLength() const {
    return length;
}

double Room::getWidth() const {
    return width;
}

double Room::getHeight() const {
    return height;
}

double Room::getCeilingArea() const {
    return length * width;
}

double Room::getTotalArea() const {
    if (wallpaperCeiling) {
        return getWallArea() + getCeilingArea();
    }
    return getWallArea();
}


int Room::getRequiredRolls() const {
    double rollArea = wallpaper.getArea();
    int rolls = static_cast<int>(getTotalArea() / rollArea) + 1;
    return rolls;
}


bool Room::getWallpaperCeiling() const {
    return wallpaperCeiling;
}


void Room::setName(string name) {
    this->name = name;
}

void Room::setDimensions(double length, double width, double height) {
    this->length = length;
    this->width = width;
    this->height = height;
}

void Room::setWallpaperCeiling(bool wallpaperCeiling) {
    this->wallpaperCeiling = wallpaperCeiling;
}

void Room::setWallpaper(WallpaperRoll wallpaper) {
    this->wallpaper = wallpaper;
}