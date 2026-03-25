#include <iostream>
#include <fstream>

#include "task1/Base.h"
#include "task1/Child.h"
#include "task1/Child2.h"

#include "task2/FileHandler.h"
#include "task2/ASCIIDisplay.h"
#include "task2/BinaryDisplay.h"
#include "task2/HexDisplay.h"

using namespace std;

void testTemplateHierarchy() {
    cout << "\n========== TEMPLATE INHERITANCE TEST ==========" << endl;
    
    cout << "\n--- Testing Base class ---" << endl;
    Base<int, double> base1(10, 3.14);
    base1.display();
    
    Base<string, char> base2("Hello", 'A');
    base2.display();
    
    cout << "\n--- Testing Child class ---" << endl;
    Child<int, double, string, char> child1(100, 2.71, "World", 'B');
    child1.display();
    cout << "Value1 from base: " << child1.getValue1() << endl;
    cout << "Value3 from child: " << child1.getValue3() << endl;
    
    cout << "\n--- Testing Child2 class ---" << endl;
    Child2<int, double, string, char, bool, float> child2(1000, 1.41, "Template", 'C', true, 9.99f);
    child2.display();
    cout << "Value5 from child2: " << (child2.getValue5() ? "true" : "false") << endl;
    cout << "Value6 from child2: " << child2.getValue6() << endl;
    
    cout << "\n--- Testing copy constructor ---" << endl;
    Child2<int, double, string, char, bool, float> child3(child2);
    cout << "Copied object: ";
    child3.display();
    
    cout << "\n--- Testing assignment operator ---" << endl;
    Child<int, double, string, char> child4;
    child4 = child1;
    cout << "Assigned object: ";
    child4.display();
}

void testFileHandlers() {
    cout << "\n========== FILE HANDLER TEST ==========" << endl;
    
    const char* testFile = "test.txt";
    
    cout << "\n--- Testing FileHandler (Normal View) ---" << endl;
    FileHandler normalHandler;
    normalHandler.Display(testFile);
    
    cout << "\n--- Testing ASCIIDisplay ---" << endl;
    ASCIIDisplay asciiHandler;
    asciiHandler.Display(testFile);
    
    cout << "\n--- Testing BinaryDisplay ---" << endl;
    BinaryDisplay binaryHandler;
    binaryHandler.Display(testFile);
    
    cout << "\n--- Testing HexDisplay ---" << endl;
    HexDisplay hexHandler;
    hexHandler.Display(testFile);
    
    cout << "\n--- Testing polymorphism ---" << endl;
    FileHandler* handlers[3];
    handlers[0] = new ASCIIDisplay();
    handlers[1] = new BinaryDisplay();
    handlers[2] = new HexDisplay();
    
    for (int i = 0; i < 3; i++) {
        handlers[i]->Display(testFile);
        cout << endl;
    }
    
    for (int i = 0; i < 3; i++) {
        delete handlers[i];
    }
}

void createTestFile() {
    ofstream file("test.txt");
    if (file.is_open()) {
        file << "Hello, World!" << endl;
        file << "This is a test file." << endl;
        file << "Testing file handlers..." << endl;
        file << "123 ABC xyz" << endl;
        file.close();
        cout << "Test file 'test.txt' created successfully!" << endl;
    }
}

int main() {
    int choice;
    
    cout << "===== HOMEWORK: INHERITANCE TEST =====" << endl;
    
    while (true) {
        cout << "\n1. Test Template Inheritance (Base, Child, Child2)" << endl;
        cout << "2. Create Test File" << endl;
        cout << "3. Test File Handlers (Normal, ASCII, Binary, Hex)" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        
        if (choice == 0) {
            break;
        }
        
        switch (choice) {
            case 1:
                testTemplateHierarchy();
                break;
            case 2:
                createTestFile();
                break;
            case 3:
                testFileHandlers();
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    }
    
    cout << "Goodbye!" << endl;
    return 0;
}
