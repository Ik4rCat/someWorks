#include <iostream>
#include "Contact.h"

Contact::Contact() {
    fullName = new char[1];
    fullName[0] = '\0';
    strcpy(homePhone, "");
    strcpy(workPhone, "");
    strcpy(mobilePhone, "");
    strcpy(additionalInfo, "");
}

Contact::Contact(const char* fullName, const char* homePhone, const char* workPhone, const char* mobilePhone, const char* additionalInfo) {
    this->fullName = new char[strlen(fullName) + 1];
    strcpy(this->fullName, fullName);
    strcpy(this->homePhone, homePhone);
    strcpy(this->workPhone, workPhone);
    strcpy(this->mobilePhone, mobilePhone);
    strcpy(this->additionalInfo, additionalInfo);
}

Contact::Contact(const Contact& other) {
    this->fullName = new char[strlen(other.fullName) + 1];
    strcpy(this->fullName, other.fullName);
    strcpy(this->homePhone, other.homePhone);
    strcpy(this->workPhone, other.workPhone);
    strcpy(this->mobilePhone, other.mobilePhone);
    strcpy(this->additionalInfo, other.additionalInfo);
}

Contact::~Contact() {
    delete[] fullName;
}

void Contact::setFullName(const char* fullName) {
    delete[] this->fullName;
    this->fullName = new char[strlen(fullName) + 1];
    strcpy(this->fullName, fullName);
}

void Contact::setHomePhone(const char* phone) {
    strcpy(homePhone, phone);
}

void Contact::setWorkPhone(const char* phone) {
    strcpy(workPhone, phone);
}

void Contact::setMobilePhone(const char* phone) {
    strcpy(mobilePhone, phone);
}

void Contact::setAdditionalInfo(const char* info) {
    strcpy(additionalInfo, info);
}

void Contact::input() {
    char temp[100];
    
    cout << "Full Name: ";
    cin.getline(temp, 100);
    setFullName(temp);
    
    cout << "Home Phone: ";
    cin.getline(homePhone, 20);
    
    cout << "Work Phone: ";
    cin.getline(workPhone, 20);
    
    cout << "Mobile Phone: ";
    cin.getline(mobilePhone, 20);
    
    cout << "Additional Info: ";
    cin.getline(additionalInfo, 100);
}

void Contact::output() const {
    cout << "Name: " << fullName << endl;
    cout << "Home: " << homePhone << endl;
    cout << "Work: " << workPhone << endl;
    cout << "Mobile: " << mobilePhone << endl;
    cout << "Info: " << additionalInfo << endl;
    cout << "------------------------" << endl;
}
