#pragma once

class Object;

class ICollection {
public:
    virtual void add(Object* value) = 0;
    virtual void removeAt(int index) = 0;
    virtual int size() const = 0;
    virtual void clear() = 0;
    virtual bool isEmpty() const = 0;
    virtual ~ICollection() {}
};
