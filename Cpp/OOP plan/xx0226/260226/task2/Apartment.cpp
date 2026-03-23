#include <iostream>
#include "Apartment.h"

Apartment::Apartment() {
    number = 0;
    area = 0.0;
    residents = nullptr;
    residentCount = 0;
    maxResidents = 0;
}

Apartment::Apartment(int number, double area) {
    this->number = number;
    this->area = area;
    residents = nullptr;
    residentCount = 0;
    maxResidents = 0;
}

Apartment::Apartment(const Apartment& other) {
    this->number = other.number;
    this->area = other.area;
    this->residentCount = other.residentCount;
    this->maxResidents = other.maxResidents;
    
    if (other.residents != nullptr && maxResidents > 0) {
        residents = new Person[maxResidents];
        for (int i = 0; i < residentCount; i++) {
            residents[i] = other.residents[i];
        }
    } else {
        residents = nullptr;
    }
}

Apartment::Apartment(Apartment&& other) noexcept {
    number = other.number;
    area = other.area;
    residents = other.residents;
    residentCount = other.residentCount;
    maxResidents = other.maxResidents;
    
    other.residents = nullptr;
    other.number = 0;
    other.area = 0.0;
    other.residentCount = 0;
    other.maxResidents = 0;
}

Apartment::~Apartment() {
    delete[] residents;
}

int Apartment::getNumber() const {
    return number;
}

double Apartment::getArea() const {
    return area;
}

int Apartment::getResidentCount() const {
    return residentCount;
}

void Apartment::setNumber(int number) {
    this->number = number;
}

void Apartment::setArea(double area) {
    this->area = area;
}

void Apartment::addResident(const Person& person) {
    if (residentCount >= maxResidents) {
        int newMax = (maxResidents == 0) ? 1 : maxResidents * 2;
        Person* newResidents = new Person[newMax];
        for (int i = 0; i < residentCount; i++) {
            newResidents[i] = residents[i];
        }
        delete[] residents;
        residents = newResidents;
        maxResidents = newMax;
    }
    residents[residentCount] = person;
    residentCount++;
}

void Apartment::removeResident(int index) {
    if (index >= 0 && index < residentCount) {
        for (int i = index; i < residentCount - 1; i++) {
            residents[i] = residents[i + 1];
        }
        residentCount--;
    }
}

Person Apartment::getResident(int index) const {
    return residents[index];
}

void Apartment::display() const {
    cout << "Apartment #" << number << ", Area: " << area << " sq.m." << endl;
    cout << "Residents (" << residentCount << "):" << endl;
    for (int i = 0; i < residentCount; i++) {
        cout << "  ";
        residents[i].display();
        cout << endl;
    }
}

void Apartment::input() {
    cout << "Enter apartment number: ";
    cin >> number;
    cout << "Enter area: ";
    cin >> area;
    cin.ignore();
    
    int count;
    cout << "Enter number of residents: ";
    cin >> count;
    cin.ignore();
    
    for (int i = 0; i < count; i++) {
        cout << "Resident #" << (i + 1) << ":" << endl;
        Person person;
        person.input();
        addResident(person);
    }
}

Apartment& Apartment::operator=(const Apartment& other) {
    if (this != &other) {
        delete[] residents;
        number = other.number;
        area = other.area;
        residentCount = other.residentCount;
        maxResidents = other.maxResidents;
        
        if (other.residents != nullptr && maxResidents > 0) {
            residents = new Person[maxResidents];
            for (int i = 0; i < residentCount; i++) {
                residents[i] = other.residents[i];
            }
        } else {
            residents = nullptr;
        }
    }
    return *this;
}

Apartment& Apartment::operator=(Apartment&& other) noexcept {
    if (this != &other) {
        delete[] residents;
        number = other.number;
        area = other.area;
        residents = other.residents;
        residentCount = other.residentCount;
        maxResidents = other.maxResidents;
        
        other.residents = nullptr;
        other.number = 0;
        other.area = 0.0;
        other.residentCount = 0;
        other.maxResidents = 0;
    }
    return *this;
}
