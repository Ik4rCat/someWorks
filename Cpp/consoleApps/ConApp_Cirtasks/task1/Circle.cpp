#include <iostream>
#include "Circle.h"

using namespace std;

const float PI = 3.14159265358979323846f;

Circle::Circle(float r) : radius(r >= 0 ? r : 0) {}

float Circle::getRadius() const {
    return radius;
}

float Circle::getLength() const {
    return 2 * PI * radius;
}

bool Circle::operator==(const Circle& other) const {
    float diff = radius - other.radius;
    return (diff < 0 ? -diff : diff) < 0.0001f;
}

bool Circle::operator>(const Circle& other) const {
    return getLength() > other.getLength();
}

Circle& Circle::operator+=(float value) {
    radius += value;
    if (radius < 0) radius = 0;
    return *this;
}

Circle& Circle::operator-=(float value) {
    radius -= value;
    if (radius < 0) radius = 0;
    return *this;
}

void Circle::display() const {
    cout << "Circle: radius = " << radius 
         << ", length = " << getLength() << endl;
}
