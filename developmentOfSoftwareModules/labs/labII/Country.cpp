#include <iostream>
#include "Country.h"


Country::Country() : name(nullptr), citizens(0), president(nullptr) {
    std::cout << "Default constructor called for object at " << this << std::endl;
}

Country::Country(char* n, int c, char* p)
    : name(nullptr), citizens(c), president(nullptr) {

    if (n) {
        int len = 0;
        while (n[len] != '\0') {
            ++len;
        }

        name = new char[len + 1];
        for (int i = 0; i <= len; ++i) { 
            name[i] = n[i];
        }
    }

    if (p) {
        int len = 0;
        while (p[len] != '\0') {
            ++len;
        }

        president = new char[len + 1];
        for (int i = 0; i <= len; ++i) {
            president[i] = p[i];
        }
    }

    std::cout << "Parameterized constructor called for object at " << this << std::endl;
}

Country::Country(const Country& other)
    : name(nullptr), citizens(other.citizens), president(nullptr) {
    
    if (other.name) {
        int len = 0;
        while (other.name[len] != '\0') {
            ++len;
        }

        name = new char[len + 1];
        for (int i = 0; i <= len; ++i) {
            name[i] = other.name[i];
        }
    }

    if (other.president) {
        int len = 0;
        while (other.president[len] != '\0') {
            ++len;
        }

        president = new char[len + 1];
        for (int i = 0; i <= len; ++i) {
            president[i] = other.president[i];
        }
    }

    std::cout << "Copy constructor called for object at " << this << std::endl;
}

Country::~Country() {
    delete[] name;
    delete[] president;
    std::cout << "Destructor called for object at " << this << std::endl;
}

void Country::show() const {
    std::cout << "Country: name=" << (name ? name : "null")
              << ", citizens=" << citizens
              << ", president=" << (president ? president : "null")
              << std::endl;
}

void Country::setName(const char* n) {
    delete[] name;
    name = nullptr;

    if (n) {
        int len = 0;
        while (n[len] != '\0') {
            ++len;
        }

        name = new char[len + 1];
        for (int i = 0; i <= len; ++i) {
            name[i] = n[i];
        }
    }
}

void Country::setCitizens(int c) {
    citizens = c;
}

void Country::setPresident(const char* p) {
    delete[] president;
    president = nullptr;

    if (p) {
        int len = 0;
        while (p[len] != '\0') {
            ++len;
        }

        president = new char[len + 1];
        for (int i = 0; i <= len; ++i) {
            president[i] = p[i];
        }
    }
}

char* Country::getName() const {
    return name;
}

int Country::getCitizens() const {
    return citizens;
}

char* Country::getPresident() const {
    return president;
}
