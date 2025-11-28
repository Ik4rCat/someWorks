#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

void task1() {
    double base;
    int exponent;
    cout << "Enter base: ";
    cin >> base;
    cout << "Enter exponent: ";
    cin >> exponent;

    double result = 1.0;
    // Manual exponentiation to keep the logic explicit.
    bool negative = exponent < 0;
    int absExponent = negative ? -exponent : exponent;

    for (int i = 0; i < absExponent; ++i) {
        result *= base;
    }

    if (negative) {
        result = 1.0 / result;
    }

    cout << "Result: " << result << "\n";
}

void task2() {
    int a, b;
    cout << "Enter first integer: ";
    cin >> a;
    cout << "Enter second integer: ";
    cin >> b;

    const int start = min(a, b);
    const int end = max(a, b);
    int sum = 0;
    for (int i = start; i <= end; ++i) {
        sum += i;
    }
    cout << "Sum: " << sum << "\n";
}

void task3() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    int sum = 0;
    for (int i = 1; i < n; ++i) {
        if (n % i == 0) {
            sum += i;
        }
    }

    cout << (sum == n ? "Perfect number\n" : "Not a perfect number\n");
}

void task4() {
    int num;
    cout << "Enter a number (1-3999): ";
    cin >> num;

    if (num < 1 || num > 3999) {
        cout << "Out of range\n";
        return;
    }

    int thousands = num / 1000;
    int hundreds = (num % 1000) / 100;
    int tens = (num % 100) / 10;
    int ones = num % 10;

    cout << "Roman numeral: ";
    for (int i = 0; i < thousands; ++i) cout << "M";

    if (hundreds == 9) cout << "CM";
    else if (hundreds >= 5) {
        cout << "D";
        for (int i = 0; i < hundreds - 5; ++i) cout << "C";
    }
    else if (hundreds == 4) cout << "CD";
    else for (int i = 0; i < hundreds; ++i) cout << "C";

    if (tens == 9) cout << "XC";
    else if (tens >= 5) {
        cout << "L";
        for (int i = 0; i < tens - 5; ++i) cout << "X";
    }
    else if (tens == 4) cout << "XL";
    else for (int i = 0; i < tens; ++i) cout << "X";

    if (ones == 9) cout << "IX";
    else if (ones >= 5) {
        cout << "V";
        for (int i = 0; i < ones - 5; ++i) cout << "I";
    }
    else if (ones == 4) cout << "IV";
    else for (int i = 0; i < ones; ++i) cout << "I";
    cout << "\n";
}

void task5() {
    int num;
    cout << "Enter a 6-digit number: ";
    cin >> num;

    if (num < 100000 || num > 999999) {
        cout << "The number must have exactly 6 digits\n";
        return;
    }

    int d1 = num / 100000; num %= 100000;
    int d2 = num / 10000;  num %= 10000;
    int d3 = num / 1000;   num %= 1000;
    int d4 = num / 100;    num %= 100;
    int d5 = num / 10;     num %= 10;
    int d6 = num;

    const int sum1 = d1 + d2 + d3;
    const int sum2 = d4 + d5 + d6;
    cout << (sum1 == sum2 ? "Lucky number\n" : "Not a lucky number\n");
}

void task6() {
    int d1, m1, y1, d2, m2, y2;
    cout << "Enter first date (d m y): ";
    cin >> d1 >> m1 >> y1;
    cout << "Enter second date (d m y): ";
    cin >> d2 >> m2 >> y2;

    const int days1 = y1 * 365 + m1 * 30 + d1;
    const int days2 = y2 * 365 + m2 * 30 + d2;
    cout << "Difference in days: " << abs(days2 - days1) << "\n";
}

void task7() {
    int n;
    cout << "Enter array size: ";
    cin >> n;
    if (n <= 0) {
        cout << "Size must be positive\n";
        return;
    }

    double* arr = new double[n];
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        cout << "arr[" << i << "]: ";
        cin >> arr[i];
        sum += arr[i];
    }

    cout << "Average: " << sum / n << "\n";
    delete[] arr;
}

