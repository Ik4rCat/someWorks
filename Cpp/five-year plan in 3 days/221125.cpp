#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void task1() {
    vector<int> values(10);
    int sum = 0;
    // Fill with random data within [1,100] and collect stats.
    for (int i = 0; i < 10; i++) {
        values[i] = rand() % 100 + 1;
        sum += values[i];
        cout << values[i] << " ";
    }
    cout << "\nSum: " << sum << "\nAverage: " << static_cast<double>(sum) / 10 << "\n";
}

void task2() {
    vector<int> values = { 10, 20, 30, 40, 50 };
    int target;
    cout << "Enter a number to search: ";
    cin >> target;
    // Plain linear search to report the first index.
    for (int i = 0; i < static_cast<int>(values.size()); i++) {
        if (values[i] == target) {
            cout << "Index: " << i << "\n";
            return;
        }
    }
    cout << "Index: -1\n";
}

void task3() {
    vector<int> values = { 1,2,3,4,5,6,7,8,9,10 };
    int startIndex;
    cout << "Enter start index: ";
    cin >> startIndex;
    if (startIndex < 0 || startIndex >= static_cast<int>(values.size())) {
        cout << "Invalid index\n";
        return;
    }
    cout << "Even numbers:\n";
    for (int i = startIndex; i < static_cast<int>(values.size()); i++) {
        if (values[i] % 2 == 0) {
            cout << values[i] << " ";
        }
    }
    cout << "\n";
}

void task4() {
    vector<int> values = { 1,2,3,2,1 };
    bool isPalindrome = true;
    for (int i = 0; i < static_cast<int>(values.size()) / 2; i++) {
        if (values[i] != values[values.size() - 1 - i]) {
            isPalindrome = false;
            break;
        }
    }
    cout << (isPalindrome ? "It is a palindrome\n" : "It is not a palindrome\n");
}

void task5() {
    int a[2][3] = { {1,2,3},{4,5,6} };
    int b[3][2] = { {7,8},{9,10},{11,12} };
    int c[2][2] = { {0,0},{0,0} };
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 3; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    cout << "Matrix product:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << c[i][j] << " ";
        }
        cout << "\n";
    }
}

void task6() {
    int m[2][3] = { {1,5,3},{9,2,4} };
    int maxVal = m[0][0], minVal = m[0][0];
    int maxI = 0, maxJ = 0, minI = 0, minJ = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            if (m[i][j] > maxVal) {
                maxVal = m[i][j];
                maxI = i;
                maxJ = j;
            }
            if (m[i][j] < minVal) {
                minVal = m[i][j];
                minI = i;
                minJ = j;
            }
        }
    }
    cout << "Max: " << maxVal << " at (" << maxI << "," << maxJ << ")\n";
    cout << "Min: " << minVal << " at (" << minI << "," << minJ << ")\n";
}

void task7() {
    int rows, cols;
    cout << "Enter rows and cols: ";
    cin >> rows >> cols;
    cout << (rows == cols ? "Matrix is square\n" : "Matrix is not square\n");
}

void task8() {
    vector<int> values = { 1,2,2,3,3,4,5 };
    vector<int> unique;
    for (int value : values) {
        bool found = false;
        for (int uniq : unique) {
            if (value == uniq) {
                found = true;
                break;
            }
        }
        if (!found) {
            unique.push_back(value);
        }
    }
    cout << "Without duplicates:\n";
    for (int value : unique) cout << value << " ";
    cout << "\n";
}

void task9() {
    vector<int> values = { 1,2,3,4,5 };
    int shift;
    cout << "Shift right by: ";
    cin >> shift;
    reverse(values.begin(), values.end());
    shift %= values.size();
    vector<int> result(values.size());
    for (int i = 0; i < static_cast<int>(values.size()); i++) {
        result[(i + shift) % values.size()] = values[i];
    }
    cout << "Shifted values:\n";
    for (int value : result) cout << value << " ";
    cout << "\n";
}

void task10() {
    vector<int> a = { 1,2,3,4,5 };
    vector<int> b = { 3,4,5,6,7 };
    cout << "Common numbers:\n";
    for (int value : a) {
        for (int other : b) {
            if (value == other) {
                cout << value << " ";
                break;
            }
        }
    }
    cout << "\n";
}

void task11() {
    vector<int> values = { -2,1,-3,4,-1,2,1,-5,4 };
    int bestSum = values[0];
    for (int i = 0; i < static_cast<int>(values.size()); i++) {
        int sum = 0;
        // Brute-force every subarray starting at i.
        for (int j = i; j < static_cast<int>(values.size()); j++) {
            sum += values[j];
            if (sum > bestSum) {
                bestSum = sum;
            }
        }
    }
    cout << "Max subarray sum: " << bestSum << "\n";
}

void task12() {
    vector<int> values = { -1,2,-3,4,-5 };
    int replacement;
    cout << "Replace negatives with: ";
    cin >> replacement;
    for (int& value : values) {
        if (value < 0) {
            value = replacement;
        }
    }
    cout << "Result:\n";
    for (int value : values) cout << value << " ";
    cout << "\n";
}

void task13() { 
    cout << "Task 13 is not implemented yet\n"; 
}

void task14() {
    cout << "Task 14 is not implemented yet\n";
}

void task15() {
    cout << "Task 15 is not implemented yet\n";
}

int main() {
    while (true) {
        cout << "\n=== Array Tasks ===\n";
        cout << "1. Random stats\n";
        cout << "2. Linear search\n";
        cout << "3. Even numbers from index\n";
        cout << "4. Check palindrome\n";
        cout << "5. Matrix multiplication\n";
        cout << "6. Matrix min/max\n";
        cout << "7. Check for square matrix\n";
        cout << "8. Remove duplicates\n";
        cout << "9. Right rotation\n";
        cout << "10. Intersection of vectors\n";
        cout << "11. Max subarray sum\n";
        cout << "12. Replace negatives\n";
        cout << "13. Placeholder\n";
        cout << "14. Placeholder\n";
        cout << "15. Placeholder\n";
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
        case 0: return 0;   
        default: cout << "Unknown option.\n"; break;
        }
    }
}

