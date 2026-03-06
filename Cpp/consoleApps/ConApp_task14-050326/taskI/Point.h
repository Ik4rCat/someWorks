#pragma once

#include <iostream>

template <typename T>
class Point
{
private:
    T x;
    T y;
    T z;

public:
    Point() : x(T{}), y(T{}), z(T{}) {}

    Point(T xVal, T yVal, T zVal) : x(xVal), y(yVal), z(zVal) {}

    T getX() const { return x; }
    T getY() const { return y; }
    T getZ() const { return z; }

    void setX(T value) { x = value; }
    void setY(T value) { y = value; }
    void setZ(T value) { z = value; }

    void print() const
    {
        std::cout << "  Point(" << x << ", " << y << ", " << z << ")";
    }
};