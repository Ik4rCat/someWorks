#include <iostream>
#include "task1/Complex.h"
#include "task2/Time.h"

using namespace std;

int main() {
    int choice;
    
    cout << "===== OPERATOR OVERLOADING TEST =====" << endl;
    
    while (true) {
        cout << "\n1. Test Complex Class" << endl;
        cout << "2. Test Time Class" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();
        
        if (choice == 0) {
            break;
        }
        
        switch (choice) {
            case 1: {
                cout << "\n===== COMPLEX NUMBER TEST =====" << endl;
                
                Complex c1, c2;
                
                cout << "\nEnter first complex number:" << endl;
                cin >> c1;
                
                cout << "\nEnter second complex number:" << endl;
                cin >> c2;
                
                cout << "\nc1 = " << c1 << endl;
                cout << "c2 = " << c2 << endl;
                
                Complex sum = c1 + c2;
                cout << "\nc1 + c2 = " << sum << endl;
                
                Complex diff = c1 - c2;
                cout << "c1 - c2 = " << diff << endl;
                
                cout << "\nc1 == c2: " << (c1 == c2 ? "Yes" : "No") << endl;
                cout << "c1 != c2: " << (c1 != c2 ? "Yes" : "No") << endl;
                
                Complex c3;
                c3(5.0, -3.0);
                cout << "\nc3 after c3(5.0, -3.0) = " << c3 << endl;
                
                Complex c4 = 10.0 + c1;
                cout << "10.0 + c1 = " << c4 << endl;
                
                c1 += c2;
                cout << "\nc1 += c2: c1 = " << c1 << endl;
                
                break;
            }
            case 2: {
                cout << "\n===== TIME CLASS TEST =====" << endl;
                
                Time t1, t2;
                
                cout << "\nEnter first time:" << endl;
                cin >> t1;
                
                cout << "\nEnter second time:" << endl;
                cin >> t2;
                
                cout << "\nt1 = " << t1 << endl;
                cout << "t2 = " << t2 << endl;
                
                cout << "\n++t1 = ";
                ++t1;
                cout << t1 << endl;
                
                cout << "t2-- = ";
                Time t3 = t2--;
                cout << t2 << " (was " << t3 << ")" << endl;
                
                cout << "\nt1 == t2: " << (t1 == t2 ? "Yes" : "No") << endl;
                cout << "t1 != t2: " << (t1 != t2 ? "Yes" : "No") << endl;
                cout << "t1 > t2: " << (t1 > t2 ? "Yes" : "No") << endl;
                cout << "t1 < t2: " << (t1 < t2 ? "Yes" : "No") << endl;
                
                Time t4(10, 30, 45);
                t4 += 100;
                cout << "\nt4 (10:30:45) + 100 seconds = " << t4 << endl;
                
                t4 -= 50;
                cout << "t4 - 50 seconds = " << t4 << endl;
                
                Time t5 = t4(23, 59, 50);
                cout << "\nt5 = t5(23, 59, 50) = " << t5 << endl;
                ++t5;
                cout << "++t5 = " << t5 << " (next day)" << endl;
                
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
