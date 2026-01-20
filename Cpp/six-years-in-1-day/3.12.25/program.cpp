#include <iostream>
#include <cmath>
using namespace std;

class Task1
{
public:
    void Program() {
        double** p = new double*[5];
        for (int i = 0; i < 5; i++) {
            p[i] = new double[5];
            for (int j = 0; j < 5; j++) {
                cout << p[i][j] << "\t";
            }
            cout << endl;
        }

        for (int i = 0; i < 5; i++) {
            delete[] p[i];
        }
        delete[] p;
    }
};

class Task2
{
public:
    void Program() {
        int a = 0;
        cout << "Enter number not exceeding 100: ";
        cin >> a;

        if (a <= 0 || a > 100) {
            cout << "Invalid number!" << endl;
            return;
        }

        double** p = new double*[a];
        for (int i = 0; i < a; i++) {
            p[i] = new double[a];
            for (int j = 0; j < a; j++) {
                if (i - j == 0) {
                    p[i][j] = 0;
                }
                else if (abs(i - j) == 1) {
                    p[i][j] = 1;
                }
                else if (abs(i - j) == 2) {
                    p[i][j] = 2;
                }
                else if (abs(i - j) == 3) {
                    p[i][j] = 3;
                }
                else if (abs(i - j) == 4) {
                    p[i][j] = 4;
                }
                else {
                    p[i][j] = abs(i - j);
                }

                cout << p[i][j] << "\t";
            }
            cout << endl;
        }

        for (int i = 0; i < a; i++) {
            delete[] p[i];
        }
        delete[] p;
    }
};

class Task3
{
private:
    double** p;
    int rows;
    int cols;

    void printMatrix() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << p[i][j] << "\t";
            }
            cout << endl;
        }
    }

    void freeMemory() {
        for (int i = 0; i < rows; i++) {
            delete[] p[i];
        }
        delete[] p;
    }

public:
    void Program() {
        int a = 0, b = 0, user = 1;
        cout << "Enter number of rows: ";
        cin >> a;
        cout << "Enter number of seats per row: ";
        cin >> b;

        rows = a;
        cols = b;

        p = new double*[a];
        for (int i = 0; i < a; i++) {
            p[i] = new double[b];
            for (int j = 0; j < b; j++) {
                p[i][j] = 0;
            }
        }

        printMatrix();

        while (user != 0) {
            cout << "1 - Add seats to all rows" << endl;
            cout << "2 - Remove seats from all rows" << endl;
            cout << "3 - Remove row" << endl;
            cout << "0 - Exit" << endl;
            cin >> user;

            switch (user) {
            case 1:
                freeMemory();
                cols = cols + 1;
                p = new double*[rows];
                for (int i = 0; i < rows; i++) {
                    p[i] = new double[cols];
                    for (int j = 0; j < cols; j++) {
                        p[i][j] = 0;
                    }
                }
                printMatrix();
                break;

            case 2:
                if (cols > 1) {
                    freeMemory();
                    cols = cols - 1;
                    p = new double*[rows];
                    for (int i = 0; i < rows; i++) {
                        p[i] = new double[cols];
                        for (int j = 0; j < cols; j++) {
                            p[i][j] = 0;
                        }
                    }
                    printMatrix();
                } else {
                    cout << "Cannot remove more seats!" << endl;
                }
                break;

            case 3:
                if (rows > 1) {
                    freeMemory();
                    rows = rows - 1;
                    p = new double*[rows];
                    for (int i = 0; i < rows; i++) {
                        p[i] = new double[cols];
                        for (int j = 0; j < cols; j++) {
                            p[i][j] = 0;
                        }
                    }
                    printMatrix();
                } else {
                    cout << "Cannot remove more rows!" << endl;
                }
                break;
            }
        }

        freeMemory();
    }
};

int main() {
    Task1 task1;
    Task2 task2;
    Task3 task3;

    while (true) {
        int choice;

        cout << "Choose task:" << endl;
        cout << "1 - Task1" << endl;
        cout << "2 - Task2" << endl;
        cout << "3 - Task3" << endl;
        cout << "0 - Exit" << endl;

        cin >> choice;

        switch (choice) {
        case 1:
            task1.Program();
            break;
        case 2:
            task2.Program();
            break;
        case 3:
            task3.Program();
            break;
        case 0:
            return 0;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    }
}
