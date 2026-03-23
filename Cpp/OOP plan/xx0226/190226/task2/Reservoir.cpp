#include <iostream>
#include "Reservoir.h"

using namespace std;

Reservoir::Reservoir() {
    name = new char[1];
    name[0] = '\0';
    type = new char[1];
    type[0] = '\0';
    width = 0.0;
    length = 0.0;
    maxDepth = 0.0;
}

Reservoir::Reservoir(const char* name) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    type = new char[1];
    type[0] = '\0';
    width = 0.0;
    length = 0.0;
    maxDepth = 0.0;
}

Reservoir::Reservoir(const char* name, const char* type, double width, double length, double maxDepth) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->type = new char[strlen(type) + 1];
    strcpy(this->type, type);
    this->width = width;
    this->length = length;
    this->maxDepth = maxDepth;
}

Reservoir::Reservoir(const Reservoir& other) {
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);
    this->type = new char[strlen(other.type) + 1];
    strcpy(this->type, other.type);
    this->width = other.width;
    this->length = other.length;
    this->maxDepth = other.maxDepth;
}

Reservoir::~Reservoir() {
    delete[] name;
    delete[] type;
}

const char* Reservoir::getName() const {
    return name;
}

const char* Reservoir::getType() const {
    return type;
}

double Reservoir::getWidth() const {
    return width;
}

double Reservoir::getLength() const {
    return length;
}

double Reservoir::getMaxDepth() const {
    return maxDepth;
}

void Reservoir::setName(const char* name) {
    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

void Reservoir::setType(const char* type) {
    delete[] this->type;
    this->type = new char[strlen(type) + 1];
    strcpy(this->type, type);
}

void Reservoir::setWidth(double width) {
    this->width = width;
}

void Reservoir::setLength(double length) {
    this->length = length;
}

void Reservoir::setMaxDepth(double maxDepth) {
    this->maxDepth = maxDepth;
}

double Reservoir::getVolume() const {
    return width * length * maxDepth;
}

double Reservoir::getSurfaceArea() const {
    return width * length;
}

bool Reservoir::isSameType(const Reservoir& other) const {
    return strcmp(type, other.type) == 0;
}

bool Reservoir::compareSurfaceArea(const Reservoir& other) const {
    return getSurfaceArea() > other.getSurfaceArea();
}

void Reservoir::display() const {
    cout << "Name: " << name << endl;
    cout << "Type: " << type << endl;
    cout << "Dimensions: " << width << "m x " << length << "m x " << maxDepth << "m" << endl;
    cout << "Volume: " << getVolume() << " cubic meters" << endl;
    cout << "Surface Area: " << getSurfaceArea() << " sq.m." << endl;
}

void Reservoir::input() {
    char temp[100];
    
    cout << "Enter name: ";
    cin.getline(temp, 100);
    setName(temp);
    
    cout << "Enter type (sea/lake/pond/pool): ";
    cin.getline(temp, 100);
    setType(temp);
    
    cout << "Enter width (m): ";
    cin >> width;
    cout << "Enter length (m): ";
    cin >> length;
    cout << "Enter max depth (m): ";
    cin >> maxDepth;
    cin.ignore();
}

Reservoir& Reservoir::operator=(const Reservoir& other) {
    if (this != &other) {
        delete[] name;
        delete[] type;
        
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        type = new char[strlen(other.type) + 1];
        strcpy(type, other.type);
        width = other.width;
        length = other.length;
        maxDepth = other.maxDepth;
    }
    return *this;
}
