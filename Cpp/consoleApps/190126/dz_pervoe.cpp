// ДЗпервое (190126)
// Задание 1: Матрица 5x3 — результаты прыжков в длину.
//            Найти спортсмена и попытку с наилучшим результатом.
// Задание 2: Деление без операций * и /: найти частное и остаток
//            только через сложение и вычитание.

#include <iostream>

// ============================================================
// Задание 1: матрица 5x3 прыжков в длину
// ============================================================
void task1() {
    const int ATHLETES = 5;
    const int ATTEMPTS = 3;

    double results[ATHLETES][ATTEMPTS] = {
        {6.45, 6.80, 7.10},
        {7.20, 6.95, 7.35},
        {5.90, 6.10, 6.05},
        {7.50, 7.25, 7.40},
        {6.60, 6.75, 6.50}
    };

    double best = results[0][0];
    int bestAthlete = 0, bestAttempt = 0;

    for (int i = 0; i < ATHLETES; i++) {
        for (int j = 0; j < ATTEMPTS; j++) {
            if (results[i][j] > best) {
                best = results[i][j];
                bestAthlete = i;
                bestAttempt = j;
            }
        }
    }

    std::cout << "=== Задание 1: Прыжки в длину ===" << std::endl;
    std::cout << "Матрица результатов (м):" << std::endl;
    for (int i = 0; i < ATHLETES; i++) {
        std::cout << "Спортсмен " << (i + 1) << ": ";
        for (int j = 0; j < ATTEMPTS; j++) {
            std::cout << results[i][j] << "  ";
        }
        std::cout << std::endl;
    }
    std::cout << "\nЛучший результат: " << best << " м" << std::endl;
    std::cout << "Спортсмен: " << (bestAthlete + 1)
              << ", Попытка: " << (bestAttempt + 1) << std::endl;
}

// ============================================================
// Задание 2: деление через сложение/вычитание
// ============================================================
void integerDivision(int dividend, int divisor, int& quotient, int& remainder) {
    if (divisor == 0) {
        std::cerr << "Ошибка: деление на ноль!" << std::endl;
        return;
    }

    bool negative = (dividend < 0) != (divisor < 0);
    int a = dividend < 0 ? -dividend : dividend;
    int b = divisor < 0 ? -divisor : divisor;

    quotient = 0;
    int current = 0;
    while (current + b <= a) {
        current = current + b;
        quotient = quotient + 1;
    }
    remainder = a - current;

    if (negative) quotient = -quotient;
    if (dividend < 0) remainder = -remainder;
}

void task2() {
    std::cout << "\n=== Задание 2: Деление без * и / ===" << std::endl;

    int pairs[][2] = {{17, 5}, {100, 7}, {-22, 4}, {0, 3}};
    for (auto& p : pairs) {
        int q, r;
        integerDivision(p[0], p[1], q, r);
        std::cout << p[0] << " / " << p[1]
                  << " = " << q << " (остаток " << r << ")" << std::endl;
    }
}

int main() {
    task1();
    task2();
    return 0;
}
