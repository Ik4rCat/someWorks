#pragma once

#include <iostream>
#include <vector>
#include "Contact.h"

using namespace std;

class PhoneBook {
private:
    vector<Contact> contacts;

public:
    PhoneBook();
    void addContact(const Contact& contact);
    void deleteContact(int index);
    int searchByName(const char* name) const;
    void showAll() const;
    void saveToFile(const char* filename) const;
    void loadFromFile(const char* filename);
    int getContactCount() const;
};
