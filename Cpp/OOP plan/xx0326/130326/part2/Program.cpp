#include <iostream>
#include "task1/Stack.h"
#include "task2/LinkedList.h"

using namespace std;

int main() {
    int choice;
    
    cout << "===== STACK AND LINKED LIST TEST =====" << endl;
    
    while (true) {
        cout << "\n1. Test Stack" << endl;
        cout << "2. Test Linked List (Clone, +, *)" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();
        
        if (choice == 0) {
            break;
        }
        
        switch (choice) {
            case 1: {
                cout << "\n===== STACK TEST =====" << endl;
                
                Stack<int> stack(5);
                cout << "Initial size: " << stack.getSize() << endl;
                cout << "Is empty: " << (stack.isEmpty() ? "Yes" : "No") << endl;
                
                cout << "\nPushing elements: 10, 20, 30, 40, 50" << endl;
                stack.push(10);
                stack.push(20);
                stack.push(30);
                stack.push(40);
                stack.push(50);
                stack.display();
                cout << "Size: " << stack.getSize() << endl;
                
                cout << "\nPushing more (auto-resize): 60, 70" << endl;
                stack.push(60);
                stack.push(70);
                stack.display();
                cout << "Size: " << stack.getSize() << endl;
                
                cout << "\nPeek: " << stack.peek() << endl;
                
                cout << "Pop: ";
                stack.pop();
                stack.display();
                
                Stack<int> stack2 = stack;
                cout << "\nstack2 (copy): ";
                stack2.display();
                
                break;
            }
            case 2: {
                cout << "\n===== LINKED LIST TEST =====" << endl;
                
                LinkedList<int> list1;
                list1.append(1);
                list1.append(2);
                list1.append(3);
                list1.append(4);
                list1.append(5);
                
                LinkedList<int> list2;
                list2.append(3);
                list2.append(4);
                list2.append(5);
                list2.append(6);
                list2.append(7);
                
                cout << "List 1: ";
                list1.display();
                cout << "List 2: ";
                list2.display();
                
                LinkedList<int>* cloned = list1.clone();
                cout << "\nCloned list1: ";
                cloned->display();
                
                LinkedList<int>* concatenated = list1 + list2;
                cout << "\nList1 + List2: ";
                concatenated->display();
                
                LinkedList<int>* intersection = list1 * list2;
                cout << "\nList1 * List2 (intersection): ";
                intersection->display();
                
                delete cloned;
                delete concatenated;
                delete intersection;
                
                cout << "\nlist1[2] = " << list1[2] << endl;
                list1[2] = 99;
                cout << "After list1[2] = 99: ";
                list1.display();
                
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
