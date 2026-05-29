#pragma once

#include "ICollection.h"
#include "IIterable.h"
#include "Iterator.h"
#include "Object.h"

struct Node {
    Object* value;
    Node* next;
    Node(Object* v, Node* n = nullptr) : value(v), next(n) {}
};

class LinkedList : public ICollection, public IIterable {
private:
    Node* head;
    int count;

    class LinkedListIteratorImpl : public Iterator {
    private:
        Node* head;
        Node* current;

    public:
        explicit LinkedListIteratorImpl(Node* h) : head(h), current(h) {}
        bool hasNext() const override { return current != nullptr; }
        Object* next() override {
            Object* val = current->value;
            current = current->next;
            return val;
        }
        void reset() override { current = head; }
    };

public:
    LinkedList() : head(nullptr), count(0) {}

    ~LinkedList() {
        clear();
    }

    void add(Object* value) override {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) temp = temp->next;
            temp->next = newNode;
        }
        count++;
    }

    void removeAt(int index) override {
        if (index < 0 || index >= count) return;
        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp->value;
            delete temp;
        } else {
            Node* temp = head;
            for (int i = 0; i < index - 1; i++) temp = temp->next;
            Node* toDelete = temp->next;
            temp->next = toDelete->next;
            delete toDelete->value;
            delete toDelete;
        }
        count--;
    }

    int size() const override { return count; }

    void clear() override {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp->value;
            delete temp;
        }
        count = 0;
    }

    bool isEmpty() const override { return count == 0; }

    Iterator* getIterator() override {
        return new LinkedListIteratorImpl(head);
    }
};
