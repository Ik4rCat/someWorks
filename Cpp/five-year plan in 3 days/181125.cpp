#include <iostream>
#include <ctime>
#include <algorithm>
#include <string>
#include <climits>
using namespace std;

void task1() {
    const int n = 10;
    int values[n];
    srand(static_cast<unsigned>(time(nullptr)));
    int minVal = INT_MAX, maxVal = INT_MIN;
    for (int i = 0; i < n; ++i) {
        values[i] = 10 + rand() % 10;
        minVal = min(minVal, values[i]);
        maxVal = max(maxVal, values[i]);
        cout << values[i] << " ";
    }
    cout << "\nMin: " << minVal << " Max: " << maxVal << "\n";
}

void task2() {
    const int n = 10;
    int values[n];
    int a, b, level;
    cout << "Range start: ";
    cin >> a;
    cout << "Range end: ";
    cin >> b;
    cout << "Threshold: ";
    cin >> level;
    srand(static_cast<unsigned>(time(nullptr)));
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        values[i] = a + rand() % (b - a + 1);
        cout << values[i] << " ";
        if (values[i] < level) sum += values[i];
    }
    cout << "\nSum below threshold: " << sum << "\n";
}

void task3() {
    const int months = 12;
    int profit[months];
    for (int i = 0; i < months; ++i) {
        cout << "Profit for month " << i + 1 << ": ";
        cin >> profit[i];
    }
    int start, end;
    cout << "Start month (1-12): ";
    cin >> start;
    cout << "End month (1-12): ";
    cin >> end;
    start--; end--;
    int minIdx = start, maxIdx = start;
    for (int i = start; i <= end; ++i) {
        if (profit[i] < profit[minIdx]) minIdx = i;
        if (profit[i] > profit[maxIdx]) maxIdx = i;
    }
    cout << "Min at month " << minIdx + 1 << "\n";
    cout << "Max at month " << maxIdx + 1 << "\n";
}

void task4() {
    int n;
    cout << "Array size: ";
    cin >> n;
    double* arr = new double[n];
    for (int i = 0; i < n; ++i) {
        cout << "arr[" << i << "]: ";
        cin >> arr[i];
    }

    double sumNeg = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] < 0) sumNeg += arr[i];
    }

    int minIdx = 0, maxIdx = 0;
    for (int i = 1; i < n; ++i) {
        if (arr[i] < arr[minIdx]) minIdx = i;
        if (arr[i] > arr[maxIdx]) maxIdx = i;
    }
    int left = min(minIdx, maxIdx);
    int right = max(minIdx, maxIdx);
    double prodMid = (right - left > 1) ? 1 : 0;
    bool hasMid = right - left > 1;
    for (int i = left + 1; i < right; ++i) {
        prodMid *= arr[i];
    }
    if (!hasMid) prodMid = 0;

    double prodEvenIdx = 1;
    for (int i = 0; i < n; i += 2) {
        prodEvenIdx *= arr[i];
    }

    int firstNeg = -1, lastNeg = -1;
    for (int i = 0; i < n; ++i) {
        if (arr[i] < 0) {
            if (firstNeg == -1) firstNeg = i;
            lastNeg = i;
        }
    }
    double sumBetween = 0;
    if (firstNeg != -1 && lastNeg - firstNeg > 1) {
        for (int i = firstNeg + 1; i < lastNeg; ++i) {
            sumBetween += arr[i];
        }
    }

    cout << "Sum of negatives: " << sumNeg << "\n";
    cout << "Product between min/max: " << prodMid << "\n";
    cout << "Product of even indices: " << prodEvenIdx << "\n";
    cout << "Sum between first/last negatives: " << sumBetween << "\n";
    delete[] arr;
}

void task5() {
    const int n = 10, m = 5;
    int source[n], first[m], second[m];
    srand(static_cast<unsigned>(time(nullptr)));
    for (int i = 0; i < n; ++i) {
        source[i] = rand() % 100;
    }
    for (int i = 0; i < m; ++i) {
        first[i] = source[i];
        second[i] = source[i + m];
    }
    cout << "First half vs second half:\n";
    for (int i = 0; i < m; ++i) {
        cout << first[i] << "\t" << second[i] << "\n";
    }
}

void task6() {
    const int n = 10;
    int a[n], b[n], c[n];
    srand(static_cast<unsigned>(time(nullptr)));
    for (int i = 0; i < n; ++i) {
        a[i] = rand() % 50;
        b[i] = rand() % 50;
        c[i] = a[i] + b[i];
        cout << a[i] << " + " << b[i] << " = " << c[i] << "\n";
    }
}

