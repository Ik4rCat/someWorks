#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.14159265358979;

class Circle {
  private:
    double radius;
  public:
    Circle() : radius(1.0) {}
    Circle(double r) : radius(r > 0 ? r : 1.0) {}

    void setRadius(double r) {
        if (r > 0)
            radius = r;
        else
            cout << "Ошибка: радиус должен быть больше 0" << endl;
    }

    double getRadius() { return radius; }
    double area()      { return PI * radius * radius; }
    double perimeter() { return 2 * PI * radius; }

    void show() {
        cout << "Радиус:    " << radius      << endl;
        cout << "Площадь:   " << area()      << endl;
        cout << "Периметр:  " << perimeter() << endl;
    }
};

int main() {
    Circle c1;
    cout << "--- Конструктор без параметров ---" << endl;
    c1.show();

    Circle c2(5.0);
    cout << "\n--- Конструктор с параметром ---" << endl;
    c2.show();

    cout << "\n--- Смена радиуса на -3 (ошибка) ---" << endl;
    c2.setRadius(-3);

    cout << "\n--- Смена радиуса на 10 ---" << endl;
    c2.setRadius(10);
    c2.show();

    return 0;
}
