#pragma once

#include <iostream>

class Object {
public:
    virtual void print(std::ostream& out) const = 0;
    virtual Object* clone() const = 0;
    virtual ~Object() {}
};

template<typename T>
class ObjectT : public Object {
private:
    T value;

public:
    explicit ObjectT(const T& v) : value(v) {}

    void print(std::ostream& out) const override {
        out << value;
    }

    Object* clone() const override {
        return new ObjectT<T>(value);
    }

    T getValue() const {
        return value;
    }
};
