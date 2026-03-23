#pragma once

#include <iostream>
#include <cstring>

using namespace std;

class Overcoat {
private:
    char* type;
    char* color;
    double price;
    int size;

public:
    Overcoat();
    Overcoat(const char* type, const char* color, double price, int size);
    Overcoat(const Overcoat& other);
    ~Overcoat();
    
    const char* getType() const;
    const char* getColor() const;
    double getPrice() const;
    int getSize() const;
    
    void setType(const char* type);
    void setColor(const char* color);
    void setPrice(double price);
    void setSize(int size);
    
    bool operator==(const Overcoat& other) const;
    bool operator>(const Overcoat& other) const;
    Overcoat& operator=(const Overcoat& other);
    
    void display() const;
    void input();
};
