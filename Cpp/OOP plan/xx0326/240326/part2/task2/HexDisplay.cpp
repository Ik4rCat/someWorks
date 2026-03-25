#include <iostream>
#include <fstream>
#include <iomanip>
#include "HexDisplay.h"

using namespace std;

HexDisplay::HexDisplay() : FileHandler() {
}

HexDisplay::HexDisplay(const char* path) : FileHandler(path) {
}

HexDisplay::HexDisplay(const HexDisplay& other) : FileHandler(other) {
}

HexDisplay::~HexDisplay() {
}

void HexDisplay::Display(const char* path) {
    ifstream file(path, ios::binary);
    if (!file.is_open()) {
        cout << "Error: Cannot open file " << path << endl;
        return;
    }
    
    cout << "\n===== File Content (Hexadecimal View) =====" << endl;
    unsigned char ch;
    int count = 0;
    while (file.read(reinterpret_cast<char*>(&ch), 1)) {
        cout << hex << setw(2) << setfill('0') << (int)ch << " ";
        count++;
        if (count % 16 == 0) {
            cout << endl;
        }
    }
    cout << dec << endl;
    
    file.close();
}

HexDisplay& HexDisplay::operator=(const HexDisplay& other) {
    if (this != &other) {
        FileHandler::operator=(other);
    }
    return *this;
}
