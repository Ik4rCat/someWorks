#include "task1/Student.h"
#include "task2/House.h"

using namespace std;

int main() {
    int choice;
    
    cout << "===== MOVE CONSTRUCTOR TEST =====" << endl;
    
    while (true) {
        cout << "\n1. Test Student Move Constructor" << endl;
        cout << "2. Test House Move Constructor" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();
        
        if (choice == 0) {
            break;
        }
        
        switch (choice) {
            case 1: {
                cout << "\n===== STUDENT MOVE SEMANTICS =====" << endl;
                
                int grades[] = {5, 4, 5, 3};
                Student s1("Ivanov Ivan", 20, "Computer Science", grades, 4);
                
                cout << "\nOriginal student:" << endl;
                s1.display();
                
                Student s2(std::move(s1));
                
                cout << "\nAfter move to s2:" << endl;
                cout << "s2 (moved):" << endl;
                s2.display();
                
                Student s3;
                s3 = std::move(s2);
                
                cout << "\nAfter move assignment to s3:" << endl;
                cout << "s3 (move assigned):" << endl;
                s3.display();
                
                break;
            }
            case 2: {
                cout << "\n===== HOUSE MOVE SEMANTICS =====" << endl;
                
                Person p1("Petrov Petr", 35);
                Person p2("Petrova Anna", 32);
                
                Apartment apt1(1, 45.5);
                apt1.addResident(p1);
                apt1.addResident(p2);
                
                House house1("Lenina St, 10");
                house1.addApartment(apt1);
                
                cout << "\nOriginal house:" << endl;
                house1.display();
                
                House house2(std::move(house1));
                
                cout << "\nAfter move to house2:" << endl;
                cout << "house2 (moved):" << endl;
                house2.display();
                
                House house3;
                house3 = std::move(house2);
                
                cout << "\nAfter move assignment to house3:" << endl;
                cout << "house3 (move assigned):" << endl;
                house3.display();
                
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
