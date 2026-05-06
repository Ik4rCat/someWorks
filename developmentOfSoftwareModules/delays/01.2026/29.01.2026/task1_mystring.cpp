#include <iostream>
#include <cstring>
using namespace std;

class MyString {
private:
    char *data;

public:
    // Конструктор по умолчанию
    MyString() {
        data = new char[1];
        data[0] = '\0';
    }

    // Конструктор с параметром
    MyString(const char *str) {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }

    // Конструктор копирования
    MyString(const MyString &other) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
    }

    // Деструктор
    ~MyString() {
        delete[] data;
    }

    // Длина строки
    int length() const {
        return strlen(data);
    }

    // Конкатенация
    MyString concat(const MyString &other) const {
        MyString result;
        delete[] result.data;
        result.data = new char[length() + other.length() + 1];
        strcpy(result.data, data);
        strcat(result.data, other.data);
        return result;
    }

    // Сравнение
    int compare(const MyString &other) const {
        return strcmp(data, other.data);
    }

    // Вставка строки на позицию pos
    MyString insert(const MyString &other, int pos) const {
        if (pos < 0 || pos > length()) return *this;
        MyString result;
        delete[] result.data;
        result.data = new char[length() + other.length() + 1];
        strncpy(result.data, data, pos);
        result.data[pos] = '\0';
        strcat(result.data, other.data);
        strcat(result.data, data + pos);
        return result;
    }

    // Вывод
    void print() const {
        cout << data << endl;
    }

    // Оператор =
    MyString & operator=(const MyString &other) {
        if (this != &other) {
            delete[] data;
            data = new char[strlen(other.data) + 1];
            strcpy(data, other.data);
        }
        return *this;
    }

    // Оператор + (конкатенация)
    MyString operator+(const MyString &other) const {
        return concat(other);
    }

    // Оператор +=
    MyString & operator+=(const MyString &other) {
        *this = concat(other);
        return *this;
    }

    // Оператор [] (доступ к символу)
    char & operator[](int index) {
        return data[index];
    }
};

int main() {
    MyString s1("Hello");
    MyString s2(", World!");
    MyString s3(s1); // копирование

    cout << "s1: "; s1.print();
    cout << "s2: "; s2.print();
    cout << "s3 (копия s1): "; s3.print();

    MyString s4 = s1 + s2;
    cout << "s1 + s2: "; s4.print();

    s1 += MyString(" OOP");
    cout << "s1 после +=: "; s1.print();

    cout << "Длина s2: " << s2.length() << endl;
    cout << "Сравнение s1 и s3: " << s1.compare(s3) << endl;

    MyString s5 = s3.insert(MyString(" C++"), 5);
    cout << "Вставка в s3: "; s5.print();

    cout << "s4[0]: " << s4[0] << endl;

    return 0;
}
