#pragma once

#include <iostream>
#include <iomanip>
#include "FileHandler.h"

using namespace std;

class HexDisplay : public FileHandler {
public:
    HexDisplay();
    HexDisplay(const char* path);
    HexDisplay(const HexDisplay& other);
    ~HexDisplay();
    
    void Display(const char* path) override;
    
    HexDisplay& operator=(const HexDisplay& other);
};
