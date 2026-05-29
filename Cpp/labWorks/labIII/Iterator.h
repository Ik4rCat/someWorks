#pragma once

class Object;

class Iterator {
public:
    virtual bool hasNext() const = 0;
    virtual Object* next() = 0;
    virtual void reset() = 0;
    virtual ~Iterator() {}
};
