#include <iostream>
#include "Date.h"

Date::Date() {
    day = 1;
    month = 1;
    year = 2000;
}

Date::Date(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
}

Date::Date(const Date& other) {
    this->day = other.day;
    this->month = other.month;
    this->year = other.year;
}

Date::~Date() {
}

bool Date::isLeapYear(int year) const {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int Date::getDaysInMonth(int month, int year) const {
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    return days[month - 1];
}

void Date::incrementDay() {
    day++;
    if (day > getDaysInMonth(month, year)) {
        day = 1;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
}

void Date::decrementDay() {
    day--;
    if (day < 1) {
        month--;
        if (month < 1) {
            month = 12;
            year--;
        }
        day = getDaysInMonth(month, year);
    }
}

Date& Date::operator++() {
    incrementDay();
    return *this;
}

Date Date::operator++(int) {
    Date temp = *this;
    incrementDay();
    return temp;
}

Date& Date::operator--() {
    decrementDay();
    return *this;
}

Date Date::operator--(int) {
    Date temp = *this;
    decrementDay();
    return temp;
}

bool Date::operator==(const Date& other) const {
    return day == other.day && month == other.month && year == other.year;
}

bool Date::operator!=(const Date& other) const {
    return !(*this == other);
}

bool Date::operator>(const Date& other) const {
    if (year != other.year) return year > other.year;
    if (month != other.month) return month > other.month;
    return day > other.day;
}

bool Date::operator<(const Date& other) const {
    if (year != other.year) return year < other.year;
    if (month != other.month) return month < other.month;
    return day < other.day;
}

Date& Date::operator=(const Date& other) {
    if (this != &other) {
        day = other.day;
        month = other.month;
        year = other.year;
    }
    return *this;
}

Date& Date::operator+=(int days) {
    for (int i = 0; i < days; i++) {
        incrementDay();
    }
    return *this;
}

Date& Date::operator-=(int days) {
    for (int i = 0; i < days; i++) {
        decrementDay();
    }
    return *this;
}

int Date::operator()(const Date& other) const {
    Date temp1 = *this;
    Date temp2 = other;
    int count = 0;
    
    while (temp1 != temp2) {
        if (temp1 < temp2) {
            temp1.incrementDay();
            count++;
        } else {
            temp2.incrementDay();
            count--;
        }
    }
    return count;
}

ostream& operator<<(ostream& os, const Date& date) {
    os << date.day << "." << date.month << "." << date.year;
    return os;
}

istream& operator>>(istream& is, Date& date) {
    char dot;
    is >> date.day >> dot >> date.month >> dot >> date.year;
    return is;
}

int Date::getDay() const {
    return day;
}

int Date::getMonth() const {
    return month;
}

int Date::getYear() const {
    return year;
}

void Date::setDay(int day) {
    this->day = day;
}

void Date::setMonth(int month) {
    this->month = month;
}

void Date::setYear(int year) {
    this->year = year;
}
