#include <iostream>
#include "Array.h"

int main() {
    Array arr;
    int choice;
    
    cout << "===== DYNAMIC ARRAY =====" << endl;
    
    while (true) {
        cout << "\n1. Create/Resize Array" << endl;
        cout << "2. Fill Array" << endl;
        cout << "3. Display Array" << endl;
        cout << "4. Sort Array" << endl;
        cout << "5. Get Min Value" << endl;
        cout << "6. Get Max Value" << endl;
        cout << "7. Get Size" << endl;
        cout << "8. Set Element" << endl;
        cout << "9. Get Element" << endl;
        cout << "10. Test Copy Constructor" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        
        if (choice == 0) {
            break;
        }
        
        switch (choice) {
            case 1: {
                int newSize;
                cout << "Enter new size: ";
                cin >> newSize;
                arr.resize(newSize);
                cout << "Array resized to " << newSize << endl;
                break;
            }
            case 2: {
                if (arr.getSize() == 0) {
                    cout << "Array is empty, set size first" << endl;
                } else {
                    arr.fill();
                }
                break;
            }
            case 3: {
                arr.display();
                break;
            }
            case 4: {
                arr.sort();
                cout << "Array sorted" << endl;
                break;
            }
            case 5: {
                cout << "Min value: " << arr.getMin() << endl;
                break;
            }
            case 6: {
                cout << "Max value: " << arr.getMax() << endl;
                break;
            }
            case 7: {
                cout << "Array size: " << arr.getSize() << endl;
                break;
            }
            case 8: {
                int index, value;
                cout << "Enter index: ";
                cin >> index;
                cout << "Enter value: ";
                cin >> value;
                arr.setElement(index, value);
                break;
            }
            case 9: {
                int index;
                cout << "Enter index: ";
                cin >> index;
                cout << "Element at [" << index << "]: " << arr.getElement(index) << endl;
                break;
            }
            case 10: {
                Array arr2(arr);
                cout << "Original array: ";
                arr.display();
                cout << "Copied array: ";
                arr2.display();
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
