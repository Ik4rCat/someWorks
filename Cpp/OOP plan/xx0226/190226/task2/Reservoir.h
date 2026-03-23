#pragma once

#include <iostream>
#include <cstring>

using namespace std;

class Reservoir {
private:
    char* name;
    char* type;
    double width;
    double length;
    double maxDepth;

public:
    Reservoir();
    explicit Reservoir(const char* name);
    Reservoir(const char* name, const char* type, double width, double length, double maxDepth);
    Reservoir(const Reservoir& other);
    ~Reservoir();
    
    const char* getName() const;
    const char* getType() const;
    
    double getWidth() const;
    double getLength() const;
    double getMaxDepth() const;
    
    void setName(const char* name);
    void setType(const char* type);
    void setWidth(double width);
    void setLength(double length);
    void setMaxDepth(double maxDepth);
    
    double getVolume() const;
    double getSurfaceArea() const;
    
    bool isSameType(const Reservoir& other) const;
    bool compareSurfaceArea(const Reservoir& other) const;
    
    void display() const;
    void input();
    
    Reservoir& operator=(const Reservoir& other);
};
