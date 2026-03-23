#include <iostream>
#include "ReservoirArray.h"

int main() {
    ReservoirArray reservoirs;
    int choice;
    
    cout << "===== RESERVOIR MANAGER =====" << endl;
    
    while (true) {
        cout << "\n1. Add Reservoir" << endl;
        cout << "2. Remove Reservoir" << endl;
        cout << "3. Display All Reservoirs" << endl;
        cout << "4. Compare Two Reservoirs" << endl;
        cout << "5. Test Copy Constructor" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();
        
        if (choice == 0) {
            break;
        }
        
        switch (choice) {
            case 1: {
                Reservoir reservoir;
                reservoir.input();
                reservoirs.addReservoir(reservoir);
                cout << "Reservoir added" << endl;
                break;
            }
            case 2: {
                int index;
                cout << "Enter reservoir number to remove: ";
                cin >> index;
                cin.ignore();
                reservoirs.removeReservoir(index - 1);
                cout << "Reservoir removed" << endl;
                break;
            }
            case 3: {
                reservoirs.displayAll();
                break;
            }
            case 4: {
                if (reservoirs.getCount() < 2) {
                    cout << "Need at least 2 reservoirs" << endl;
                    break;
                }
                
                int idx1, idx2;
                cout << "Enter first reservoir number: ";
                cin >> idx1;
                cout << "Enter second reservoir number: ";
                cin >> idx2;
                cin.ignore();
                
                Reservoir r1 = reservoirs.getReservoir(idx1 - 1);
                Reservoir r2 = reservoirs.getReservoir(idx2 - 1);
                
                cout << "\nComparison:" << endl;
                if (r1.isSameType(r2)) {
                    cout << "Same type: YES" << endl;
                    if (r1.compareSurfaceArea(r2)) {
                        cout << r1.getName() << " has larger surface area" << endl;
                    } else {
                        cout << r2.getName() << " has larger or equal surface area" << endl;
                    }
                } else {
                    cout << "Same type: NO" << endl;
                    cout << r1.getName() << " is " << r1.getType() << endl;
                    cout << r2.getName() << " is " << r2.getType() << endl;
                }
                break;
            }
            case 5: {
                ReservoirArray copy(reservoirs);
                cout << "\nOriginal:" << endl;
                reservoirs.displayAll();
                cout << "\nCopy:" << endl;
                copy.displayAll();
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
