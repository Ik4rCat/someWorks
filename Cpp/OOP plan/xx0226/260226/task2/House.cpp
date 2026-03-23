#include <iostream>
#include "House.h"
#include <cstring>

House::House() {
    address = new char[1];
    address[0] = '\0';
    apartments = nullptr;
    apartmentCount = 0;
    maxApartments = 0;
}

House::House(const char* address) {
    this->address = new char[strlen(address) + 1];
    strcpy(this->address, address);
    apartments = nullptr;
    apartmentCount = 0;
    maxApartments = 0;
}

House::House(const House& other) {
    this->address = new char[strlen(other.address) + 1];
    strcpy(this->address, other.address);
    this->apartmentCount = other.apartmentCount;
    this->maxApartments = other.maxApartments;
    
    if (other.apartments != nullptr && maxApartments > 0) {
        apartments = new Apartment[maxApartments];
        for (int i = 0; i < apartmentCount; i++) {
            apartments[i] = other.apartments[i];
        }
    } else {
        apartments = nullptr;
    }
}

House::House(House&& other) noexcept {
    address = other.address;
    apartments = other.apartments;
    apartmentCount = other.apartmentCount;
    maxApartments = other.maxApartments;
    
    other.address = nullptr;
    other.apartments = nullptr;
    other.apartmentCount = 0;
    other.maxApartments = 0;
}

House::~House() {
    delete[] address;
    delete[] apartments;
}

const char* House::getAddress() const {
    return address;
}

int House::getApartmentCount() const {
    return apartmentCount;
}

void House::setAddress(const char* address) {
    delete[] this->address;
    this->address = new char[strlen(address) + 1];
    strcpy(this->address, address);
}

void House::addApartment(const Apartment& apartment) {
    if (apartmentCount >= maxApartments) {
        int newMax = (maxApartments == 0) ? 1 : maxApartments * 2;
        Apartment* newApartments = new Apartment[newMax];
        for (int i = 0; i < apartmentCount; i++) {
            newApartments[i] = apartments[i];
        }
        delete[] apartments;
        apartments = newApartments;
        maxApartments = newMax;
    }
    apartments[apartmentCount] = apartment;
    apartmentCount++;
}

void House::removeApartment(int index) {
    if (index >= 0 && index < apartmentCount) {
        for (int i = index; i < apartmentCount - 1; i++) {
            apartments[i] = apartments[i + 1];
        }
        apartmentCount--;
    }
}

Apartment House::getApartment(int index) const {
    return apartments[index];
}

void House::display() const {
    cout << "\n===== HOUSE: " << address << " =====" << endl;
    cout << "Total apartments: " << apartmentCount << endl;
    for (int i = 0; i < apartmentCount; i++) {
        cout << "\nApartment #" << (i + 1) << ":" << endl;
        apartments[i].display();
    }
}

void House::input() {
    char temp[200];
    cout << "Enter house address: ";
    cin.getline(temp, 200);
    setAddress(temp);
    
    int count;
    cout << "Enter number of apartments: ";
    cin >> count;
    cin.ignore();
    
    for (int i = 0; i < count; i++) {
        cout << "\nApartment #" << (i + 1) << ":" << endl;
        Apartment apt;
        apt.input();
        addApartment(apt);
    }
}

House& House::operator=(const House& other) {
    if (this != &other) {
        delete[] address;
        delete[] apartments;
        
        address = new char[strlen(other.address) + 1];
        strcpy(address, other.address);
        apartmentCount = other.apartmentCount;
        maxApartments = other.maxApartments;
        
        if (other.apartments != nullptr && maxApartments > 0) {
            apartments = new Apartment[maxApartments];
            for (int i = 0; i < apartmentCount; i++) {
                apartments[i] = other.apartments[i];
            }
        } else {
            apartments = nullptr;
        }
    }
    return *this;
}

House& House::operator=(House&& other) noexcept {
    if (this != &other) {
        delete[] address;
        delete[] apartments;
        
        address = other.address;
        apartments = other.apartments;
        apartmentCount = other.apartmentCount;
        maxApartments = other.maxApartments;
        
        other.address = nullptr;
        other.apartments = nullptr;
        other.apartmentCount = 0;
        other.maxApartments = 0;
    }
    return *this;
}
