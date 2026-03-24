#pragma once

#include <iostream>

using namespace std;

class Date {
private:
    int day;
    int month;
    int year;
    
    bool isLeapYear(int year) const;
    int getDaysInMonth(int month, int year) const;

public:
    Date();
    Date(int day, int month, int year);
    Date(const Date& other);
    ~Date();
    
    void incrementDay();
    void decrementDay();
    
    Date& operator++();
    Date operator++(int);
    Date& operator--();
    Date operator--(int);
    
    bool operator==(const Date& other) const;
    bool operator!=(const Date& other) const;
    bool operator>(const Date& other) const;
    bool operator<(const Date& other) const;
    
    Date& operator=(const Date& other);
    Date& operator+=(int days);
    Date& operator-=(int days);
    int operator()(const Date& other) const;
    
    friend ostream& operator<<(ostream& os, const Date& date);
    friend istream& operator>>(istream& is, Date& date);
    
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    
    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);
};