void task7() {
    const int days = 7;
    string names[days] = { "Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday" };
    double expenses[days];
    double total = 0;
    int over100 = 0;
    for (int i = 0; i < days; ++i) {
        cout << "Expenses for " << names[i] << ": ";
        cin >> expenses[i];
        total += expenses[i];
        if (expenses[i] > 100) over100++;
    }
    double average = total / days;
    cout << "Average: " << average << "\n";
    cout << "Total: " << total << "\n";
    cout << "Days over 100: " << over100 << "\n";
    if (over100 > 0) {
        cout << "These days exceeded 100:\n";
        for (int i = 0; i < days; ++i) {
            if (expenses[i] > 100) cout << names[i] << "\n";
        }
    }
}

void task8() {
    const int months = 12;
    double rate[months], interest[months], deposit;
    cout << "Deposit in EUR: ";
    cin >> deposit;
    for (int i = 0; i < months; ++i) {
        cout << "USD/EUR rate for month " << i + 1 << ": ";
        cin >> rate[i];
        cout << "Interest in EUR for month " << i + 1 << ": ";
        cin >> interest[i];
    }
    int month;
    cout << "Select month (1-12): ";
    cin >> month;
    month--;
    double payoutUSD = interest[month] * rate[month];
    if (payoutUSD >= 500) {
        cout << "You may withdraw $" << payoutUSD * 0.5 << "\n";
    } else {
        cout << "Cannot withdraw (less than $500 earned).\n";
    }
}

void task9() {
    const int n = 5;
    long long mobile[n], home[n];
    bool filled = false;
    int choice;
    do {
        cout << "1 Enter\n2 Show\n3 Sort by mobile\n4 Sort by home\n5 Exit\n";
        cin >> choice;
        if (choice == 1) {
            for (int i = 0; i < n; ++i) {
                cout << "Mobile " << i + 1 << ": ";
                cin >> mobile[i];
                cout << "Home " << i + 1 << ": ";
                cin >> home[i];
            }
            filled = true;
        } else if (choice == 2) {
            if (!filled) { cout << "No data.\n"; continue; }
            cout << "ID\tMobile\tHome\n";
            for (int i = 0; i < n; ++i) {
                cout << i + 1 << "\t" << mobile[i] << "\t" << home[i] << "\n";
            }
        } else if (choice == 3 || choice == 4) {
            if (!filled) { cout << "No data.\n"; continue; }
            for (int i = 0; i < n - 1; ++i) {
                for (int j = 0; j < n - 1 - i; ++j) {
                    bool needSwap = (choice == 3) ? (mobile[j] > mobile[j + 1]) : (home[j] > home[j + 1]);
                    if (needSwap) {
                        swap(mobile[j], mobile[j + 1]);
                        swap(home[j], home[j + 1]);
                    }
                }
            }
            cout << "Sorted.\n";
        }
    } while (choice != 5);
}

void task10() {
    const int n = 10;
    int arr[n];
    cout << "Enter 10 integers:\n";
    for (int i = 0; i < n; ++i) cin >> arr[i];
    for (int i = 0; i < n - 1; ++i) {
        int swaps = 0;
        for (int j = 0; j < n - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swaps++;
            }
        }
        if (swaps == 0) {
            cout << "Early stop at pass " << i + 1 << "\n";
            break;
        }
    }
    cout << "Sorted array:\n";
    for (int value : arr) cout << value << " ";
    cout << "\n";
}

void task11() {
    int n;
    cout << "Number of pancakes: ";
    cin >> n;
    int* radius = new int[n];
    cout << "Enter radii:\n";
    for (int i = 0; i < n; ++i) cin >> radius[i];
    for (int i = 0; i < n - 1; ++i) {
        int maxIdx = 0;
        for (int j = 1; j < n - i; ++j) {
            if (radius[j] > radius[maxIdx]) maxIdx = j;
        }
        if (maxIdx != n - 1 - i) {
            reverse(radius, radius + maxIdx + 1);
            reverse(radius, radius + n - i);
        }
    }
    cout << "Sorted pancakes:\n";
    for (int i = 0; i < n; ++i) cout << radius[i] << " ";
    cout << "\n";
    delete[] radius;
}

