#pragma once

#include <iostream>

using namespace std;

class FileHandler {
protected:
    char* filePath;

public:
    FileHandler();
    FileHandler(const char* path);
    FileHandler(const FileHandler& other);
    virtual ~FileHandler();
    
    virtual void Display(const char* path);
    
    FileHandler& operator=(const FileHandler& other);
    
    const char* getFilePath() const;
    void setFilePath(const char* path);
};
