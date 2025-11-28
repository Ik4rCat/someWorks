#include <iostream>
#include <cmath>
#include <windows.h>
#include <ctime>
using namespace std;

void task1() {
    int a;
    cout << "Enter start value a: ";
    cin >> a;
    int sum = 0;
    while (a <= 500) {
        sum += a;
        a++;
    }
    cout << "Sum up to 500: " << sum << "\n";
}

void task2() {
    int x, y;
    cout << "Enter base x: ";
    cin >> x;
    cout << "Enter exponent y: ";
    cin >> y;
    bool negative = y < 0;
    int absY = negative ? -y : y;
    double result = 1;
    for (int i = 0; i < absY; ++i) {
        result *= x;
    }
    if (negative) {
        result = 1.0 / result;
    }
    cout << "Result: " << result << "\n";
}

void task3() {
    double sum = 0;
    for (int i = 1; i <= 1000; ++i) {
        sum += i;
    }
    cout << "Average 1..1000: " << sum / 1000.0 << "\n";
}

void task4() {
    int a;
    cout << "Enter a (1-20): ";
    cin >> a;
    long long product = 1;
    for (int i = a; i <= 20; ++i) {
        product *= i;
    }
    cout << "Product: " << product << "\n";
}

void task5() {
    const int k = 7;
    for (int i = 1; i <= 10; ++i) {
        cout << k << " x " << i << " = " << k * i << "\n";
    }
}

void task6() {
    int count = 0;
    // Count numbers where exactly two digits match.
    for (int i = 100; i <= 999; ++i) {
        int d1 = i / 100;
        int d2 = (i / 10) % 10;
        int d3 = i % 10;
        if ((d1 == d2 && d1 != d3) ||
            (d1 == d3 && d1 != d2) ||
            (d2 == d3 && d2 != d1)) {
            count++;
        }
    }
    cout << "Numbers with exactly two equal digits: " << count << "\n";
}

void task7() {
    int count = 0;
    for (int i = 100; i <= 999; ++i) {
        int d1 = i / 100;
        int d2 = (i / 10) % 10;
        int d3 = i % 10;
        if (d1 != d2 && d1 != d3 && d2 != d3) {
            count++;
        }
    }
    cout << "Numbers with all unique digits: " << count << "\n";
}

void task8() {
    int number;
    cout << "Enter number: ";
    cin >> number;
    int filtered = 0;
    int place = 1;
    if (number == 0) {
        cout << "Filtered number: 0\n";
        return;
    }
    while (number != 0) {
        int digit = number % 10;
        number /= 10;
        if (digit != 3 && digit != 6) {
            filtered += digit * place;
            place *= 10;
        }
    }
    cout << "Filtered number: " << filtered << "\n";
}

void task9() {
    int a;
    cout << "Enter A: ";
    cin >> a;
    cout << "Valid B:\n";
    for (int b = 1; b * b <= a; ++b) {
        if (a % (b * b) == 0 && a % (b * b * b) != 0) {
            cout << b << "\n";
        }
    }
}

void task10() {
    int a;
    cout << "Enter A: ";
    cin >> a;
    int temp = a;
    int sum = 0;
    while (temp != 0) {
        sum += temp % 10;
        temp /= 10;
    }
    long long cube = 1LL * sum * sum * sum;
    long long square = 1LL * a * a;
    cout << (cube == square ? "Equal\n" : "Not equal\n");
}

void task11() {
    int a;
    cout << "Enter number: ";
    cin >> a;
    cout << "Divisors:\n";
    for (int i = 1; i <= a; ++i) {
        if (a % i == 0) {
            cout << i << "\n";
        }
    }
}

void task12() {
    int choice;
    cout << "1-A 2-B 3-C 4-D 5-E 6-Exit\nSelect: ";
    cin >> choice;
    const int N = 8;
    if (choice == 6) {
        cout << "Bye\n";
        return;
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            bool star = false;
            switch (choice) {
            case 1: star = j >= i; break;
            case 2: star = j <= i; break;
            case 3: star = (j >= i && j < N - i); break;
            case 4: star = (i >= N / 2 && j >= (N - (2 * (i - N / 2) + 1)) / 2 && j < (N + (2 * (i - N / 2) + 1)) / 2); break;
            case 5:
                if (i <= N / 2) star = (j >= i && j < N - i);
                else {
                    int idx = i - N / 2;
                    int stars = 2 * idx - 1;
                    int spaces = (N - stars) / 2;
                    star = (j >= spaces && j < spaces + stars);
                }
                break;
            default: break;
            }
            cout << (star ? "*" : " ");
        }
        cout << "\n";
    }
}

