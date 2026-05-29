#pragma once

#include "Document.h"
#include <iostream>

using namespace std;

class PDFDocument : public Document {
private:
    bool isEncrypted;
    
public:
    PDFDocument() : Document(), isEncrypted(false) {}
    PDFDocument(string name, int pages, bool encrypted = false) 
        : Document(name, pages), isEncrypted(encrypted) {}
    
    void create() override {
        cout << "Creating PDF document: " << fileName << endl;
        cout << "PDF format initialized" << endl;
        if (isEncrypted) {
            cout << "Encryption enabled" << endl;
        }
    }
    
    void open() override {
        cout << "Opening PDF: " << fileName << endl;
        cout << "Rendering " << pageCount << " pages" << endl;
    }
    
    void save() override {
        cout << "Saving PDF document: " << fileName << ".pdf" << endl;
        cout << "File size: " << (pageCount * 50) << " KB" << endl;
    }
    
    string getType() const override {
        return "PDF";
    }
    
    void encrypt() {
        isEncrypted = true;
        cout << "Document encrypted" << endl;
    }
    
    bool isEncryptedDocument() const {
        return isEncrypted;
    }
};
