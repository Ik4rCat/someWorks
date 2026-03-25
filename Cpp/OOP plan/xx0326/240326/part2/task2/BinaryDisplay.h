#pragma once

#include <iostream>
#include "FileHandler.h"

using namespace std;

class BinaryDisplay : public FileHandler {
public:
    BinaryDisplay();
    BinaryDisplay(const char* path);
    BinaryDisplay(const BinaryDisplay& other);
    ~BinaryDisplay();
    
    void Display(const char* path) override;
    
    BinaryDisplay& operator=(const BinaryDisplay& other);
    
private:
    string toBinary(unsigned char ch);
};
