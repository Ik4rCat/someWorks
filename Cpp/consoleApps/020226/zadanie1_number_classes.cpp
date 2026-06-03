// 1 задание (020226)
// Класс «Обычное число» с двумя наследниками: ОтрицательноеЧисло и ДробноеЧисло.
// Минимум 5 методов + конструкторы.

#include <iostream>
#include <stdexcept>
#include <cmath>

class Number {
protected:
    double value;

public:
    Number(double val) : value(val) {}

    virtual double getValue() const { return value; }
    virtual void setValue(double val) { value = val; }

    virtual double add(double other) const { return value + other; }
    virtual double multiply(double other) const { return value * other; }
    virtual double absolute() const { return std::abs(value); }

    virtual void print() const {
        std::cout << "Number: " << value << std::endl;
    }

    virtual bool isZero() const { return value == 0.0; }

    virtual ~Number() = default;
};


class NegativeNumber : public Number {
public:
    // Конструктор — принудительно делает число отрицательным
    NegativeNumber(double val) : Number(val <= 0 ? val : -val) {}

    void setValue(double val) override {
        value = (val <= 0) ? val : -val;
    }

    // Возвращает модуль (делает «положительную копию»)
    double toPositive() const { return std::abs(value); }

    // Проверяет, меньше ли это число другого отрицательного
    bool isMoreNegativeThan(const NegativeNumber& other) const {
        return value < other.value;
    }

    void print() const override {
        std::cout << "NegativeNumber: " << value << std::endl;
    }

    // Возводит в квадрат (результат будет положительным)
    double square() const { return value * value; }
};


class FractionalNumber : public Number {
private:
    int numerator;
    int denominator;

    void reduce() {
        if (denominator == 0) throw std::invalid_argument("Знаменатель не может быть 0");
        int g = gcd(std::abs(numerator), std::abs(denominator));
        numerator /= g;
        denominator /= g;
        if (denominator < 0) { numerator = -numerator; denominator = -denominator; }
        value = static_cast<double>(numerator) / denominator;
    }

    static int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

public:
    FractionalNumber(int num, int den) : Number(0), numerator(num), denominator(den) {
        reduce();
    }

    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }

    // Сложение дробей
    FractionalNumber addFraction(const FractionalNumber& other) const {
        return FractionalNumber(
            numerator * other.denominator + other.numerator * denominator,
            denominator * other.denominator
        );
    }

    // Умножение дробей
    FractionalNumber multiplyFraction(const FractionalNumber& other) const {
        return FractionalNumber(numerator * other.numerator, denominator * other.denominator);
    }

    // Обратная дробь
    FractionalNumber reciprocal() const {
        return FractionalNumber(denominator, numerator);
    }

    bool isProper() const { return std::abs(numerator) < std::abs(denominator); }

    void print() const override {
        std::cout << "FractionalNumber: " << numerator << "/" << denominator
                  << " = " << value << std::endl;
    }
};


int main() {
    Number n(42);
    n.print();
    std::cout << "Absolute: " << n.absolute() << std::endl;

    NegativeNumber neg(15); // станет -15
    neg.print();
    std::cout << "ToPositive: " << neg.toPositive() << std::endl;
    std::cout << "Square: " << neg.square() << std::endl;

    FractionalNumber frac(3, 4);
    frac.print();
    FractionalNumber frac2(1, 2);
    frac.addFraction(frac2).print();
    frac.multiplyFraction(frac2).print();
    frac.reciprocal().print();

    return 0;
}
