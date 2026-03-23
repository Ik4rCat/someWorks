#include <iostream>
#include "Overcoat.h"

using namespace std; 

Overcoat::Overcoat() {
    type = new char[1];
    type[0] = '\0';
    color = new char[1];
    color[0] = '\0';
    price = 0.0;
    size = 0;
}

Overcoat::Overcoat(const char* type, const char* color, double price, int size) {
    this->type = new char[strlen(type) + 1];
    strcpy(this->type, type);
    this->color = new char[strlen(color) + 1];
    strcpy(this->color, color);
    this->price = price;
    this->size = size;
}

Overcoat::Overcoat(const Overcoat& other) {
    this->type = new char[strlen(other.type) + 1];
    strcpy(this->type, other.type);
    this->color = new char[strlen(other.color) + 1];
    strcpy(this->color, other.color);
    this->price = other.price;
    this->size = other.size;
}

Overcoat::~Overcoat() {
    delete[] type;
    delete[] color;
}

const char* Overcoat::getType() const {
    return type;
}

const char* Overcoat::getColor() const {
    return color;
}

double Overcoat::getPrice() const {
    return price;
}

int Overcoat::getSize() const {
    return size;
}

void Overcoat::setType(const char* type) {
    delete[] this->type;
    this->type = new char[strlen(type) + 1];
    strcpy(this->type, type);
}

void Overcoat::setColor(const char* color) {
    delete[] this->color;
    this->color = new char[strlen(color) + 1];
    strcpy(this->color, color);
}

void Overcoat::setPrice(double price) {
    this->price = price;
}

void Overcoat::setSize(int size) {
    this->size = size;
}

bool Overcoat::operator==(const Overcoat& other) const {
    return strcmp(type, other.type) == 0;
}

bool Overcoat::operator>(const Overcoat& other) const {
    if (strcmp(type, other.type) == 0) {
        return price > other.price;
    }
    return false;
}

Overcoat& Overcoat::operator=(const Overcoat& other) {
    if (this != &other) {
        delete[] type;
        delete[] color;
        
        type = new char[strlen(other.type) + 1];
        strcpy(type, other.type);
        color = new char[strlen(other.color) + 1];
        strcpy(color, other.color);
        price = other.price;
        size = other.size;
    }
    return *this;
}

void Overcoat::display() const {
    cout << "Type: " << type << endl;
    cout << "Color: " << color << endl;
    cout << "Price: $" << price << endl;
    cout << "Size: " << size << endl;
}

void Overcoat::input() {
    char temp[100];
    
    cout << "Enter type: ";
    cin.getline(temp, 100);
    setType(temp);
    
    cout << "Enter color: ";
    cin.getline(temp, 100);
    setColor(temp);
    
    cout << "Enter price: ";
    cin >> price;
    cout << "Enter size: ";
    cin >> size;
    cin.ignore();
}
