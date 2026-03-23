#include <iostream>
#include "House.h"

int main() {
    House house;
    int choice;
    
    cout << "===== APARTMENT BUILDING SIMULATOR =====" << endl;
    
    while (true) {
        cout << "\n1. Create House" << endl;
        cout << "2. Add Apartment" << endl;
        cout << "3. Remove Apartment" << endl;
        cout << "4. Add Resident to Apartment" << endl;
        cout << "5. Display House" << endl;
        cout << "6. Test Copy Constructor" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();
        
        if (choice == 0) {
            break;
        }
        
        switch (choice) {
            case 1: {
                house.input();
                cout << "House created" << endl;
                break;
            }
            case 2: {
                Apartment apt;
                apt.input();
                house.addApartment(apt);
                cout << "Apartment added" << endl;
                break;
            }
            case 3: {
                int index;
                cout << "Enter apartment number to remove: ";
                cin >> index;
                cin.ignore();
                house.removeApartment(index - 1);
                cout << "Apartment removed" << endl;
                break;
            }
            case 4: {
                int aptIndex;
                cout << "Enter apartment number: ";
                cin >> aptIndex;
                cin.ignore();
                
                if (aptIndex > 0 && aptIndex <= house.getApartmentCount()) {
                    Person person;
                    person.input();
                    Apartment apt = house.getApartment(aptIndex - 1);
                    apt.addResident(person);
                    cout << "Resident added" << endl;
                } else {
                    cout << "Invalid apartment number" << endl;
                }
                break;
            }
            case 5: {
                house.display();
                break;
            }
            case 6: {
                House houseCopy(house);
                cout << "\nOriginal house:" << endl;
                house.display();
                cout << "\nCopied house:" << endl;
                houseCopy.display();
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
