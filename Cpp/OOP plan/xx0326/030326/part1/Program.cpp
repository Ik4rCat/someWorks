#include "task1/MyString.h"
#include "task2/Date.h"
#include "task3/Array.h"

int main() {
    int choice;
    
    cout << "===== OPERATOR OVERLOADING TEST =====" << endl;
    
    while (true) {
        cout << "\n1. Test MyString Operators" << endl;
        cout << "2. Test Date Operators" << endl;
        cout << "3. Test Array Operators" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();
        
        if (choice == 0) {
            break;
        }
        
        switch (choice) {
            case 1: {
                cout << "\n===== MYSTRING OPERATORS =====" << endl;
                
                MyString s1("Hello World");
                cout << "String: ";
                s1.output();
                cout << endl;
                
                cout << "s1[0] = " << s1[0] << endl;
                cout << "s1[6] = " << s1[6] << endl;
                
                cout << "s1('o') = " << s1('o') << " (index of 'o')" << endl;
                cout << "s1('z') = " << s1('z') << " (not found)" << endl;
                
                int len = (int)s1;
                cout << "(int)s1 = " << len << " (string length)" << endl;
                
                break;
            }
            case 2: {
                cout << "\n===== DATE OPERATORS =====" << endl;
                
                Date d1(15, 3, 2024);
                Date d2(20, 3, 2024);
                
                cout << "d1 = " << d1 << endl;
                cout << "d2 = " << d2 << endl;
                
                cout << "\nIncrement d1 (++d1): ";
                ++d1;
                cout << d1 << endl;
                
                cout << "Decrement d2 (--d2): ";
                --d2;
                cout << d2 << endl;
                
                cout << "\nd1 == d2: " << (d1 == d2 ? "Yes" : "No") << endl;
                cout << "d1 != d2: " << (d1 != d2 ? "Yes" : "No") << endl;
                cout << "d1 < d2: " << (d1 < d2 ? "Yes" : "No") << endl;
                cout << "d1 > d2: " << (d1 > d2 ? "Yes" : "No") << endl;
                
                Date d3(1, 1, 2024);
                d3 += 50;
                cout << "\nd3 (2024-01-01) + 50 days = " << d3 << endl;
                
                Date d4(15, 3, 2024);
                Date d5(20, 3, 2024);
                int days = d4(d5);
                cout << "Days between d4 and d5: " << days << endl;
                
                break;
            }
            case 3: {
                cout << "\n===== ARRAY OPERATORS =====" << endl;
                
                Array arr(5);
                arr[0] = 10;
                arr[1] = 20;
                arr[2] = 30;
                arr[3] = 40;
                arr[4] = 50;
                
                cout << "Array: ";
                arr.display();
                
                cout << "arr[2] = " << arr[2] << endl;
                
                cout << "\nCalling arr(100) - add 100 to all elements" << endl;
                arr(100);
                cout << "Array: ";
                arr.display();
                
                int sum = (int)arr;
                cout << "(int)arr = " << sum << " (sum of elements)" << endl;
                
                char* str = (char*)arr;
                cout << "(char*)arr = " << str << endl;
                delete[] str;
                
                break;
            }
            default: {
                cout << "Invalid choice" << endl;
            }
        }
    }
    
    cout << "Goodbye!" << endl;
    return 0;
}
