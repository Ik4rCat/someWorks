#pragma once

#include <vector>

template <typename T>
class Massiv
{
private:
    std::vector<T> data;

public:
    explicit Massiv(int size)
    {
        data.resize(size);
    }

    int getSize() const
    {
        return static_cast<int>(data.size());
    }

    const T& getValue(int index) const
    {
        return data.at(index);
    }

    void setValue(int index, const T& value)
    {
        data.at(index) = value;
    }
};