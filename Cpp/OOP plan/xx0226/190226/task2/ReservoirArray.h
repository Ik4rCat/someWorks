#pragma once

#include <iostream>
#include "Reservoir.h"

class ReservoirArray {
private:
    Reservoir* reservoirs;
    int count;
    int maxSize;

public:
    ReservoirArray();
    explicit ReservoirArray(int size);
    ReservoirArray(const ReservoirArray& other);
    ~ReservoirArray();
    
    void addReservoir(const Reservoir& reservoir);
    void removeReservoir(int index);
    Reservoir getReservoir(int index) const;
    int getCount() const;
    
    void displayAll() const;
    
    ReservoirArray& operator=(const ReservoirArray& other);
};
