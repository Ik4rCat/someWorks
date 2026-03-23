#include <iostream>
#include "ReservoirArray.h"

ReservoirArray::ReservoirArray() {
    reservoirs = nullptr;
    count = 0;
    maxSize = 0;
}

ReservoirArray::ReservoirArray(int size) {
    reservoirs = new Reservoir[size];
    count = 0;
    maxSize = size;
}

ReservoirArray::ReservoirArray(const ReservoirArray& other) {
    this->count = other.count;
    this->maxSize = other.maxSize;
    
    if (other.reservoirs != nullptr && maxSize > 0) {
        reservoirs = new Reservoir[maxSize];
        for (int i = 0; i < count; i++) {
            reservoirs[i] = other.reservoirs[i];
        }
    } else {
        reservoirs = nullptr;
    }
}

ReservoirArray::~ReservoirArray() {
    delete[] reservoirs;
}

void ReservoirArray::addReservoir(const Reservoir& reservoir) {
    if (count >= maxSize) {
        int newMax = (maxSize == 0) ? 1 : maxSize * 2;
        Reservoir* newReservoirs = new Reservoir[newMax];
        for (int i = 0; i < count; i++) {
            newReservoirs[i] = reservoirs[i];
        }
        delete[] reservoirs;
        reservoirs = newReservoirs;
        maxSize = newMax;
    }
    reservoirs[count] = reservoir;
    count++;
}

void ReservoirArray::removeReservoir(int index) {
    if (index >= 0 && index < count) {
        for (int i = index; i < count - 1; i++) {
            reservoirs[i] = reservoirs[i + 1];
        }
        count--;
    }
}

Reservoir ReservoirArray::getReservoir(int index) const {
    return reservoirs[index];
}

int ReservoirArray::getCount() const {
    return count;
}

void ReservoirArray::displayAll() const {
    cout << "\n===== ALL RESERVOIRS =====" << endl;
    cout << "Total: " << count << endl;
    for (int i = 0; i < count; i++) {
        cout << "\nReservoir #" << (i + 1) << ":" << endl;
        reservoirs[i].display();
    }
}

ReservoirArray& ReservoirArray::operator=(const ReservoirArray& other) {
    if (this != &other) {
        delete[] reservoirs;
        count = other.count;
        maxSize = other.maxSize;
        
        if (other.reservoirs != nullptr && maxSize > 0) {
            reservoirs = new Reservoir[maxSize];
            for (int i = 0; i < count; i++) {
                reservoirs[i] = other.reservoirs[i];
            }
        } else {
            reservoirs = nullptr;
        }
    }
    return *this;
}
