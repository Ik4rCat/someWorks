#pragma once

#include <iostream>
#include "Child.h"

using namespace std;

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
class Child2 : public Child<T1, T2, T3, T4> {
private:
    T5 value5;
    T6 value6;

public:
    Child2() : Child<T1, T2, T3, T4>() {
        value5 = T5();
        value6 = T6();
    }
    
    Child2(T1 v1, T2 v2, T3 v3, T4 v4, T5 v5, T6 v6) 
        : Child<T1, T2, T3, T4>(v1, v2, v3, v4) {
        value5 = v5;
        value6 = v6;
    }
    
    Child2(const Child2<T1, T2, T3, T4, T5, T6>& other) 
        : Child<T1, T2, T3, T4>(other) {
        value5 = other.value5;
        value6 = other.value6;
    }
    
    ~Child2() {
    }
    
    T5 getValue5() const {
        return value5;
    }
    
    T6 getValue6() const {
        return value6;
    }
    
    void setValue5(T5 v5) {
        value5 = v5;
    }
    
    void setValue6(T6 v6) {
        value6 = v6;
    }
    
    void display() const override {
        cout << "Child2: value1 = " << this->value1 
             << ", value2 = " << this->value2
             << ", value3 = " << this->value3 
             << ", value4 = " << this->value4
             << ", value5 = " << value5 
             << ", value6 = " << value6 << endl;
    }
    
    Child2<T1, T2, T3, T4, T5, T6>& operator=(const Child2<T1, T2, T3, T4, T5, T6>& other) {
        if (this != &other) {
            Child<T1, T2, T3, T4>::operator=(other);
            value5 = other.value5;
            value6 = other.value6;
        }
        return *this;
    }
};
