#include <iostream>
#include "TrafficPoliceDB.h"

using namespace std;

void addViolationInteractive(TrafficPoliceDB& db) {
    string plate, description, date, location;
    double fine;
    
    cout << "\nEnter license plate: ";
    cin >> plate;
    cin.ignore();
    
    cout << "Enter violation description: ";
    getline(cin, description);
    
    cout << "Enter fine amount: $";
    cin >> fine;
    cin.ignore();
    
    cout << "Enter date (DD.MM.YYYY): ";
    getline(cin, date);
    
    cout << "Enter location: ";
    getline(cin, location);
    
    Violation violation(description, fine, date, location);
    db.addViolation(plate, violation);
    
    cout << "Violation added successfully!" << endl;
}

void searchByPlate(TrafficPoliceDB& db) {
    string plate;
    cout << "\nEnter license plate to search: ";
    cin >> plate;
    
    TreeNode* result = db.findCar(plate);
    if (result != nullptr) {
        cout << "\nFound violations for " << plate << ":" << endl;
        result->displayViolations();
    } else {
        cout << "No violations found for " << plate << endl;
    }
}

void searchByRange(TrafficPoliceDB& db) {
    string startPlate, endPlate;
    cout << "\nEnter start license plate: ";
    cin >> startPlate;
    cout << "Enter end license plate: ";
    cin >> endPlate;
    
    db.printByRange(startPlate, endPlate);
}

int main() {
    TrafficPoliceDB db;
    int choice;
    
    cout << "===== TRAFFIC POLICE DATABASE =====" << endl;
    
    while (true) {
        cout << "\n1. Add violation" << endl;
        cout << "2. Print all database" << endl;
        cout << "3. Search by license plate" << endl;
        cout << "4. Search by range" << endl;
        cout << "5. Display statistics" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        
        if (choice == 0) {
            break;
        }
        
        switch (choice) {
            case 1:
                addViolationInteractive(db);
                break;
            case 2:
                db.printAll();
                break;
            case 3:
                searchByPlate(db);
                break;
            case 4:
                searchByRange(db);
                break;
            case 5:
                cout << "\nDatabase statistics:" << endl;
                cout << "Total cars with violations: " << db.getNodeCount() << endl;
                cout << "Database is " << (db.isEmpty() ? "empty" : "not empty") << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    }
    
    cout << "Goodbye!" << endl;
    return 0;
}
