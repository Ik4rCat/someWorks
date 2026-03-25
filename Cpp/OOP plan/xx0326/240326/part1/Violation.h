#pragma once

#include <iostream>
#include <string>

using namespace std;

class Violation {
private:
    string description;
    double fineAmount;
    string date;
    string location;

public:
    Violation();
    Violation(string description, double fineAmount, string date, string location);
    
    string getDescription() const;
    double getFineAmount() const;
    string getDate() const;
    string getLocation() const;
    
    void setDescription(string description);
    void setFineAmount(double fineAmount);
    void setDate(string date);
    void setLocation(string location);
    
    void display() const;
};
