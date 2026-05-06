#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node *next;
        Node(const T &d) : data(d), next(nullptr) {}
    };

    Node *head;   // начало очереди (откуда берём)
    Node *tail;   // конец очереди (куда кладём)
    int   length;

public:
    // Конструктор по умолчанию
    Queue() : head(nullptr), tail(nullptr), length(0) {}

    // Конструктор копирования
    Queue(const Queue &other) : head(nullptr), tail(nullptr), length(0) {
        Node *cur = other.head;
        while (cur) {
            add(cur->data);
            cur = cur->next;
        }
    }

    // Деструктор
    ~Queue() {
        while (head) {
            Node *tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    // Оператор присваивания
    Queue & operator=(const Queue &other) {
        if (this != &other) {
            this->~Queue();
            head = tail = nullptr;
            length = 0;
            Node *cur = other.head;
            while (cur) { add(cur->data); cur = cur->next; }
        }
        return *this;
    }

    // add — добавить элемент в конец очереди
    void add(const T &value) {
        Node *node = new Node(value);
        if (!tail) { head = tail = node; }
        else       { tail->next = node; tail = node; }
        length++;
    }

    // in — проверить, есть ли элемент в очереди
    bool in(const T &value) const {
        Node *cur = head;
        while (cur) {
            if (cur->data == value) return true;
            cur = cur->next;
        }
        return false;
    }

    // get — извлечь элемент из начала очереди (FIFO)
    T get() {
        if (!head) throw runtime_error("Очередь пуста");
        T val = head->data;
        Node *tmp = head;
        head = head->next;
        if (!head) tail = nullptr;
        delete tmp;
        length--;
        return val;
    }

    // getLength — получить количество элементов
    int getLength() const { return length; }

    // peek — посмотреть первый элемент без удаления
    T peek() const {
        if (!head) throw runtime_error("Очередь пуста");
        return head->data;
    }

    // Оператор [] — доступ по индексу (только чтение)
    T operator[](int index) const {
        if (index < 0 || index >= length)
            throw out_of_range("Индекс за пределами очереди");
        Node *cur = head;
        for (int i = 0; i < index; i++) cur = cur->next;
        return cur->data;
    }

    // Оператор вывода <<
    friend ostream & operator<<(ostream &os, const Queue<T> &q) {
        os << "Queue [";
        Node *cur = q.head;
        while (cur) {
            os << cur->data;
            if (cur->next) os << ", ";
            cur = cur->next;
        }
        os << "] (length=" << q.length << ")";
        return os;
    }

    // Оператор ввода >>
    friend istream & operator>>(istream &is, Queue<T> &q) {
        T val;
        cout << "Введите элемент: ";
        is >> val;
        q.add(val);
        return is;
    }
};

int main() {
    cout << "=== Queue<int> ===" << endl;
    Queue<int> q;
    q.add(10);
    q.add(20);
    q.add(30);
    q.add(40);
    cout << q << endl;

    cout << "getLength: " << q.getLength() << endl;
    cout << "q[0]: " << q[0] << ", q[2]: " << q[2] << endl;
    cout << "in(20): " << q.in(20) << ", in(99): " << q.in(99) << endl;
    cout << "get(): " << q.get() << endl;
    cout << "После get: " << q << endl;

    // Ввод через >>
    cin >> q;
    cout << "После ввода: " << q << endl;

    // Конструктор копирования
    Queue<int> q2(q);
    cout << "Копия: " << q2 << endl;

    cout << "\n=== Queue<string> ===" << endl;
    Queue<string> qs;
    qs.add("hello");
    qs.add("world");
    qs.add("foo");
    cout << qs << endl;
    cout << "in(\"world\"): " << qs.in("world") << endl;
    cout << "get(): " << qs.get() << endl;
    cout << qs << endl;

    return 0;
}
