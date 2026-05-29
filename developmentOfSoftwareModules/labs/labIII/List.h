#pragma once

template<typename T>
class List {
private:
    T* data;
    int capacity;
    int count;

public:
    List() : data(nullptr), capacity(8), count(0) {
        data = new T[capacity];
    }

    ~List() {
        delete[] data;
    }

    void add(T value) {
        if (count >= capacity) {
            capacity = capacity + capacity / 2;
            T* newData = new T[capacity];
            for (int i = 0; i < count; i++) newData[i] = data[i];
            delete[] data;
            data = newData;
        }
        data[count++] = value;
    }

    void removeAt(int index) {
        if (index < 0 || index >= count) return;
        for (int i = index; i < count - 1; i++) data[i] = data[i + 1];
        count--;
    }

    int size() const {
        return count;
    }

    void clear() {
        count = 0;
    }

    bool isEmpty() const {
        return count == 0;
    }

    T getAt(int index) const {
        if (index < 0 || index >= count) return T();
        return data[index];
    }
};
