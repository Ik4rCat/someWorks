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
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;
    
    Complex& operator=(const Complex& other);
    
    void display() const;
    void input();
};
