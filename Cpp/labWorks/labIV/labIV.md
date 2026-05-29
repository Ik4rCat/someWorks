# Лабораторная работа IV — Factory Method + Singleton

---

## Program.cpp

**Блок 1**

```cpp
#include <iostream>
#include <string> 
#include "DocumentFactory.h"
#include "LoggerFactory.h"

using namespace std;
```

**Блок 2**

```cpp
void testFactoryMethod() {
    Document* doc1 = DocumentFactory::createDocumentByType(
        DocumentFactory::DocType::PDF, "Report", 10);
    doc1->create();
    doc1->display();
    doc1->save();
    delete doc1;
    // ... аналогично WORD и EXCEL
}
```

**Блок 3**

```cpp
void testConcreteFactory() {
    ConcreteDocumentFactory factory;
    Document* doc = factory.createDocument("Manual", 50);
    doc->create();
    doc->open();
    delete doc;

    int params[] = {0, 1};
    Document* secureDoc = factory.createDocumentWithParams("Secret", 5, params);
    secureDoc->create();
    delete secureDoc;
}
```

**Блок 4**

```cpp
void testFactoryWithParams() {
    DocumentFactory* factory = new ConcreteDocumentFactory();
    Document* pdf = factory->createPDF("Confidential", 20, true);
    pdf->create();
    delete pdf;

    Document* word = factory->createWord("Resume", 2, 500, "Professional");
    word->display();
    delete word;

    Document* excel = factory->createExcel("Budget", 1, 100, 10);
    excel->display();
    delete excel;
    delete factory;
}
```

**Блок 5**

```cpp
void testSingleton() {
    LoggerFactory* logger1 = LoggerFactory::getInstance();
    LoggerFactory* logger2 = LoggerFactory::getInstance();
    cout << (logger1 == logger2 ? "YES" : "NO") << endl;

    Document* doc1 = logger1->createAndLogDocument(DocumentFactory::DocType::PDF, "Annual Report", 100);
    delete doc1;
    logger1->displayStatistics();
    logger1->displayHistory();
}
```

**Блок 6**

```cpp
void testFactoryVariations() {
    LoggerFactory* logger = LoggerFactory::getInstance();

    DocumentFactory* factory = new ConcreteDocumentFactory();
    Document* doc1 = factory->createDocument("Direct", 10);
    delete doc1;
    delete factory;

    DocumentFactory* factoryAlt = new AlternativeDocumentFactory();
    Document* docAlt = factoryAlt->createDocument("DirectAlt", 7);
    delete docAlt;
    delete factoryAlt;

    DocumentFactory* singletonFactoryA = logger->getFactory(LoggerFactory::FactoryVariant::A);
    DocumentFactory* singletonFactoryB = logger->getFactory(LoggerFactory::FactoryVariant::B);
    Document* a = singletonFactoryA->createDocument("SingletonFactoryA", 3);
    Document* b = singletonFactoryB->createDocument("SingletonFactoryB", 3);
    delete a;
    delete b;
}
```

**Блок 7**

```cpp
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
```

---

## Document.h

**Блок 1**

```cpp
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
    virtual void display() const { ... }
};
```

---

## PDFDocument.h

**Блок 1**

```cpp
class PDFDocument : public Document {
private:
    bool isEncrypted;
public:
    PDFDocument(string name, int pages, bool encrypted = false)
        : Document(name, pages), isEncrypted(encrypted) {}

    void create() override { ... }
    void open() override { ... }
    void save() override { ... }
    string getType() const override { return "PDF"; }
    void encrypt() { ... }
};
```

---

## WordDocument.h

**Блок 1**

```cpp
class WordDocument : public Document {
private:
    int wordCount;
    string templateName;
public:
    WordDocument(string name, int pages, int words, string tpl = "Default")
        : Document(name, pages), wordCount(words), templateName(tpl) {}

    void create() override { ... }
    void open() override { ... }
    void save() override { ... }
    string getType() const override { return "Word"; }
};
```

---

## ExcelDocument.h

**Блок 1**

```cpp
class ExcelDocument : public Document {
private:
    int rowCount;
    int columnCount;
    vector<vector<double>> data;
public:
    ExcelDocument(string name, int pages, int rows, int cols)
        : Document(name, pages), rowCount(rows), columnCount(cols) {
        data.resize(rows, vector<double>(cols, 0.0));
    }

    void create() override { ... }
    void open() override { ... }
    void save() override { ... }
    string getType() const override { return "Excel"; }
};
```

---

## DocumentFactory.h

**Блок 1**

```cpp
class DocumentFactory {
public:
    enum class DocType { PDF, WORD, EXCEL };
    virtual ~DocumentFactory() {}
    virtual Document* createDocument(const string& name, int pages) = 0;
    virtual Document* createDocumentWithParams(const string& name, int pages, void* params) = 0;
    static Document* createDocumentByType(DocType type, const string& name, int pages);
    Document* createPDF(const string& name, int pages, bool encrypted);
    Document* createWord(const string& name, int pages, int wordCount, const string& templateName);
    Document* createExcel(const string& name, int pages, int rows, int cols);
};
```

**Блок 2**

