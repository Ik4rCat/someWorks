#include <iostream>
#include "task1/Fraction.h"
#include "task2/Complex.h"

using namespace std;

int main() {
    int choice;
    
    cout << "===== OPERATOR OVERLOADING DEMO =====" << endl;
    
    while (true) {
        cout << "\n1. Test Fraction Class" << endl;
        cout << "2. Test Complex Class" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        
        if (choice == 0) {
            break;
        }
        
        switch (choice) {
            case 1: {
                cout << "\n===== FRACTION CALCULATOR =====" << endl;
                
                Fraction f1, f2;
                
                cout << "\nFirst fraction:" << endl;
                f1.input();
                
                cout << "\nSecond fraction:" << endl;
                f2.input();
                
                cout << "\nResults:" << endl;
                cout << "f1 = ";
                f1.display();
                cout << endl;
                
                cout << "f2 = ";
                f2.display();
                cout << endl;
                
                Fraction sum = f1 + f2;
                cout << "f1 + f2 = ";
                sum.display();
                cout << endl;
                
                Fraction diff = f1 - f2;
                cout << "f1 - f2 = ";
                diff.display();
                cout << endl;
                
                Fraction prod = f1 * f2;
                cout << "f1 * f2 = ";
                prod.display();
                cout << endl;
                
                Fraction quot = f1 / f2;
                cout << "f1 / f2 = ";
                quot.display();
                cout << endl;
                
                break;
            }
            case 2: {
                cout << "\n===== COMPLEX NUMBER CALCULATOR =====" << endl;
                
                Complex c1, c2;
                
                cout << "\nFirst complex number:" << endl;
                c1.input();
                
                cout << "\nSecond complex number:" << endl;
                c2.input();
                
                cout << "\nResults:" << endl;
                cout << "c1 = ";
                c1.display();
                cout << endl;
                
                cout << "c2 = ";
                c2.display();
                cout << endl;
                
                Complex sum = c1 + c2;
                cout << "c1 + c2 = ";
                sum.display();
                cout << endl;
                
                Complex diff = c1 - c2;
                cout << "c1 - c2 = ";
                diff.display();
                cout << endl;
                
                Complex prod = c1 * c2;
                cout << "c1 * c2 = ";
                prod.display();
                cout << endl;
                
                Complex quot = c1 / c2;
                cout << "c1 / c2 = ";
                quot.display();
                cout << endl;
                
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
