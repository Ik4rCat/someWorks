#include <iostream>
#include "part2/PhoneBook.h"
#include "part1/MyString.h"

using namespace std;

int main() {
    PhoneBook phoneBook;
    int choice;
    
    cout << "===== PHONE BOOK APPLICATION =====" << endl;
    
    while (true) {
        cout << "\n1. Add Contact" << endl;
        cout << "2. Delete Contact" << endl;
        cout << "3. Search Contact" << endl;
        cout << "4. Show All Contacts" << endl;
        cout << "5. Save to File" << endl;
        cout << "6. Load from File" << endl;
        cout << "7. Test String Class" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();
        
        if (choice == 0) {
            break;
        }
        
        switch (choice) {
            case 1: {
                Contact contact;
                contact.input();
                phoneBook.addContact(contact);
                cout << "Contact added" << endl;
                break;
            }
            case 2: {
                int index;
                cout << "Enter contact number to delete: ";
                cin >> index;
                cin.ignore();
                phoneBook.deleteContact(index - 1);
                cout << "Contact deleted" << endl;
                break;
            }
            case 3: {
                char name[100];
                cout << "Enter name to search: ";
                cin.getline(name, 100);
                int index = phoneBook.searchByName(name);
                if (index != -1) {
                    cout << "Contact found:" << endl;
                    phoneBook.showAll();
                } else {
                    cout << "Contact not found" << endl;
                }
                break;
            }
            case 4: {
                phoneBook.showAll();
                break;
            }
            case 5: {
                char filename[100];
                cout << "Enter filename: ";
                cin.getline(filename, 100);
                phoneBook.saveToFile(filename);
                break;
            }
            case 6: {
                char filename[100];
                cout << "Enter filename: ";
                cin.getline(filename, 100);
                phoneBook.loadFromFile(filename);
                break;
            }
            case 7: {
                MyString s1;
                MyString s2(50);
                MyString s3("Hello World");
                
                cout << "\n===== STRING CLASS TEST =====" << endl;
                cout << "s1 (default): ";
                s1.output();
                cout << endl;
                
                cout << "s2 (size 50): ";
                s2.output();
                cout << endl;
                
                cout << "s3 (initialized): ";
                s3.output();
                cout << endl;
                
                cout << "Enter string for s1: ";
                s1.input();
                
                cout << "s1 after input: ";
                s1.output();
                cout << endl;
                
                cout << "Total String objects created: " << MyString::getObjectCount() << endl;
                break;
            }
            default: {
                cout << "Invalid choice" << endl;
            }
        }
    }
    
    cout << "\nTotal String objects remaining: " << MyString::getObjectCount() << endl;
    cout << "Goodbye!" << endl;
    
    return 0;
}
