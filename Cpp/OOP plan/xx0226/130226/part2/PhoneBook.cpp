#include <iostream>
#include "PhoneBook.h"
#include <fstream>

PhoneBook::PhoneBook() {}

void PhoneBook::addContact(const Contact& contact) {
    contacts.push_back(contact);
}

void PhoneBook::deleteContact(int index) {
    if (index >= 0 && index < contacts.size()) {
        contacts.erase(contacts.begin() + index);
    }
}

int PhoneBook::searchByName(const char* name) const {
    for (size_t i = 0; i < contacts.size(); i++) {
        if (strcmp(contacts[i].getFullName(), name) == 0) {
            return i;
        }
    }
    return -1;
}

void PhoneBook::showAll() const {
    if (contacts.size() == 0) {
        cout << "Phone book is empty" << endl;
        return;
    }
    
    cout << "\n===== ALL CONTACTS =====" << endl;
    for (size_t i = 0; i < contacts.size(); i++) {
        cout << "Contact #" << (i + 1) << endl;
        contacts[i].output();
    }
}

void PhoneBook::saveToFile(const char* filename) const {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Error saving to file" << endl;
        return;
    }
    
    file << contacts.size() << endl;
    for (size_t i = 0; i < contacts.size(); i++) {
        file << contacts[i].getFullName() << endl;
        file << contacts[i].getHomePhone() << endl;
        file << contacts[i].getWorkPhone() << endl;
        file << contacts[i].getMobilePhone() << endl;
        file << contacts[i].getAdditionalInfo() << endl;
    }
    
    file.close();
    cout << "Contacts saved to " << filename << endl;
}

void PhoneBook::loadFromFile(const char* filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error loading from file" << endl;
        return;
    }
    
    int count;
    file >> count;
    file.ignore();
    
    for (int i = 0; i < count; i++) {
        char fullName[100], homePhone[20], workPhone[20], mobilePhone[20], additionalInfo[100];
        
        file.getline(fullName, 100);
        file.getline(homePhone, 20);
        file.getline(workPhone, 20);
        file.getline(mobilePhone, 20);
        file.getline(additionalInfo, 100);
        
        Contact contact(fullName, homePhone, workPhone, mobilePhone, additionalInfo);
        addContact(contact);
    }
    
    file.close();
    cout << "Contacts loaded from " << filename << endl;
}

int PhoneBook::getContactCount() const {
    return contacts.size();
}
