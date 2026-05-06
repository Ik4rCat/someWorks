#include <iostream>
using namespace std;

template <class T>
class List {
private:
    class Node {
    public:
        T dat;
        Node *next;
        Node(T d = 0) : dat(d), next(nullptr) {}
    };

    Node *head, *tail;

public:
    List() : head(nullptr), tail(nullptr) {}

    // Деструктор
    ~List() {
        Node *cur = head;
        while (cur) {
            Node *tmp = cur->next;
            delete cur;
            cur = tmp;
        }
    }

    // Конструктор копирования
    List(const List &other) : head(nullptr), tail(nullptr) {
        Node *cur = other.head;
        while (cur) {
            insert_end(cur->dat);
            cur = cur->next;
        }
    }

    // Оператор присваивания
    List & operator=(const List &other) {
        if (this != &other) {
            this->~List();
            head = tail = nullptr;
            Node *cur = other.head;
            while (cur) {
                insert_end(cur->dat);
                cur = cur->next;
            }
        }
        return *this;
    }

    // Вставка в начало
    void insert_beg(T data) {
        Node *nel = new Node(data);
        nel->next = head;
        head = nel;
        if (!tail) tail = head;
    }

    // Вставка в конец
    void insert_end(T data) {
        Node *nel = new Node(data);
        if (!tail) {
            head = tail = nel;
        } else {
            tail->next = nel;
            tail = nel;
        }
    }

    // Удаление элемента
    void del(T data) {
        Node *cur = head, *prev = nullptr;
        while (cur) {
            if (cur->dat == data) {
                if (prev) prev->next = cur->next;
                else      head = cur->next;
                if (cur == tail) tail = prev;
                delete cur;
                return;
            }
            prev = cur;
            cur = cur->next;
        }
    }

    // Поиск элемента
    int find(T data) const {
        Node *cur = head;
        int idx = 0;
        while (cur) {
            if (cur->dat == data) return idx;
            cur = cur->next;
            idx++;
        }
        return -1;
    }

    // Вывод
    void display() const {
        Node *cur = head;
        while (cur) {
            cout << cur->dat << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    // --- Итератор ---
    class Iterator {
        Node *cur;
    public:
        Iterator(Node *n) : cur(n) {}
        Iterator(const Iterator &it) : cur(it.cur) {}

        Iterator & operator++() {
            cur = cur->next;
            return *this;
        }

        bool operator!=(const Iterator &other) const {
            return cur != other.cur;
        }

        T & operator*()  { return cur->dat; }
        T * operator->() { return &cur->dat; }
    };

    Iterator begin() const { return Iterator(head); }
    Iterator end()   const { return Iterator(nullptr); }
};

int main() {
    List<int> lst;
    lst.insert_end(1);
    lst.insert_end(2);
    lst.insert_end(3);
    lst.insert_beg(0);

    cout << "Список: ";
    lst.display();

    cout << "Через итератор: ";
    for (List<int>::Iterator it = lst.begin(); it != lst.end(); ++it)
        cout << *it << " ";
    cout << endl;

    cout << "Найти 2: индекс " << lst.find(2) << endl;

    lst.del(2);
    cout << "После удаления 2: ";
    lst.display();

    // Конструктор копирования
    List<int> lst2(lst);
    cout << "Копия: ";
    lst2.display();

    // Оператор присваивания
    List<int> lst3;
    lst3 = lst;
    cout << "Присваивание: ";
    lst3.display();

    // Шаблон со строками
    List<char> charList;
    charList.insert_end('a');
    charList.insert_end('b');
    charList.insert_end('c');
    cout << "Char список: ";
    charList.display();

    return 0;
}
