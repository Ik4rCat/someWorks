#include <iostream>
#include <fstream>
#include "BinaryDisplay.h"

using namespace std;

BinaryDisplay::BinaryDisplay() : FileHandler() {
}

BinaryDisplay::BinaryDisplay(const char* path) : FileHandler(path) {
}

BinaryDisplay::BinaryDisplay(const BinaryDisplay& other) : FileHandler(other) {
}

BinaryDisplay::~BinaryDisplay() {
}

string BinaryDisplay::toBinary(unsigned char ch) {
    string binary = "";
    for (int i = 7; i >= 0; i--) {
        binary += ((ch >> i) & 1) ? '1' : '0';
    }
    return binary;
}

void BinaryDisplay::Display(const char* path) {
    ifstream file(path, ios::binary);
    if (!file.is_open()) {
        cout << "Error: Cannot open file " << path << endl;
        return;
    }
    
    cout << "\n===== File Content (Binary View) =====" << endl;
    unsigned char ch;
    int count = 0;
    while (file.read(reinterpret_cast<char*>(&ch), 1)) {
        cout << toBinary(ch) << " ";
        count++;
        if (count % 8 == 0) {
            cout << endl;
        }
    }
    cout << endl;
    
    file.close();
}

BinaryDisplay& BinaryDisplay::operator=(const BinaryDisplay& other) {
    if (this != &other) {
        FileHandler::operator=(other);
    }
    return *this;
}
