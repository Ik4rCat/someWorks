#pragma once

#include "DocumentFactory.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class LoggerFactory {
private:
    static LoggerFactory* instance;
    
    DocumentFactory* factoryA;
    DocumentFactory* factoryB;
    
    vector<string> creationHistory;

    int pdfCount;
    int wordCount;
    int excelCount;
    
    LoggerFactory() {
        factoryA = new ConcreteDocumentFactory();
        factoryB = new AlternativeDocumentFactory();
        pdfCount = 0;
        wordCount = 0;
        excelCount = 0;
        cout << "LoggerFactory Singleton created" << endl;
    }
    
    LoggerFactory(const LoggerFactory&) = delete;
    LoggerFactory& operator=(const LoggerFactory&) = delete;
    
public:
    enum class FactoryVariant {
        A,
        B
    };

    static LoggerFactory* getInstance() {
        if (instance == nullptr) {
            instance = new LoggerFactory();
        }
        return instance;
    }
    
    DocumentFactory* getFactory() {
        return factoryA;
    }

    DocumentFactory* getFactory(FactoryVariant variant) {
        return (variant == FactoryVariant::A) ? factoryA : factoryB;
    }
    
    Document* createAndLogDocument(DocumentFactory::DocType type, const string& name, int pages) {
        Document* doc = DocumentFactory::createDocumentByType(type, name, pages);
        
        if (doc != nullptr) {
            string logEntry = "Created " + doc->getType() + " document: " + name;
            creationHistory.push_back(logEntry);
            
            // Update statistics
            if (type == DocumentFactory::DocType::PDF) pdfCount++;
            else if (type == DocumentFactory::DocType::WORD) wordCount++;
            else if (type == DocumentFactory::DocType::EXCEL) excelCount++;
            
            cout << "[LOG] " << logEntry << endl;
        }
        
        return doc;
    }
    
    Document* createWithFactory(const string& name, int pages, bool encrypted = false) {
        Document* doc = factoryA->createPDF(name, pages, encrypted);
        creationHistory.push_back("Created PDF with factory: " + name);
        pdfCount++;
        cout << "[LOG] Created with custom factory" << endl;
        return doc;
    }
    
    void displayStatistics() const {
        cout << "\n===== CREATION STATISTICS =====" << endl;
        cout << "PDF documents: " << pdfCount << endl;
        cout << "Word documents: " << wordCount << endl;
        cout << "Excel documents: " << excelCount << endl;
        cout << "Total documents: " << (pdfCount + wordCount + excelCount) << endl;
    }
    
    void displayHistory() const {
        cout << "\n===== CREATION HISTORY =====" << endl;
        for (size_t i = 0; i < creationHistory.size(); i++) {
            cout << (i + 1) << ". " << creationHistory[i] << endl;
        }
    }
    
    void clearHistory() {
        creationHistory.clear();
        cout << "[LOG] History cleared" << endl;
    }
    
    ~LoggerFactory() {
        delete factoryA;
        delete factoryB;
        cout << "LoggerFactory Singleton destroyed" << endl;
    }
};

LoggerFactory* LoggerFactory::instance = nullptr;