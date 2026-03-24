#pragma once

#include <iostream>

using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex();
    Complex(double real, double imag);
    Complex(const Complex& other);
    ~Complex();
    
    double getReal() const;
    double getImag() const;
    void setReal(double real);
    void setImag(double imag);
    
    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;
    Complex operator()(double real, double imag);
    
    Complex& operator=(const Complex& other);
    Complex& operator+=(const Complex& other);
    Complex& operator-=(const Complex& other);
    
    friend Complex operator+(double num, const Complex& c);
    friend Complex operator-(double num, const Complex& c);
    friend ostream& operator<<(ostream& os, const Complex& c);
    friend istream& operator>>(istream& is, Complex& c);
    
    void display() const;
};
