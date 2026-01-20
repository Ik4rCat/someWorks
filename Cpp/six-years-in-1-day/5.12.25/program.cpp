#include <iostream>
#include <string>
using namespace std;

class Task1
{
public:
    void Program() {
        cout << "Task 1: Array of odd numbers" << endl;
        
        int numbers[20];
        for (int i = 0; i < 20; i++) {
            numbers[i] = 2 * i + 1; 
        }
        
        int* ptr = numbers; 
        cout << "Forward order (5 per line):" << endl;
        for (int i = 0; i < 20; i++) {
            cout << *ptr << " ";
            if ((i + 1) % 5 == 0) cout << endl; 
            ptr++; 
        }
        
        cout << "\nReverse order:" << endl;
        ptr = &numbers[19]; 
        for (int i = 0; i < 20; i++) {
            cout << *ptr << " ";
            if ((i + 1) % 5 == 0) cout << endl;
            ptr--; 
        }
        cout << endl;
    }
};

class Task2
{
private:
    double power(double num, int exp) {
        double result = 1;
        
        if (exp >= 0) {
            for (int i = 0; i < exp; i++) {
                result *= num;
            }
        } else {
            for (int i = 0; i < -exp; i++) {
                result *= num;
            }
            result = 1 / result;
        }
        
        return result;
    }

public:
    void Program() {
        cout << "Task 2: Exponentiation" << endl;
        
        double num;
        int exp;
        
        cout << "Enter number: ";
        cin >> num;
        cout << "Enter exponent: ";
        cin >> exp;
        
        double result = power(num, exp);
        cout << num << "^" << exp << " = " << result << endl << endl;
    }
};

class Task3
{
private:
    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }

    string add(string a, string b) {
        return a + b;
    }

public:
    void Program() {
        cout << "Task 3: Overloaded add function" << endl;
        
        int a_int = 10, b_int = 20;
        cout << "int: " << a_int << " + " << b_int << " = " << add(a_int, b_int) << endl;
        
        double a_double = 3.14, b_double = 2.86;
        cout << "double: " << a_double << " + " << b_double << " = " << add(a_double, b_double) << endl;

        string a_string = "Hello, ", b_string = "World!";
        cout << "string: \"" << a_string << "\" + \"" << b_string << "\" = \"" << add(a_string, b_string) << "\"" << endl << endl;
    }
};

class Task4
{
public:
    void Program() {
        cout << "Task 4: Dynamic array" << endl;
        
        int size;
        cout << "Enter array size: ";
        cin >> size;
        
        if (size <= 0) {
            cout << "Invalid size!" << endl;
            return;
        }

        int* arr = new int[size];

        for (int i = 0; i < size; i++) {
            arr[i] = i * i; 
        }
        
        cout << "Array: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        
        int sum = 0;
        for (int i = 0; i < size; i++) {
            sum += arr[i];
        }
        cout << "Sum of elements: " << sum << endl;
        
        delete[] arr;
        cout << endl;
    }
};

class Task5
{
public:
    void Program() {
        cout << "Task 5: Students and grades" << endl;
        
        int count;
        cout << "Enter number of students: ";
        cin >> count;
        cin.ignore(); 
        
        if (count <= 0) {
            cout << "Invalid number!" << endl;
            return;
        }
        
        string* names = new string[count];
        int* grades = new int[count];
        
        for (int i = 0; i < count; i++) {
            cout << "Student " << (i + 1) << ":" << endl;
            cout << "  Name: ";
            getline(cin, names[i]);
            cout << "  Grade: ";
            cin >> grades[i];
            cin.ignore(); 
        }
        
        double sum = 0;
        for (int i = 0; i < count; i++) {
            sum += grades[i];
        }
        double average = sum / count;
        
        cout << "\nStudent list:" << endl;
        for (int i = 0; i < count; i++) {
            cout << names[i] << ": " << grades[i] << endl;
        }
        cout << "Average grade: " << average << endl;
        
        delete[] names;
        delete[] grades;
        cout << endl;
    }
};

int main() {
    Task1 task1;
    Task2 task2;
    Task3 task3;
    Task4 task4;
    Task5 task5;

    while (true) {
        int choice;
        
        cout << "Choose task:" << endl;
        cout << "1 - Task1 (Array of odd numbers)" << endl;
        cout << "2 - Task2 (Exponentiation)" << endl;
        cout << "3 - Task3 (Overloaded add function)" << endl;
        cout << "4 - Task4 (Dynamic array)" << endl;
        cout << "5 - Task5 (Students and grades)" << endl;
        cout << "0 - Exit" << endl;
        cout << "Your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: task1.Program(); break;
            case 2: task2.Program(); break;
            case 3: task3.Program(); break;
            case 4: task4.Program(); break;
            case 5: task5.Program(); break;
            case 0: cout << "Program finished." << endl; return 0;
            default: cout << "Invalid choice!" << endl;
        }
    }
}
