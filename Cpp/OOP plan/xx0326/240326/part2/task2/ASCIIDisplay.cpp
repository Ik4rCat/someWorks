#include <iostream>
#include <fstream>
#include "ASCIIDisplay.h"

using namespace std;

ASCIIDisplay::ASCIIDisplay() : FileHandler() {
}

ASCIIDisplay::ASCIIDisplay(const char* path) : FileHandler(path) {
}

ASCIIDisplay::ASCIIDisplay(const ASCIIDisplay& other) : FileHandler(other) {
}

ASCIIDisplay::~ASCIIDisplay() {
}

void ASCIIDisplay::Display(const char* path) {
    ifstream file(path);
    if (!file.is_open()) {
        cout << "Error: Cannot open file " << path << endl;
        return;
    }
    
    cout << "\n===== File Content (ASCII Codes) =====" << endl;
    char ch;
    int count = 0;
    while (file.get(ch)) {
        cout << (int)ch << " ";
        count++;
        if (count % 20 == 0) {
            cout << endl;
        }
    }
    cout << endl;
    
    file.close();
}

ASCIIDisplay& ASCIIDisplay::operator=(const ASCIIDisplay& other) {
    if (this != &other) {
        FileHandler::operator=(other);
    }
    return *this;
}
