#include <iostream>
#include "Time.h"

using namespace std;

Time::Time() {
    hours = 0;
    minutes = 0;
    seconds = 0;
}

Time::Time(int hours, int minutes, int seconds) {
    this->hours = hours;
    this->minutes = minutes;
    this->seconds = seconds;
    normalize();
}

Time::Time(const Time& other) {
    this->hours = other.hours;
    this->minutes = other.minutes;
    this->seconds = other.seconds;
}

Time::~Time() {
}

int Time::getHours() const {
    return hours;
}

int Time::getMinutes() const {
    return minutes;
}

int Time::getSeconds() const {
    return seconds;
}

void Time::setHours(int hours) {
    this->hours = hours;
    normalize();
}

void Time::setMinutes(int minutes) {
    this->minutes = minutes;
    normalize();
}

void Time::setSeconds(int seconds) {
    this->seconds = seconds;
    normalize();
}

void Time::normalize() {
    int totalSeconds = toSeconds();
    if (totalSeconds < 0) {
        totalSeconds += 86400;
    }
    totalSeconds %= 86400;
    fromSeconds(totalSeconds);
}

int Time::toSeconds() const {
    return hours * 3600 + minutes * 60 + seconds;
}

void Time::fromSeconds(int totalSeconds) {
    hours = totalSeconds / 3600;
    minutes = (totalSeconds % 3600) / 60;
    seconds = totalSeconds % 60;
}

void Time::increment() {
    seconds++;
    normalize();
}

Time& Time::operator++() {
    increment();
    return *this;
}

Time Time::operator++(int) {
    Time temp = *this;
    increment();
    return temp;
}

Time& Time::operator--() {
    seconds--;
    normalize();
    return *this;
}

Time Time::operator--(int) {
    Time temp = *this;
    seconds--;
    normalize();
    return temp;
}

bool Time::operator==(const Time& other) const {
    return hours == other.hours && minutes == other.minutes && seconds == other.seconds;
}

bool Time::operator!=(const Time& other) const {
    return !(*this == other);
}

bool Time::operator>(const Time& other) const {
    return toSeconds() > other.toSeconds();
}

bool Time::operator<(const Time& other) const {
    return toSeconds() < other.toSeconds();
}

bool Time::operator>=(const Time& other) const {
    return toSeconds() >= other.toSeconds();
}

bool Time::operator<=(const Time& other) const {
    return toSeconds() <= other.toSeconds();
}

Time& Time::operator=(const Time& other) {
    if (this != &other) {
        hours = other.hours;
        minutes = other.minutes;
        seconds = other.seconds;
    }
    return *this;
}

Time& Time::operator+=(int seconds) {
    this->seconds += seconds;
    normalize();
    return *this;
}

Time& Time::operator-=(int seconds) {
    this->seconds -= seconds;
    normalize();
    return *this;
}

Time Time::operator()(int hours, int minutes, int seconds) {
    this->hours = hours;
    this->minutes = minutes;
    this->seconds = seconds;
    normalize();
    return *this;
}

Time Time::operator+(int seconds) const {
    Time temp = *this;
    temp += seconds;
    return temp;
}

Time Time::operator-(int seconds) const {
    Time temp = *this;
    temp -= seconds;
    return temp;
}

ostream& operator<<(ostream& os, const Time& time) {
    if (time.hours < 10) os << "0";
    os << time.hours << ":";
    if (time.minutes < 10) os << "0";
    os << time.minutes << ":";
    if (time.seconds < 10) os << "0";
    os << time.seconds;
    return os;
}

istream& operator>>(istream& is, Time& time) {
    char colon1, colon2;
    cout << "Enter time (HH:MM:SS): ";
    is >> time.hours >> colon1 >> time.minutes >> colon2 >> time.seconds;
    time.normalize();
    return is;
}

void Time::display() const {
    cout << *this << endl;
}
