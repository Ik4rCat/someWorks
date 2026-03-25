#include <iostream>
#include <fstream>
#include <cstring>
#include "FileHandler.h"

using namespace std;

FileHandler::FileHandler() {
    filePath = new char[1];
    filePath[0] = '\0';
}

FileHandler::FileHandler(const char* path) {
    filePath = new char[strlen(path) + 1];
    strcpy(filePath, path);
}

FileHandler::FileHandler(const FileHandler& other) {
    filePath = new char[strlen(other.filePath) + 1];
    strcpy(filePath, other.filePath);
}

FileHandler::~FileHandler() {
    delete[] filePath;
}

void FileHandler::Display(const char* path) {
    ifstream file(path);
    if (!file.is_open()) {
        cout << "Error: Cannot open file " << path << endl;
        return;
    }
    
    cout << "\n===== File Content (Normal View) =====" << endl;
    char ch;
    while (file.get(ch)) {
        cout << ch;
    }
    cout << endl;
    
    file.close();
}

FileHandler& FileHandler::operator=(const FileHandler& other) {
    if (this != &other) {
        delete[] filePath;
        filePath = new char[strlen(other.filePath) + 1];
        strcpy(filePath, other.filePath);
    }
    return *this;
}

const char* FileHandler::getFilePath() const {
    return filePath;
}

void FileHandler::setFilePath(const char* path) {
    delete[] filePath;
    filePath = new char[strlen(path) + 1];
    strcpy(filePath, path);
}