void task12() {
    const int size = 1000;
    const int tests = 10;
    int totalBubble = 0, totalSelection = 0;
    srand(static_cast<unsigned>(time(nullptr)));
    // Run multiple trials to smooth random noise.
    for (int t = 0; t < tests; ++t) {
        int a[size], b[size];
        for (int i = 0; i < size; ++i) {
            a[i] = b[i] = rand() % 1000;
        }
        int bubbleSwaps = 0;
        for (int i = 0; i < size - 1; ++i) {
            int local = 0;
            for (int j = 0; j < size - 1 - i; ++j) {
                if (a[j] > a[j + 1]) {
                    swap(a[j], a[j + 1]);
                    bubbleSwaps++;
                    local++;
                }
            }
            if (local == 0) break;
        }
        int selectionSwaps = 0;
        for (int i = 0; i < size - 1; ++i) {
            int minIdx = i;
            for (int j = i + 1; j < size; ++j) {
                if (b[j] < b[minIdx]) minIdx = j;
            }
            if (minIdx != i) {
                swap(b[i], b[minIdx]);
                selectionSwaps++;
            }
        }
        totalBubble += bubbleSwaps;
        totalSelection += selectionSwaps;
    }
    cout << "Average swaps bubble: " << totalBubble / tests << "\n";
    cout << "Average swaps selection: " << totalSelection / tests << "\n";
}

void task13() {
    int rows, cols, start;
    cout << "Rows: ";
    cin >> rows;
    cout << "Columns: ";
    cin >> cols;
    cout << "Start number: ";
    cin >> start;
    int** mat = new int*[rows];
    for (int i = 0; i < rows; ++i) mat[i] = new int[cols];
    mat[0][0] = start;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i == 0 && j == 0) continue;
            if (j == 0) mat[i][j] = mat[i - 1][cols - 1] * 2;
            else mat[i][j] = mat[i][j - 1] * 2;
        }
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) cout << mat[i][j] << "\t";
        cout << "\n";
    }
    for (int i = 0; i < rows; ++i) delete[] mat[i];
    delete[] mat;
}

void task14() {
    int rows, cols, start;
    cout << "Rows: ";
    cin >> rows;
    cout << "Columns: ";
    cin >> cols;
    cout << "Start number: ";
    cin >> start;
    int** mat = new int*[rows];
    for (int i = 0; i < rows; ++i) mat[i] = new int[cols];
    mat[0][0] = start;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i == 0 && j == 0) continue;
            if (j == 0) mat[i][j] = mat[i - 1][cols - 1] + 1;
            else mat[i][j] = mat[i][j - 1] + 1;
        }
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) cout << mat[i][j] << "\t";
        cout << "\n";
    }
    for (int i = 0; i < rows; ++i) delete[] mat[i];
    delete[] mat;
}

void task15() {
    int rows, cols;
    cout << "Matrix size (rows cols): ";
    cin >> rows >> cols;
    int** mat = new int*[rows];
    srand(static_cast<unsigned>(time(nullptr)));
    for (int i = 0; i < rows; ++i) {
        mat[i] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            mat[i][j] = rand() % 10;
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
    int steps;
    string direction;
    cout << "Shift steps: ";
    cin >> steps;
    cout << "Direction (left/right): ";
    cin >> direction;
    steps %= cols;
    if (direction == "right") {
        for (int i = 0; i < rows; ++i) {
            int* temp = new int[steps];
            for (int k = 0; k < steps; ++k) temp[k] = mat[i][cols - steps + k];
            for (int j = cols - 1; j >= steps; --j) mat[i][j] = mat[i][j - steps];
            for (int k = 0; k < steps; ++k) mat[i][k] = temp[k];
            delete[] temp;
        }
    } else if (direction == "left") {
        for (int i = 0; i < rows; ++i) {
            int* temp = new int[steps];
            for (int k = 0; k < steps; ++k) temp[k] = mat[i][k];
            for (int j = 0; j < cols - steps; ++j) mat[i][j] = mat[i][j + steps];
            for (int k = 0; k < steps; ++k) mat[i][cols - steps + k] = temp[k];
            delete[] temp;
        }
    }
    cout << "After shift:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) cout << mat[i][j] << " ";
        cout << "\n";
    }
    for (int i = 0; i < rows; ++i) delete[] mat[i];
    delete[] mat;
}


int main() {
    while (true) {
        cout << "\n=== Array and Matrix Lab ===\n";
        cout << "1. Random stats\n";
        cout << "2. Sum below level\n";
        cout << "3. Profit analysis\n";
        cout << "4. Double array analytics\n";
        cout << "5. Split array halves\n";
        cout << "6. Vector addition\n";
        cout << "7. Weekly expenses\n";
        cout << "8. Deposit helper\n";
        cout << "9. Phone records\n";
        cout << "10. Bubble sort with break\n";
        cout << "11. Pancake sort\n";
        cout << "12. Sort comparison\n";
        cout << "13. Matrix doubling\n";
        cout << "14. Matrix increment\n";
        cout << "15. Matrix shift\n";
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