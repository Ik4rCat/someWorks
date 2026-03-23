#pragma once

#include <iostream>
#include "Apartment.h"

using namespace std;

class House {
private:
    char* address;
    Apartment* apartments;
    int apartmentCount;
    int maxApartments;

public:
    House();
    explicit House(const char* address);
    House(const House& other);
    House(House&& other) noexcept;
    ~House();
    
    const char* getAddress() const;
    int getApartmentCount() const;
    
    void setAddress(const char* address);
    
    void addApartment(const Apartment& apartment);
    void removeApartment(int index);
    Apartment getApartment(int index) const;
    
    void display() const;
    void input();
    
    House& operator=(const House& other);
    House& operator=(House&& other) noexcept;
};
