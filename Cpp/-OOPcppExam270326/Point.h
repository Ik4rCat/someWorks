#pragma once
    
 #include <iostream>

class Point {
private:
    double x;
    double y;
    static int count;
    
public:
    Point();
    Point(double xVal, double yVal);
    ~Point();
    
    void show() const;

    friend std::ostream& operator<<(std::ostream& os, const Point& p);
};

#include "Point.inl"
