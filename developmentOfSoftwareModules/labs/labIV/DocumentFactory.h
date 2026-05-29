#pragma once

#include "Document.h"
#include "PDFDocument.h"
#include "WordDocument.h"
#include "ExcelDocument.h"
#include <string>

using namespace std;

class DocumentFactory {
public:
    enum class DocType {
        PDF,
        WORD,
        EXCEL
    };
    
    virtual ~DocumentFactory() {}
    
    virtual Document* createDocument(const string& name, int pages) = 0;
    
    virtual Document* createDocumentWithParams(const string& name, int pages, void* params) = 0;
    
    static Document* createDocumentByType(DocType type, const string& name, int pages);
    
    Document* createPDF(const string& name, int pages, bool encrypted);
    Document* createWord(const string& name, int pages, int wordCount, const string& templateName);
    Document* createExcel(const string& name, int pages, int rows, int cols);
};

class ConcreteDocumentFactory : public DocumentFactory {
public:
    Document* createDocument(const string& name, int pages) override {
        return new PDFDocument(name, pages);
    }
    
    Document* createDocumentWithParams(const string& name, int pages, void* params) override {
        int* extraParams = static_cast<int*>(params);
        if (extraParams[0] == 0) {
            return new PDFDocument(name, pages, extraParams[1] > 0);
        } else if (extraParams[0] == 1) {
            return new WordDocument(name, pages, extraParams[1]);
        } else {
            return new ExcelDocument(name, pages, extraParams[1], extraParams[2]);
        }
    }
};

class AlternativeDocumentFactory : public DocumentFactory {
public:
    Document* createDocument(const string& name, int pages) override {
        return new WordDocument(name, pages, 0, "Default");
    }

    Document* createDocumentWithParams(const string& name, int pages, void* params) override {
        int* extraParams = static_cast<int*>(params);
        if (extraParams[0] == 0) {
            return new WordDocument(name, pages, extraParams[1], "AltTemplate");
        } else if (extraParams[0] == 1) {
            return new ExcelDocument(name, pages, extraParams[1], extraParams[2]);
        } else {
            return new PDFDocument(name, pages, extraParams[1] > 0);
        }
    }
};


inline Document* DocumentFactory::createDocumentByType(DocType type, const string& name, int pages) {
    switch (type) {
        case DocType::PDF:
            return new PDFDocument(name, pages);
        case DocType::WORD:
            return new WordDocument(name, pages, 0);
        case DocType::EXCEL:
            return new ExcelDocument(name, pages, 10, 10);
        default:
            return nullptr;
    }
}

inline Document* DocumentFactory::createPDF(const string& name, int pages, bool encrypted) {
    return new PDFDocument(name, pages, encrypted);
}

inline Document* DocumentFactory::createWord(const string& name, int pages, int wordCount, const string& templateName) {
    return new WordDocument(name, pages, wordCount, templateName);
}

inline Document* DocumentFactory::createExcel(const string& name, int pages, int rows, int cols) {
    return new ExcelDocument(name, pages, rows, cols);
}
