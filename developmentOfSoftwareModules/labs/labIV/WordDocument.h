#pragma once

#include "Document.h"
#include <iostream>

using namespace std;

class WordDocument : public Document {
private:
    int wordCount;
    string templateName;
    
public:
    WordDocument() : Document(), wordCount(0), templateName("Default") {}
    WordDocument(string name, int pages, int words, string tpl = "Default")
        : Document(name, pages), wordCount(words), templateName(tpl) {}
    
    void create() override {
        cout << "Creating Word document: " << fileName << endl;
        cout << "Using template: " << templateName << endl;
        cout << "Word count: " << wordCount << endl;
    }
    
    void open() override {
        cout << "Opening Word: " << fileName << endl;
        cout << "Loading styles and formatting" << endl;
    }
    
    void save() override {
        cout << "Saving Word document: " << fileName << ".docx" << endl;
        cout << "Words saved: " << wordCount << endl;
    }
    
    string getType() const override {
        return "Word";
    }
    
    void setTemplate(string tpl) {
        templateName = tpl;
    }
    
    int getWordCount() const {
        return wordCount;
    }
    
    void edit() {
        cout << "Editing Word document..." << endl;
        wordCount += 100;
        cout << "New word count: " << wordCount << endl;
    }
};
