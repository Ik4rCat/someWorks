#pragma once

#include <iostream>

using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;
    
    void normalize();
    int toSeconds() const;
    void fromSeconds(int totalSeconds);

public:
    Time();
    Time(int hours, int minutes, int seconds);
    Time(const Time& other);
    ~Time();
    
    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;
    
    void setHours(int hours);
    void setMinutes(int minutes);
    void setSeconds(int seconds);
    
    void increment();
    
    Time& operator++();
    Time operator++(int);
    Time& operator--();
    Time operator--(int);
    
    bool operator==(const Time& other) const;
    bool operator!=(const Time& other) const;
    bool operator>(const Time& other) const;
    bool operator<(const Time& other) const;
    bool operator>=(const Time& other) const;
    bool operator<=(const Time& other) const;
    
    Time& operator=(const Time& other);
    Time& operator+=(int seconds);
    Time& operator-=(int seconds);
    Time operator()(int hours, int minutes, int seconds);
    
    Time operator+(int seconds) const;
    Time operator-(int seconds) const;
    
    friend ostream& operator<<(ostream& os, const Time& time);
    friend istream& operator>>(istream& is, Time& time);
    
    void display() const;
};
