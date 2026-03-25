#include <iostream>
#include "Violation.h"

using namespace std;

Violation::Violation() {
    description = "";
    fineAmount = 0.0;
    date = "";
    location = "";
}

Violation::Violation(string description, double fineAmount, string date, string location) {
    this->description = description;
    this->fineAmount = fineAmount;
    this->date = date;
    this->location = location;
}

string Violation::getDescription() const {
    return description;
}

double Violation::getFineAmount() const {
    return fineAmount;
}

string Violation::getDate() const {
    return date;
}

string Violation::getLocation() const {
    return location;
}

void Violation::setDescription(string description) {
    this->description = description;
}

void Violation::setFineAmount(double fineAmount) {
    this->fineAmount = fineAmount;
}

void Violation::setDate(string date) {
    this->date = date;
}

void Violation::setLocation(string location) {
    this->location = location;
}

void Violation::display() const {
    cout << "    Description: " << description << endl;
    cout << "    Fine: $" << fineAmount << endl;
    cout << "    Date: " << date << endl;
    cout << "    Location: " << location << endl;
}
