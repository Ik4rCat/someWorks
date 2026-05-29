#include <iostream>
#include <string> 
#include "DocumentFactory.h"
#include "LoggerFactory.h"

using namespace std;

void testFactoryMethod() {
    cout << "\n========== TEST 1: FACTORY METHOD ==========" << endl;
    
    Document* doc1 = DocumentFactory::createDocumentByType(
        DocumentFactory::DocType::PDF, "Report", 10);
    doc1->create();
    doc1->display();
    doc1->save();
    delete doc1;
    
    Document* doc2 = DocumentFactory::createDocumentByType(
        DocumentFactory::DocType::WORD, "Essay", 5);
    doc2->create();
    doc2->display();
    delete doc2;
    
    Document* doc3 = DocumentFactory::createDocumentByType(
        DocumentFactory::DocType::EXCEL, "Data", 1);
    doc3->create();
    doc3->display();
    delete doc3;
}

void testConcreteFactory() {
    cout << "\n========== TEST 2: CONCRETE FACTORY ==========" << endl;
    
    ConcreteDocumentFactory factory;
    
    // Using factory method
    Document* doc = factory.createDocument("Manual", 50);
    doc->create();
    doc->open();
    delete doc;
    
    // Using factory with parameters
    int params[] = {0, 1}; // PDF, encrypted
    Document* secureDoc = factory.createDocumentWithParams("Secret", 5, params);
    secureDoc->create();
    delete secureDoc;
}

void testFactoryWithParams() {
    cout << "\n========== TEST 3: FACTORY WITH PARAMETERS ==========" << endl;
    
    DocumentFactory* factory = new ConcreteDocumentFactory();
    
    Document* pdf = factory->createPDF("Confidential", 20, true);
    pdf->create();
    delete pdf;
    
    Document* word = factory->createWord("Resume", 2, 500, "Professional");
    word->create();
    word->display();
    delete word;
    
    Document* excel = factory->createExcel("Budget", 1, 100, 10);
    excel->create();
    excel->display();
    delete excel;
    
    delete factory;
}

void testSingleton() {
    cout << "\n========== TEST 4: SINGLETON PATTERN ==========" << endl;
    
    LoggerFactory* logger1 = LoggerFactory::getInstance();
    LoggerFactory* logger2 = LoggerFactory::getInstance();
    
    cout << "Logger1 address: " << logger1 << endl;
    cout << "Logger2 address: " << logger2 << endl;
    cout << "Same instance: " << (logger1 == logger2 ? "YES" : "NO") << endl;
    
    Document* doc1 = logger1->createAndLogDocument(
        DocumentFactory::DocType::PDF, "Annual Report", 100);
    doc1->save();
    delete doc1;
    
    Document* doc2 = logger1->createAndLogDocument(
        DocumentFactory::DocType::WORD, "Meeting Notes", 3);
    doc2->save();
    delete doc2;
    
    Document* doc3 = logger1->createAndLogDocument(
        DocumentFactory::DocType::EXCEL, "Statistics", 1);
    doc3->save();
    delete doc3;
    
    logger1->displayStatistics();
    logger1->displayHistory();
}

void testMultipleSingletons() {
    cout << "\n========== TEST 5: SINGLETON CONSISTENCY ==========" << endl;
    
    LoggerFactory* logger = LoggerFactory::getInstance();
    
    for (int i = 1; i <= 5; i++) {
        string name = "Document" + to_string(i);
        DocumentFactory::DocType type = static_cast<DocumentFactory::DocType>(i % 3);
        
        Document* doc = logger->createAndLogDocument(type, name, i * 10);
        delete doc;
    }
    
    logger->displayStatistics();
}

void testFactoryVariations() {
    cout << "\n========== TEST 6: FACTORY VARIATIONS ==========" << endl;
    
    LoggerFactory* logger = LoggerFactory::getInstance();
    
    DocumentFactory* factory = new ConcreteDocumentFactory();
    Document* doc1 = factory->createDocument("Direct", 10);
    cout << "Created via direct factory: " << doc1->getType() << endl;
    delete doc1;
    delete factory;

    DocumentFactory* factoryAlt = new AlternativeDocumentFactory();
    Document* docAlt = factoryAlt->createDocument("DirectAlt", 7);
    cout << "Created via alternative factory: " << docAlt->getType() << endl;
    delete docAlt;
    delete factoryAlt;
    
    Document* doc2 = DocumentFactory::createDocumentByType(
        DocumentFactory::DocType::PDF, "Static", 5);
    cout << "Created via static method: " << doc2->getType() << endl;
    delete doc2;
    
    Document* doc3 = logger->createWithFactory("Singleton", 15, false);
    cout << "Created via singleton: " << doc3->getType() << endl;
    delete doc3;

    DocumentFactory* singletonFactoryA = logger->getFactory(LoggerFactory::FactoryVariant::A);
    DocumentFactory* singletonFactoryB = logger->getFactory(LoggerFactory::FactoryVariant::B);
    Document* a = singletonFactoryA->createDocument("SingletonFactoryA", 3);
    Document* b = singletonFactoryB->createDocument("SingletonFactoryB", 3);
    cout << "Created via singleton factory A: " << a->getType() << endl;
    cout << "Created via singleton factory B: " << b->getType() << endl;
    delete a;
    delete b;
}

int main() {
    cout << "===== LABORATORY WORK 4 =====" << endl;
    cout << "Factory Method + Singleton" << endl;
    
    testFactoryMethod();
    testConcreteFactory();
    testFactoryWithParams();
    testSingleton();
    testMultipleSingletons();
    testFactoryVariations();
   
    LoggerFactory::getInstance()->displayStatistics();
    LoggerFactory::getInstance()->displayHistory();
    
    return 0;
}