void task13() {
    long long number;
    cout << "Enter number: ";
    cin >> number;
    if (number == 0) {
        cout << "Digits: 1\nSum: 0\nAverage: 0\nZeros: 1\n";
        return;
    }
    long long temp = number;
    int count = 0, sum = 0, zeros = 0;
    while (temp != 0) {
        int digit = temp % 10;
        sum += digit;
        if (digit == 0) zeros++;
        count++;
        temp /= 10;
    }
    cout << "Digits: " << count << "\n";
    cout << "Sum: " << sum << "\n";
    cout << "Average: " << static_cast<double>(sum) / count << "\n";
    cout << "Zeros: " << zeros << "\n";
}

void task14() {
    int size;
    cout << "Enter cell size: ";
    cin >> size;
    for (int i = 0; i < 8; ++i) {
        for (int line = 0; line < size; ++line) {
            for (int j = 0; j < 8; ++j) {
                char symbol = ((i + j) % 2 == 0) ? '*' : '-';
                for (int k = 0; k < size; ++k) {
                    cout << symbol;
                }
            }
            cout << "\n";
        }
    }
}

void task15() {
    int people;
    cout << "How many people? ";
    cin >> people;
    double total = 0;
    for (int p = 0; p < people; ++p) {
        cout << "\nMenu: 1-coffee(2), 2-tea(1.5), 3-bun(3), 4-cake(5), 0-done\n";
        double personSum = 0;
        int choice;
        do {
            cout << "Select item: ";
            cin >> choice;
            if (choice == 1) personSum += 2;
            else if (choice == 2) personSum += 1.5;
            else if (choice == 3) personSum += 3;
            else if (choice == 4) personSum += 5;
        } while (choice != 0);
        total += personSum;
    }
    cout << "Bill: $" << total << "\n";
}

void task16() {
    char symbol;
    int speedOption, lineType;
    cout << "Symbol: ";
    cin >> symbol;
    cout << "Speed (1-slow 2-normal 3-fast): ";
    cin >> speedOption;
    cout << "Line type (1-vertical 2-horizontal): ";
    cin >> lineType;
    int delay = (speedOption == 1) ? 1000 : (speedOption == 2 ? 500 : 0);

    if (lineType == 1) {
        for (int i = 0; i < 10; ++i) {
            Sleep(delay);
            cout << symbol << "\n";
        }
    } else {
        for (int i = 0; i < 10; ++i) {
            Sleep(delay);
            cout << symbol;
        }
        cout << "\n";
    }
}

void task17() {
    srand(static_cast<unsigned>(time(nullptr)));
    int playerPoints = 0, botPoints = 0;
    cout << "Bot rolls the dice...\n";
    Sleep(1000);
    for (int round = 1; round <= 3; ++round) {
        playerPoints += rand() % 6 + 1;
        playerPoints += rand() % 6 + 1;
        botPoints += rand() % 6 + 1;
        botPoints += rand() % 6 + 1;
    }
    cout << "Player points: " << playerPoints << "\n";
    cout << "Bot points: " << botPoints << "\n";
    if (playerPoints > botPoints) cout << "You win!\n";
    else if (botPoints > playerPoints) cout << "Bot wins!\n";
    else cout << "Draw!\n";
}

void task18() {
    srand(static_cast<unsigned>(time(nullptr)));
    int choice;
    cout << "Level (1:1-10, 2:10-100): ";
    cin >> choice;
    int a, b, lives;
    if (choice == 1) {
        a = 1; b = 10; lives = (b - a + 1) / 2;
    } else if (choice == 2) {
        a = 10; b = 100; lives = (b - a + 1) / 4;
    } else {
        cout << "Unknown level.\n";
        return;
    }
    int secret = a + rand() % (b - a + 1);
    bool won = false;
    while (lives > 0) {
        int guess;
        cout << "Guess (" << lives << " lives): ";
        cin >> guess;
        if (guess == secret) {
            won = true;
            break;
        }
        lives--;
        if (lives <= 0) break;
        int hint;
        cout << "Hint? (1 yes /0 no, costs 1 life): ";
        cin >> hint;
        if (hint == 1) {
            lives--;
            cout << (guess < secret ? "Higher\n" : "Lower\n");
        }
    }
    if (won) {
        int points = (choice == 1) ? lives * 5 : lives * 10;
        cout << "Victory! Points: " << points << "\n";
    } else {
        cout << "Defeat.\n";
    }
}

