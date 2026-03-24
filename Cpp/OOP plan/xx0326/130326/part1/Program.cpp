#include <iostream>
#include "Array.h"

using namespace std;

int main() {
    int choice;
    
    cout << "===== TEMPLATE ARRAY CLASS TEST =====" << endl;
    
    while (true) {
        cout << "\n1. Test Array<int>" << endl;
        cout << "2. Test Array<double>" << endl;
        cout << "3. Test Array<string>" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();
        
        if (choice == 0) {
            break;
        }
        
        switch (choice) {
            case 1: {
                cout << "\n===== ARRAY<int> TEST =====" << endl;
                
                Array<int> arr(5, 5);
                cout << "Initial size: " << arr.GetSize() << endl;
                cout << "Is empty: " << (arr.IsEmpty() ? "Yes" : "No") << endl;
                
                arr.Add(10);
                arr.Add(20);
                arr.Add(30);
                cout << "After adding 3 elements: ";
                arr.display();
                cout << "Upper bound: " << arr.GetUpperBound() << endl;
                
                arr.Add(40);
                arr.Add(50);
                arr.Add(60);
                cout << "After adding 6th element (auto resize): ";
                arr.display();
                cout << "New size: " << arr.GetSize() << endl;
                
                cout << "\narr[2] = " << arr[2] << endl;
                arr.SetAt(2, 99);
                cout << "After SetAt(2, 99): ";
                arr.display();
                
                cout << "\nGetAt(1) = " << arr.GetAt(1) << endl;
                
                Array<int> arr2;
                arr2.Add(100);
                arr2.Add(200);
                cout << "\narr2: ";
                arr2.display();
                
                arr.Append(arr2);
                cout << "After arr.Append(arr2): ";
                arr.display();
                
                arr.InsertAt(3, 777);
                cout << "After InsertAt(3, 777): ";
                arr.display();
                
                arr.RemoveAt(3);
                cout << "After RemoveAt(3): ";
                arr.display();
                
                arr.RemoveAt(0, 2);
                cout << "After RemoveAt(0, 2): ";
                arr.display();
                
                Array<int> arr3 = arr;
                cout << "\narr3 (copy): ";
                arr3.display();
                
                cout << "GetData()[0] = " << arr.GetData()[0] << endl;
                
                arr.RemoveAll();
                cout << "\nAfter RemoveAll, IsEmpty: " << (arr.IsEmpty() ? "Yes" : "No") << endl;
                
                break;
            }
            case 2: {
                cout << "\n===== ARRAY<double> TEST =====" << endl;
                
                Array<double> arr(3, 2);
                arr.Add(1.5);
                arr.Add(2.7);
                arr.Add(3.14);
                arr.Add(4.0);
                arr.Add(5.25);
                
                cout << "Array<double>: ";
                arr.display();
                cout << "Size: " << arr.GetSize() << endl;
                cout << "Count: " << arr.GetCount() << endl;
                
                break;
            }
            case 3: {
                cout << "\n===== ARRAY<string> TEST =====" << endl;
                
                Array<string> arr(2, 2);
                arr.Add("Hello");
                arr.Add("World");
                arr.Add("Template");
                arr.Add("Array");
                
                cout << "Array<string>: ";
                arr.display();
                
                arr.InsertAt(1, "Beautiful");
                cout << "After InsertAt(1, \"Beautiful\"): ";
                arr.display();
                
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