void task8() {
    int n;
    cout << "Enter array size: ";
    cin >> n;
    if (n <= 0) {
        cout << "Size must be positive\n";
        return;
    }

    int* arr = new int[n];
    int positives = 0, negatives = 0, zeros = 0;
    // Single pass classification of signs.
    for (int i = 0; i < n; ++i) {
        cout << "arr[" << i << "]: ";
        cin >> arr[i];
        if (arr[i] > 0) positives++;
        else if (arr[i] < 0) negatives++;
        else zeros++;
    }

    cout << "Positive: " << positives << "\n";
    cout << "Negative: " << negatives << "\n";
    cout << "Zeros: " << zeros << "\n";
    delete[] arr;
}

void task9() {
    int n;
    cout << "Enter size of square matrix: ";
    cin >> n;
    if (n <= 0) {
        cout << "Size must be positive\n";
        return;
    }

    int** mat = new int*[n];
    for (int i = 0; i < n; ++i) {
        mat[i] = new int[n];
    }

    cout << "Enter matrix values:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> mat[i][j];
        }
    }

    int minVal = mat[0][0];
    int maxVal = mat[0][0];
    for (int i = 0; i < n; ++i) {
        if (mat[i][i] < minVal) minVal = mat[i][i];
        if (mat[i][i] > maxVal) maxVal = mat[i][i];
    }

    cout << "Min on main diagonal: " << minVal << "\n";
    cout << "Max on main diagonal: " << maxVal << "\n";

    for (int i = 0; i < n; ++i) delete[] mat[i];
    delete[] mat;
}

void task10() {
    int rows, cols;
    cout << "Enter rows and columns: ";
    cin >> rows >> cols;
    if (rows <= 0 || cols <= 0) {
        cout << "Dimensions must be positive\n";
        return;
    }

    int** mat = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        mat[i] = new int[cols];
    }

    cout << "Enter matrix values:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> mat[i][j];
        }
    }

    // Bubble sort each row to keep implementation simple.
    for (int i = 0; i < rows; ++i) {
        for (int pass = 0; pass < cols - 1; ++pass) {
            for (int j = 0; j < cols - 1 - pass; ++j) {
                if (mat[i][j] > mat[i][j + 1]) {
                    int tmp = mat[i][j];
                    mat[i][j] = mat[i][j + 1];
                    mat[i][j + 1] = tmp;
                }
            }
        }
    }

    cout << "Sorted matrix:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }

    for (int i = 0; i < rows; ++i) delete[] mat[i];
    delete[] mat;
}

void task11() {
    srand(static_cast<unsigned>(time(nullptr)));
    // Generate a 4-digit secret with a non-zero leading digit.
    const int secret = 1000 + rand() % 9000;
    int attempts = 0;
    cout << "Guess the 4-digit number\n";

    while (true) {
        int guess;
        cout << "Your guess: ";
        cin >> guess;
        attempts++;

        int s1 = secret / 1000;
        int s2 = (secret / 100) % 10;
        int s3 = (secret / 10) % 10;
        int s4 = secret % 10;

        int g1 = guess / 1000;
        int g2 = (guess / 100) % 10;
        int g3 = (guess / 10) % 10;
        int g4 = guess % 10;

        int bulls = 0, cows = 0;
        if (g1 == s1) bulls++;
        if (g2 == s2) bulls++;
        if (g3 == s3) bulls++;
        if (g4 == s4) bulls++;

        if (g1 == s2 || g1 == s3 || g1 == s4) cows++;
        if (g2 == s1 || g2 == s3 || g2 == s4) cows++;
        if (g3 == s1 || g3 == s2 || g3 == s4) cows++;
        if (g4 == s1 || g4 == s2 || g4 == s3) cows++;

        cout << "Bulls: " << bulls << ", Cows: " << cows << "\n";
        if (bulls == 4) {
            cout << "You win in " << attempts << " attempts!\n";
            break;
        }
    }
}

int main() {
    while (true) {
        cout << "\n=== Mixed Tasks ===\n";
        cout << "1. Power function\n";
        cout << "2. Sum between numbers\n";
        cout << "3. Perfect number check\n";
        cout << "4. Roman numeral converter\n";
        cout << "5. Lucky ticket check\n";
        cout << "6. Date difference (simplified)\n";
        cout << "7. Average of numbers\n";
        cout << "8. Count positives/negatives/zeros\n";
        cout << "9. Diagonal min/max\n";
        cout << "10. Sort each matrix row\n";
        cout << "11. Bulls and cows game\n";
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
        case 0: return 0;
        default: cout << "Unknown option.\n"; break;
        }
    }
}
