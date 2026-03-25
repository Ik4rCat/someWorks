#pragma once

#include <iostream>
#include "Base.h"

using namespace std;

template <typename T1, typename T2, typename T3, typename T4>
class Child : public Base<T1, T2> {
protected:
    T3 value3;
    T4 value4;

public:
    Child() : Base<T1, T2>() {
        value3 = T3();
        value4 = T4();
    }
    
    Child(T1 v1, T2 v2, T3 v3, T4 v4) : Base<T1, T2>(v1, v2) {
        value3 = v3;
        value4 = v4;
    }
    
    Child(const Child<T1, T2, T3, T4>& other) : Base<T1, T2>(other) {
        value3 = other.value3;
        value4 = other.value4;
    }
    
    ~Child() {
    }
    
    T3 getValue3() const {
        return value3;
    }
    
    T4 getValue4() const {
        return value4;
    }
    
    void setValue3(T3 v3) {
        value3 = v3;
    }
    
    void setValue4(T4 v4) {
        value4 = v4;
    }
    
    void display() const override {
        cout << "Child: value1 = " << this->value1 
             << ", value2 = " << this->value2
             << ", value3 = " << value3 
             << ", value4 = " << value4 << endl;
    }
    
    Child<T1, T2, T3, T4>& operator=(const Child<T1, T2, T3, T4>& other) {
        if (this != &other) {
            Base<T1, T2>::operator=(other);
            value3 = other.value3;
            value4 = other.value4;
        }
        return *this;
    }
};
