#include <iostream>
#include "LinkedList.h"

using namespace std;

template <typename T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    size = 0;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& other) {
    head = nullptr;
    size = 0;
    
    if (other.head != nullptr) {
        Node* current = other.head;
        Node* prev = nullptr;
        
        while (current != nullptr) {
            Node* newNode = new Node(current->data);
            if (head == nullptr) {
                head = newNode;
            } else {
                prev->next = newNode;
            }
            prev = newNode;
            current = current->next;
            size++;
        }
    }
}

template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template <typename T>
void LinkedList<T>::append(T value) {
    Node* newNode = new Node(value);
    
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    size++;
}

template <typename T>
void LinkedList<T>::prepend(T value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    size++;
}

template <typename T>
void LinkedList<T>::insertAt(int index, T value) {
    if (index < 0 || index > size) {
        cout << "Invalid index" << endl;
        return;
    }
    
    if (index == 0) {
        prepend(value);
        return;
    }
    
    Node* newNode = new Node(value);
    Node* current = head;
    
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }
    
    newNode->next = current->next;
    current->next = newNode;
    size++;
}

template <typename T>
void LinkedList<T>::removeAt(int index) {
    if (index < 0 || index >= size) {
        cout << "Invalid index" << endl;
        return;
    }
    
    Node* temp;
    
    if (index == 0) {
        temp = head;
        head = head->next;
    } else {
        Node* current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        temp = current->next;
        current->next = temp->next;
    }
    
    delete temp;
    size--;
}

template <typename T>
void LinkedList<T>::removeValue(T value) {
    if (head == nullptr) return;
    
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
        return;
    }
    
    Node* current = head;
    while (current->next != nullptr && current->next->data != value) {
        current = current->next;
    }
    
    if (current->next != nullptr) {
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
        size--;
    }
}

template <typename T>
bool LinkedList<T>::contains(T value) const {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

template <typename T>
int LinkedList<T>::indexOf(T value) const {
    Node* current = head;
    int index = 0;
    
    while (current != nullptr) {
        if (current->data == value) {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}

template <typename T>
LinkedList<T>* LinkedList<T>::clone() const {
    LinkedList<T>* newList = new LinkedList<T>();
    
    if (head == nullptr) {
        return newList;
    }
    
    Node* current = head;
    Node* prev = nullptr;
    
    while (current != nullptr) {
        Node* newNode = new Node(current->data);
        if (newList->head == nullptr) {
            newList->head = newNode;
        } else {
            prev->next = newNode;
        }
        prev = newNode;
        current = current->next;
        newList->size++;
    }
    
    return newList;
}

template <typename T>
LinkedList<T>* LinkedList<T>::operator+(const LinkedList<T>& other) const {
    LinkedList<T>* newList = new LinkedList<T>();
    
    Node* current = head;
    while (current != nullptr) {
        newList->append(current->data);
        current = current->next;
    }
    
    current = const_cast<LinkedList<T>&>(other).head;
    while (current != nullptr) {
        newList->append(current->data);
        current = current->next;
    }
    
    return newList;
}

template <typename T>
LinkedList<T>* LinkedList<T>::operator*(const LinkedList<T>& other) const {
    LinkedList<T>* newList = new LinkedList<T>();
    
    Node* current1 = head;
    while (current1 != nullptr) {
        Node* current2 = const_cast<LinkedList<T>&>(other).head;
        while (current2 != nullptr) {
            if (current1->data == current2->data && !newList->contains(current1->data)) {
                newList->append(current1->data);
                break;
            }
            current2 = current2->next;
        }
        current1 = current1->next;
    }
    
    return newList;
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other) {
    if (this != &other) {
        clear();
        
        if (other.head != nullptr) {
            Node* current = other.head;
            Node* prev = nullptr;
            
            while (current != nullptr) {
                Node* newNode = new Node(current->data);
                if (head == nullptr) {
                    head = newNode;
                } else {
                    prev->next = newNode;
                }
                prev = newNode;
                current = current->next;
                size++;
            }
        }
    }
    return *this;
}

template <typename T>
int LinkedList<T>::getSize() const {
    return size;
}

template <typename T>
bool LinkedList<T>::isEmpty() const {
    return size == 0;
}

template <typename T>
void LinkedList<T>::clear() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    size = 0;
}

template <typename T>
void LinkedList<T>::display() const {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    
    cout << "List: ";
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

template <typename T>
T& LinkedList<T>::operator[](int index) {
    if (index < 0 || index >= size) {
        cout << "Invalid index" << endl;
        static T dummy;
        return dummy;
    }
    
    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

template <typename T>
const T& LinkedList<T>::operator[](int index) const {
    if (index < 0 || index >= size) {
        cout << "Invalid index" << endl;
        static T dummy;
        return dummy;
    }
    
    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

template class LinkedList<int>;
template class LinkedList<double>;
template class LinkedList<char>;
template class LinkedList<string>;
