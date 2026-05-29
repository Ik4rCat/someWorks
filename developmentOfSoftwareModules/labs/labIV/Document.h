#pragma once

#include <iostream>
#include <string>

using namespace std;

class Document {
protected:
    string fileName;
    int pageCount;
    
public:
    Document() : fileName(""), pageCount(0) {}
    Document(string name, int pages) : fileName(name), pageCount(pages) {}
    virtual ~Document() {}
    
    virtual void create() = 0;
    virtual void open() = 0;
    virtual void save() = 0;
    virtual string getType() const = 0;
    
    string getFileName() const { return fileName; }
    int getPageCount() const { return pageCount; }
    
    virtual void display() const {
        cout << "Document: " << fileName << endl;
        cout << "Pages: " << pageCount << endl;
        cout << "Type: " << getType() << endl;
    }
};
