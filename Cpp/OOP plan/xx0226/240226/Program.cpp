#include <iostream>
#include "task1/IntegerSet.h"
#include "task2/Overcoat.h"

using namespace std;

int main() {
    int choice;
    
    cout << "===== HOMEWORK TEST PROGRAM =====" << endl;
    
    while (true) {
        cout << "\n1. Test IntegerSet Class" << endl;
        cout << "2. Test Overcoat Class" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();
        
        if (choice == 0) {
            break;
        }
        
        switch (choice) {
            case 1: {
                cout << "\n===== INTEGER SET TEST =====" << endl;
                
                IntegerSet set1, set2;
                
                cout << "\nCreate Set 1:" << endl;
                cin >> set1;
                
                cout << "\nCreate Set 2:" << endl;
                cin >> set2;
                
                cout << "\nSet 1: " << set1 << endl;
                cout << "Set 2: " << set2 << endl;
                
                IntegerSet unionSet = set1 + set2;
                cout << "\nUnion (set1 + set2): " << unionSet << endl;
                
                IntegerSet diffSet = set1 - set2;
                cout << "Difference (set1 - set2): " << diffSet << endl;
                
                IntegerSet intersectSet = set1 * set2;
                cout << "Intersection (set1 * set2): " << intersectSet << endl;
                
                cout << "\nAdd element 100 to set1" << endl;
                set1 += 100;
                cout << "Set 1: " << set1 << endl;
                
                cout << "\nRemove element 100 from set1" << endl;
                set1 -= 100;
                cout << "Set 1: " << set1 << endl;
                
                cout << "\nSet 1 == Set 2: " << (set1 == set2 ? "Yes" : "No") << endl;
                
                break;
            }
            case 2: {
                cout << "\n===== OVERCOAT TEST =====" << endl;
                
                Overcoat coat1, coat2, coat3;
                
                cout << "\nEnter coat 1:" << endl;
                coat1.input();
                
                cout << "\nEnter coat 2 (same type):" << endl;
                coat2.input();
                
                cout << "\nEnter coat 3 (different type):" << endl;
                coat3.input();
                
                cout << "\n=== COAT 1 ===" << endl;
                coat1.display();
                
                cout << "\n=== COAT 2 ===" << endl;
                coat2.display();
                
                cout << "\n=== COAT 3 ===" << endl;
                coat3.display();
                
                cout << "\nCoat 1 == Coat 2 (same type): " << (coat1 == coat2 ? "Yes" : "No") << endl;
                cout << "Coat 1 == Coat 3 (same type): " << (coat1 == coat3 ? "Yes" : "No") << endl;
                
                if (coat1 == coat2) {
                    cout << "Coat 1 > Coat 2 (higher price): " << (coat1 > coat2 ? "Yes" : "No") << endl;
                }
                
                Overcoat coat4 = coat1;
                cout << "\nCoat 4 (copy of coat 1):" << endl;
                coat4.display();
                
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
