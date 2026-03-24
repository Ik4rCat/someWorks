#include <iostream>
#include "Complex.h"

using namespace std;

Complex::Complex() {
    real = 0.0;
    imag = 0.0;
}

Complex::Complex(double real, double imag) {
    this->real = real;
    this->imag = imag;
}

Complex::Complex(const Complex& other) {
    this->real = other.real;
    this->imag = other.imag;
}

Complex::~Complex() {
}

double Complex::getReal() const {
    return real;
}

double Complex::getImag() const {
    return imag;
}

void Complex::setReal(double real) {
    this->real = real;
}

void Complex::setImag(double imag) {
    this->imag = imag;
}

Complex Complex::operator+(const Complex& other) const {
    return Complex(real + other.real, imag + other.imag);
}

Complex Complex::operator-(const Complex& other) const {
    return Complex(real - other.real, imag - other.imag);
}

bool Complex::operator==(const Complex& other) const {
    return real == other.real && imag == other.imag;
}

bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}

Complex Complex::operator()(double real, double imag) {
    this->real = real;
    this->imag = imag;
    return *this;
}

Complex& Complex::operator=(const Complex& other) {
    if (this != &other) {
        real = other.real;
        imag = other.imag;
    }
    return *this;
}

Complex& Complex::operator+=(const Complex& other) {
    real += other.real;
    imag += other.imag;
    return *this;
}

Complex& Complex::operator-=(const Complex& other) {
    real -= other.real;
    imag -= other.imag;
    return *this;
}

Complex operator+(double num, const Complex& c) {
    return Complex(num + c.real, c.imag);
}

Complex operator-(double num, const Complex& c) {
    return Complex(num - c.real, -c.imag);
}

ostream& operator<<(ostream& os, const Complex& c) {
    if (c.imag >= 0) {
        os << c.real << " + " << c.imag << "i";
    } else {
        os << c.real << " - " << (-c.imag) << "i";
    }
    return os;
}

istream& operator>>(istream& is, Complex& c) {
    cout << "Enter real part: ";
    is >> c.real;
    cout << "Enter imaginary part: ";
    is >> c.imag;
    return is;
}

void Complex::display() const {
    if (imag >= 0) {
        cout << real << " + " << imag << "i" << endl;
    } else {
        cout << real << " - " << (-imag) << "i" << endl;
    }
}
