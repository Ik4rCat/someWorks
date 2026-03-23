#pragma once

#include <iostream>
#include <string>

using namespace std;

class WallpaperRoll {
private:
    string name;
    double width;
    double length;
    double price;

public:
    WallpaperRoll();
    WallpaperRoll(string name, double width, double length, double price);
    string getName() const;
    double getWidth() const;
    double getLength() const;
    double getPrice() const;
    double getArea() const;
    void setName(string name);
    void setWidth(double width);
    void setLength(double length);
    void setPrice(double price);
};
