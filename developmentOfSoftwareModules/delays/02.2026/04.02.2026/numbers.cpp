#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

// ─────────────────────────────────────────
//  Базовый класс — обычное целое число
// ─────────────────────────────────────────
class Number {
protected:
    int value;

public:
    Number() : value(0) {}
    Number(int v) : value(v) {}
    Number(const Number &other) : value(other.value) {}

    virtual ~Number() {}

    // 1. Получить значение
    virtual int getValue() const { return value; }

    // 2. Установить значение
    virtual void setValue(int v) { value = v; }

    // 3. Сложение
    virtual Number add(const Number &other) const {
        return Number(value + other.value);
    }

    // 4. Умножение
    virtual Number multiply(const Number &other) const {
        return Number(value * other.value);
    }

    // 5. Является ли чётным
    virtual bool isEven() const { return value % 2 == 0; }

    // 6. Абсолютное значение
    virtual int abs() const { return value >= 0 ? value : -value; }

    // 7. Вывод
    virtual void print() const {
        cout << "Number(" << value << ")" << endl;
    }
};

// ─────────────────────────────────────────
//  Наследник 1 — отрицательное число
// ─────────────────────────────────────────
class NegativeNumber : public Number {
public:
    NegativeNumber() : Number(-1) {}

    // Гарантируем что значение всегда отрицательное
    NegativeNumber(int v) : Number(v > 0 ? -v : v) {}

    NegativeNumber(const NegativeNumber &other) : Number(other.value) {}

    void setValue(int v) override {
        value = v > 0 ? -v : v;
    }

    // 1. Инвертировать знак (сделать положительным)
    int toPositive() const { return -value; }

    // 2. Насколько далеко от нуля
    int distanceFromZero() const { return -value; }

    // 3. Сравнение — какое из двух ближе к нулю
    bool isCloserToZero(const NegativeNumber &other) const {
        return -value < -other.value;
    }

    // 4. Возвести в степень (результат остаётся отрицательным если степень нечётная)
    double power(int exp) const {
        return pow(value, exp);
    }

    // 5. Прибавить положительное число (не выйти за 0)
    NegativeNumber addPositive(int n) const {
        int result = value + n;
        return NegativeNumber(result >= 0 ? -1 : result);
    }

    void print() const override {
        cout << "NegativeNumber(" << value << ")" << endl;
    }
};

// ─────────────────────────────────────────
//  Наследник 2 — дробное число
// ─────────────────────────────────────────
class FractionalNumber : public Number {
private:
    int numerator;   // числитель
    int denominator; // знаменатель

    // НОД для сокращения дроби
    int gcd(int a, int b) const {
        a = a < 0 ? -a : a;
        b = b < 0 ? -b : b;
        while (b) { int t = b; b = a % b; a = t; }
        return a;
    }

public:
    FractionalNumber() : Number(0), numerator(0), denominator(1) {}

    FractionalNumber(int num, int den) : Number(0) {
        if (den == 0) throw invalid_argument("Знаменатель не может быть 0");
        numerator   = num;
        denominator = den;
        value = num / den;
    }

    FractionalNumber(const FractionalNumber &other)
        : Number(other.value), numerator(other.numerator), denominator(other.denominator) {}

    // 1. Получить значение как double
    double toDouble() const {
        return (double)numerator / denominator;
    }

    // 2. Сократить дробь
    FractionalNumber reduce() const {
        int g = gcd(numerator, denominator);
        return FractionalNumber(numerator / g, denominator / g);
    }

    // 3. Сложение дробей
    FractionalNumber addFraction(const FractionalNumber &other) const {
        int num = numerator * other.denominator + other.numerator * denominator;
        int den = denominator * other.denominator;
        return FractionalNumber(num, den).reduce();
    }

    // 4. Умножение дробей
    FractionalNumber multiplyFraction(const FractionalNumber &other) const {
        return FractionalNumber(
            numerator * other.numerator,
            denominator * other.denominator
        ).reduce();
    }

    // 5. Является ли правильной дробью (|числитель| < |знаменатель|)
    bool isProper() const {
        return (numerator < 0 ? -numerator : numerator) <
               (denominator < 0 ? -denominator : denominator);
    }

    // 6. Получить обратную дробь
    FractionalNumber reciprocal() const {
        if (numerator == 0) throw runtime_error("Нельзя получить обратную для 0");
        return FractionalNumber(denominator, numerator);
    }

    void print() const override {
        cout << "FractionalNumber(" << numerator << "/" << denominator
             << " ≈ " << toDouble() << ")" << endl;
    }
};

// ─────────────────────────────────────────
//  main
// ─────────────────────────────────────────
int main() {
    cout << "=== Number ===" << endl;
    Number n1(10);
    Number n2(3);
    n1.print();
    n1.add(n2).print();
    n1.multiply(n2).print();
    cout << "Чётное: " << n1.isEven() << endl;
    cout << "Abs: " << n1.abs() << endl;

    cout << "\n=== NegativeNumber ===" << endl;
    NegativeNumber neg(-7);
    neg.print();
    cout << "В положительное: " << neg.toPositive() << endl;
    cout << "Расстояние от 0: " << neg.distanceFromZero() << endl;
    cout << "Степень 2: " << neg.power(2) << endl;
    cout << "Степень 3: " << neg.power(3) << endl;
    neg.addPositive(3).print();

    NegativeNumber neg2(-2);
    cout << "neg ближе к 0 чем neg2: " << neg.isCloserToZero(neg2) << endl;

    cout << "\n=== FractionalNumber ===" << endl;
    FractionalNumber f1(3, 4);
    FractionalNumber f2(1, 2);
    f1.print();
    f2.print();
    f1.addFraction(f2).print();
    f1.multiplyFraction(f2).print();
    cout << "Правильная: " << f1.isProper() << endl;
    f1.reciprocal().print();
    FractionalNumber f3(6, 9);
    cout << "До сокращения: "; f3.print();
    cout << "После: "; f3.reduce().print();

    return 0;
}
