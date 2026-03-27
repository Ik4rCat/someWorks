#pragma once
    
 #include <iostream>

class Point {
private:
    double x;
    double y;
    
public:
    Point(double xVal, double yVal);
    ~Point();
    
    void show() const;
};

#include "Point.inl"
