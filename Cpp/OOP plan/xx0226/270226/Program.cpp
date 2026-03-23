#include <iostream>
#include "task1/MyString.h"
#include "task2/Array.h"

using namespace std;

int main() {
    int choice;
    
    cout << "===== MOVE CONSTRUCTOR TEST =====" << endl;
    
    while (true) {
        cout << "\n1. Test MyString Move Constructor" << endl;
        cout << "2. Test Array Move Constructor" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();
        
        if (choice == 0) {
            break;
        }
        
        switch (choice) {
            case 1: {
                cout << "\n===== MYSTRING MOVE SEMANTICS =====" << endl;
                
                MyString s1("Hello World");
                cout << "Original string s1: ";
                s1.output();
                cout << " (size: " << s1.getSize() << ")" << endl;
                
                MyString s2(std::move(s1));
                cout << "\nAfter move to s2:" << endl;
                cout << "s2 (moved): ";
                s2.output();
                cout << endl;
                cout << "s1 (after move): ";
                s1.output();
                cout << " (size: " << s1.getSize() << ")" << endl;
                
                MyString s3;
                s3 = std::move(s2);
                cout << "\nAfter move assignment to s3:" << endl;
                cout << "s3 (move assigned): ";
                s3.output();
                cout << endl;
                
                cout << "\nTotal String objects: " << MyString::getObjectCount() << endl;
                
                break;
            }
            case 2: {
                cout << "\n===== ARRAY MOVE SEMANTICS =====" << endl;
                
                Array arr1(5);
                arr1.setElement(0, 10);
                arr1.setElement(1, 20);
                arr1.setElement(2, 30);
                arr1.setElement(3, 40);
                arr1.setElement(4, 50);
                
                cout << "Original array arr1: ";
                arr1.display();
                
                Array arr2(std::move(arr1));
                cout << "\nAfter move to arr2:" << endl;
                cout << "arr2 (moved): ";
                arr2.display();
                cout << "arr1 (after move), size: " << arr1.getSize() << endl;
                
                Array arr3;
                arr3 = std::move(arr2);
                cout << "\nAfter move assignment to arr3:" << endl;
                cout << "arr3 (move assigned): ";
                arr3.display();
                
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
