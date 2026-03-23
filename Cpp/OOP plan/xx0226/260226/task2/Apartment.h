#pragma once

#include <iostream>
#include "Person.h"

using namespace std;

class Apartment {
private:
    int number;
    double area;
    Person* residents;
    int residentCount;
    int maxResidents;

public:
    Apartment();
    Apartment(int number, double area);
    Apartment(const Apartment& other);
    Apartment(Apartment&& other) noexcept;
    ~Apartment();
    
    int getNumber() const;
    double getArea() const;
    int getResidentCount() const;
    
    void setNumber(int number);
    void setArea(double area);
    
    void addResident(const Person& person);
    void removeResident(int index);
    Person getResident(int index) const;
    
    void display() const;
    void input();
    
    Apartment& operator=(const Apartment& other);
    Apartment& operator=(Apartment&& other) noexcept;
};