```cpp
class ConcreteDocumentFactory : public DocumentFactory {
public:
    Document* createDocument(const string& name, int pages) override {
        return new PDFDocument(name, pages);
    }
    Document* createDocumentWithParams(const string& name, int pages, void* params) override { ... }
};
```

**Блок 3**

```cpp
class AlternativeDocumentFactory : public DocumentFactory {
public:
    Document* createDocument(const string& name, int pages) override {
        return new WordDocument(name, pages, 0, "Default");
    }
    Document* createDocumentWithParams(const string& name, int pages, void* params) override { ... }
};
```

**Блок 4**

```cpp
inline Document* DocumentFactory::createDocumentByType(DocType type, const string& name, int pages) { ... }
inline Document* DocumentFactory::createPDF(const string& name, int pages, bool encrypted) { ... }
inline Document* DocumentFactory::createWord(const string& name, int pages, int wordCount, const string& templateName) { ... }
inline Document* DocumentFactory::createExcel(const string& name, int pages, int rows, int cols) { ... }
```

---

## LoggerFactory.h

**Блок 1**

```cpp
class LoggerFactory {
private:
    static LoggerFactory* instance;
    DocumentFactory* factoryA;
    DocumentFactory* factoryB;
    vector<string> creationHistory;
    int pdfCount;
    int wordCount;
    int excelCount;
```

**Блок 2**

```cpp
    LoggerFactory() {
        factoryA = new ConcreteDocumentFactory();
        factoryB = new AlternativeDocumentFactory();
        pdfCount = 0; wordCount = 0; excelCount = 0;
    }
    LoggerFactory(const LoggerFactory&) = delete;
    LoggerFactory& operator=(const LoggerFactory&) = delete;
```

**Блок 3**

```cpp
public:
    enum class FactoryVariant { A, B };
    static LoggerFactory* getInstance() {
        if (instance == nullptr) instance = new LoggerFactory();
        return instance;
    }
    DocumentFactory* getFactory(FactoryVariant variant) {
        return (variant == FactoryVariant::A) ? factoryA : factoryB;
    }
```

**Блок 4**

```cpp
    Document* createAndLogDocument(DocumentFactory::DocType type, const string& name, int pages) { ... }
    Document* createWithFactory(const string& name, int pages, bool encrypted = false) { ... }
    void displayStatistics() const { ... }
    void displayHistory() const { ... }
```

**Блок 5**

```cpp
    ~LoggerFactory() {
        delete factoryA;
        delete factoryB;
    }
};

LoggerFactory* LoggerFactory::instance = nullptr;
```

---

## Блоки объяснение

**Program.cpp**  
- **Блок 1** — подключения и `using`, чтобы использовать фабрики, документы и синглтон.  
- **Блок 2** — тест статического Factory Method (`createDocumentByType`) для трёх типов документов.  
- **Блок 3** — тест конкретной фабрики `ConcreteDocumentFactory` (обычное создание и создание с параметрами).  
- **Блок 4** — тест методов фабрики с параметрами (createPDF/createWord/createExcel).  
- **Блок 5** — тест Singleton: проверка единственного экземпляра (`logger1 == logger2`) и логирование созданий.  
- **Блок 6** — тест двух вариаций фабрик: обычная, альтернативная и фабрики A/B, полученные из синглтона.  
- **Блок 7** — `main`: последовательный запуск всех тестов и вывод итоговой статистики/истории.

**Document.h**  
- **Блок 1** — абстрактный базовый класс документа: общие поля и чисто виртуальные методы, обязательные для всех документов.

**PDFDocument.h**  
- **Блок 1** — конкретный документ PDF, переопределяет create/open/save/getType, хранит флаг шифрования.

**WordDocument.h**  
- **Блок 1** — конкретный документ Word, добавляет слова и шаблон, реализует базовые операции документа.

**ExcelDocument.h**  
- **Блок 1** — конкретный документ Excel, хранит размеры таблицы и данные, реализует базовые операции.

**DocumentFactory.h**  
- **Блок 1** — интерфейс фабрики + перечисление типов документов + вспомогательные методы создания.  
- **Блок 2** — первая вариация фабрики (Concrete): по умолчанию создаёт PDF и умеет создавать с параметрами.  
- **Блок 3** — вторая вариация фабрики (Alternative): по умолчанию создаёт Word и имеет другой выбор в параметризованном создании.  
- **Блок 4** — inline-реализация статических/вспомогательных методов фабрики.

**LoggerFactory.h**  
- **Блок 1** — поля singleton-класса: один instance, две фабрики (A/B), история и счётчики.  
- **Блок 2** — приватный конструктор и запрет копирования (основа Singleton).  
- **Блок 3** — `getInstance()` и выбор фабрики по варианту (`FactoryVariant::A/B`).  
- **Блок 4** — создание документов с логированием + вывод статистики/истории.  
- **Блок 5** — освобождение фабрик и инициализация `instance`.

---

## Вывод по работе

В работе объединены два паттерна: **Factory Method** и **Singleton**.  
- Factory Method отвечает за создание нужных типов документов через единый интерфейс.  
- Singleton (`LoggerFactory`) даёт единую точку доступа к логированию и теперь управляет **двумя вариациями фабрики** (A и B).  

Это позволяет централизованно создавать документы, вести историю/статистику и переключаться между разными стратегиями создания объектов.
