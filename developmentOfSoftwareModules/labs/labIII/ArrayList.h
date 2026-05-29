#pragma once

#include "ICollection.h"
#include "IIterable.h"
#include "Iterator.h"
#include "Object.h"

class ArrayList : public ICollection, public IIterable {
private:
    Object** data;
    int capacity;
    int count;

    class ArrayListIterator : public Iterator {
    private:
        ArrayList* list;
        int current;

    public:
        ArrayListIterator(ArrayList* l) : list(l), current(0) {}
        bool hasNext() const override { return current < list->size(); }
        Object* next() override { return list->getAt(current++); }
        void reset() override { current = 0; }
    };

public:
    ArrayList() : data(nullptr), capacity(10), count(0) {
        data = new Object*[capacity];
    }

    explicit ArrayList(int initialCapacity) : data(nullptr), capacity(initialCapacity), count(0) {
        data = new Object*[capacity];
    }

    ~ArrayList() {
        clear();
        delete[] data;
    }

    void add(Object* value) override {
        if (count >= capacity) {
            int newCapacity = capacity * 2;
            Object** newData = new Object*[newCapacity];
            for (int i = 0; i < count; i++) newData[i] = data[i];
            delete[] data;
            data = newData;
            capacity = newCapacity;
        }
        data[count++] = value;
    }

    void removeAt(int index) override {
        if (index < 0 || index >= count) return;
        delete data[index];
        for (int i = index; i < count - 1; i++) data[i] = data[i + 1];
        count--;
    }

    int size() const override { return count; }
    void clear() override {
        for (int i = 0; i < count; i++) delete data[i];
        count = 0;
    }
    bool isEmpty() const override { return count == 0; }

    Iterator* getIterator() override {
        return new ArrayListIterator(this);
    }

    Object* getAt(int index) const {
        if (index < 0 || index >= count) return nullptr;
        return data[index];
    }
};
