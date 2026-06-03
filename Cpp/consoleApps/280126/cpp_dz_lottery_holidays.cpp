// с++ дз (280126)
// Задание 1: Подобие лотереи (генерация случайных чисел)
// Задание 2: Случайные праздники с датами, подсчёт через сколько дней они наступят

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

// ============================================================
// Задание 1: Лотерея
// ============================================================
void lottery() {
    std::cout << "=== ЛОТЕРЕЯ ===" << std::endl;
    std::cout << "Ваши 6 чисел: ";
    std::vector<int> drawn;
    while ((int)drawn.size() < 6) {
        int n = rand() % 49 + 1;
        bool duplicate = false;
        for (int d : drawn) if (d == n) { duplicate = true; break; }
        if (!duplicate) { drawn.push_back(n); std::cout << n << " "; }
    }
    std::cout << std::endl;

    std::cout << "Введите ваши 6 чисел (от 1 до 49):" << std::endl;
    int userNums[6];
    int matches = 0;
    for (int i = 0; i < 6; i++) {
        std::cin >> userNums[i];
    }
    for (int u : userNums) {
        for (int d : drawn) {
            if (u == d) { matches++; break; }
        }
    }
    std::cout << "Совпадений: " << matches << " из 6" << std::endl;
    if (matches == 6) std::cout << "ДЖЕКПОТ!" << std::endl;
    else if (matches >= 3) std::cout << "Небольшой выигрыш!" << std::endl;
    else std::cout << "Не повезло, попробуй ещё." << std::endl;
}

// ============================================================
// Задание 2: Праздники
// ============================================================
struct Holiday {
    std::string name;
    int day;
    int month;
};

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int month, int year) {
    int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (month == 2 && isLeapYear(year)) return 29;
    return days[month - 1];
}

// Считает дней от (d1,m1,y1) до (d2,m2,y2)
int daysBetween(int d1, int m1, int y1, int d2, int m2, int y2) {
    int count = 0;
    while (!(d1 == d2 && m1 == m2 && y1 == y2)) {
        d1++;
        if (d1 > daysInMonth(m1, y1)) { d1 = 1; m1++; }
        if (m1 > 12) { m1 = 1; y1++; }
        count++;
        if (count > 366 * 2) break; // защита
    }
    return count;
}

void holidays() {
    std::cout << "\n=== ПРАЗДНИКИ ===" << std::endl;

    // Генерируем 5 случайных "праздников" — случайные дни в году
    std::vector<Holiday> hols;
    std::string names[] = {"День Кота", "День Кода", "День Пиццы",
                           "День Сна", "День Приключений"};
    for (int i = 0; i < 5; i++) {
        Holiday h;
        h.name = names[i];
        h.month = rand() % 12 + 1;
        h.day = rand() % daysInMonth(h.month, 2026) + 1;
        hols.push_back(h);
    }

    // Текущая дата (захардкожено для примера, в реале — через time())
    time_t t = time(nullptr);
    struct tm* now = localtime(&t);
    int curDay = now->tm_mday;
    int curMonth = now->tm_mon + 1;
    int curYear = now->tm_year + 1900;

    std::cout << "Текущая дата: " << curDay << "." << curMonth << "." << curYear << std::endl;
    std::cout << std::endl;

    for (auto& h : hols) {
        int targetYear = curYear;
        // Если дата уже прошла — ищем в следующем году
        bool passed = (h.month < curMonth) || (h.month == curMonth && h.day < curDay);
        if (passed) targetYear++;

        int days = daysBetween(curDay, curMonth, curYear, h.day, h.month, targetYear);
        std::cout << h.name << " (" << h.day << "." << h.month << "."
                  << targetYear << ") — через " << days << " дней" << std::endl;
    }
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    lottery();
    holidays();
    return 0;
}