void task19() {
    srand(static_cast<unsigned>(time(nullptr)));
    int totalScore = 0;
    // First stage: easier rounds with fewer numbers.
    for (int round = 1; round <= 3; ++round) {
        int secret = 1 + rand() % 10;
        int lives = 5;
        bool won = false;
        cout << "Level 1 round " << round << "\n";
        while (lives > 0) {
            int guess;
            cout << "Guess (1-10): ";
            cin >> guess;
            if (guess == secret) {
                won = true;
                break;
            }
            lives--;
            cout << (guess < secret ? "Higher\n" : "Lower\n");
        }
        if (won) {
            totalScore += lives * 5;
            cout << "Round won! + " << lives * 5 << " points\n";
        } else {
            cout << "Round lost.\n";
        }
    }
    cout << "Score after level 1: " << totalScore << "\n";
    if (totalScore == 0) {
        cout << "Game over.\n";
        return;
    }
    char cont;
    cout << "Continue to level 2? (y/n): ";
    cin >> cont;
    if (cont != 'y') {
        cout << "Final score: " << totalScore << "\n";
        return;
    }
    for (int round = 1; round <= 2; ++round) {
        int secret = 10 + rand() % 91;
        int lives = 23;
        bool won = false;
        cout << "Level 2 round " << round << "\n";
        while (lives > 0) {
            int guess;
            cout << "Guess (10-100): ";
            cin >> guess;
            if (guess == secret) {
                won = true;
                break;
            }
            lives--;
            cout << (guess < secret ? "Higher\n" : "Lower\n");
        }
        if (won) {
            totalScore += lives * 10;
            cout << "Round won! + " << lives * 10 << " points\n";
        } else {
            cout << "Round lost.\n";
        }
    }
    cout << "Final score: " << totalScore << "\n";
}

void task20() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    cout << "Common divisors:\n";
    int limit = min(a, b);
    for (int i = 1; i <= limit; ++i) {
        if (a % i == 0 && b % i == 0) {
            cout << i << "\n";
        }
    }
}

void task21() {
    cout << "Grid coordinates:\n";
    for (int row = 0; row <= 9; ++row) {
        for (char col = 'A'; col <= 'J'; ++col) {
            cout << col << row << " ";
        }
        cout << "\n";
    }
}

int main() {

    while (true) {
        cout << "\n=== Mixed Practice ===\n";
        cout << "1. Sum to 500\n";
        cout << "2. Power function\n";
        cout << "3. Average 1..1000\n";
        cout << "4. Product from a to 20\n";
        cout << "5. Multiplication table\n";
        cout << "6. Count numbers with two equal digits\n";
        cout << "7. Count numbers with unique digits\n";
        cout << "8. Remove digits 3 and 6\n";
        cout << "9. Find B for given A\n";
        cout << "10. Compare cube and square\n";
        cout << "11. List divisors\n";
        cout << "12. Draw shapes\n";
        cout << "13. Digit statistics\n";
        cout << "14. Chessboard printer\n";
        cout << "15. Cafe order\n";
        cout << "16. Animated line\n";
        cout << "17. Dice duel\n";
        cout << "18. Guessing level game\n";
        cout << "19. Multi-round guessing\n";
        cout << "20. Common divisors\n";
        cout << "21. Coordinate grid\n";
        cout << "0. Exit\n";
        cout << "Select: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: task1(); break;
        case 2: task2(); break;
        case 3: task3(); break;
        case 4: task4(); break;
        case 5: task5(); break;
        case 6: task6(); break;
        case 7: task7(); break;
        case 8: task8(); break;
        case 9: task9(); break;
        case 10: task10(); break;
        case 11: task11(); break;
        case 12: task12(); break;
        case 13: task13(); break;
        case 14: task14(); break;
        case 15: task15(); break;
        case 16: task16(); break;
        case 17: task17(); break;
        case 18: task18(); break;
        case 19: task19(); break;
        case 20: task20(); break;
        case 21: task21(); break;
        case 0: return 0;
        default: cout << "Unknown option.\n"; break;
        }
    }
}
