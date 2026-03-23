#pragma once

#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;
    void simplify();
    int gcd(int a, int b) const;

public:
    Fraction();
    Fraction(int numerator, int denominator);
    Fraction(const Fraction& other);
    ~Fraction();
    
    int getNumerator() const;
    int getDenominator() const;
    void setNumerator(int numerator);
    void setDenominator(int denominator);
    
    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;
    Fraction operator/(const Fraction& other) const;
    
    Fraction& operator=(const Fraction& other);
    
    void display() const;
    void input();
};
