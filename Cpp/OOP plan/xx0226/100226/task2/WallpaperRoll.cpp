#include <iostream>
#include "WallpaperRoll.h"

using namespace std;

WallpaperRoll::WallpaperRoll() {
    name = "Default";
    width = 0.53;
    length = 10.0;
    price = 500.0;
}

WallpaperRoll::WallpaperRoll(string name, double width, double length, double price) {
    this->name = name;
    this->width = width;
    this->length = length;
    this->price = price;
}

string WallpaperRoll::getName() const {
    return name;
}

double WallpaperRoll::getWidth() const {
    return width;
}

double WallpaperRoll::getLength() const {
    return length;
}

double WallpaperRoll::getPrice() const {
    return price;
}

double WallpaperRoll::getArea() const {
    return width * length;
}

void WallpaperRoll::setName(string name) {
    this->name = name;
}

void WallpaperRoll::setWidth(double width) {
    this->width = width;
}

void WallpaperRoll::setLength(double length) {
    this->length = length;
}

void WallpaperRoll::setPrice(double price) {
    this->price = price;
}
