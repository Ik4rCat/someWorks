#pragma once

class Iterator;

class IIterable {
public:
    virtual Iterator* getIterator() = 0;
    virtual ~IIterable() {}
};
