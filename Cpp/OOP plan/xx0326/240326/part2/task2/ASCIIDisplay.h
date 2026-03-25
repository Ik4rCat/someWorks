#pragma once

#include <iostream>
#include "FileHandler.h"

using namespace std;

class ASCIIDisplay : public FileHandler {
public:
    ASCIIDisplay();
    ASCIIDisplay(const char* path);
    ASCIIDisplay(const ASCIIDisplay& other);
    ~ASCIIDisplay();
    
    void Display(const char* path) override;
    
    ASCIIDisplay& operator=(const ASCIIDisplay& other);
};
