#pragma once

#include <iostream>

using namespace std;

template <typename T1, typename T2>
class Base {
protected:
    T1 value1;
    T2 value2;

public:
    Base() {
        value1 = T1();
        value2 = T2();
    }
    
    Base(T1 v1, T2 v2) {
        value1 = v1;
        value2 = v2;
    }
    
    Base(const Base<T1, T2>& other) {
        value1 = other.value1;
        value2 = other.value2;
    }
    
    virtual ~Base() {
    }
    
    T1 getValue1() const {
        return value1;
    }
    
    T2 getValue2() const {
        return value2;
    }
    
    void setValue1(T1 v1) {
        value1 = v1;
    }
    
    void setValue2(T2 v2) {
        value2 = v2;
    }
    
    virtual void display() const {
        cout << "Base: value1 = " << value1 << ", value2 = " << value2 << endl;
    }
    
    Base<T1, T2>& operator=(const Base<T1, T2>& other) {
        if (this != &other) {
            value1 = other.value1;
            value2 = other.value2;
        }
        return *this;
    }
};
