#include <iostream>
#include <string>
#include "Object.h"
#include "ArrayList.h"
#include "LinkedList.h"
#include "List.h"
#include "Print.h"

int main() {
    std::cout << "=== ArrayList (Object*) ===" << std::endl;
    ArrayList arrList;
    arrList.add(new ObjectT<int>(10));
    arrList.add(new ObjectT<int>(20));
    arrList.add(new ObjectT<int>(30));
    Print::print(arrList);
    std::cout << "Size: " << arrList.size() << std::endl;
    std::cout << "Iterator: ";
    Iterator* it1 = arrList.getIterator();
    while (it1->hasNext()) {
        it1->next()->print(std::cout);
        std::cout << " ";
    }
    std::cout << std::endl;
    delete it1;

    std::cout << "\n=== LinkedList (Object*) ===" << std::endl;
    LinkedList linkedList;
    linkedList.add(new ObjectT<int>(5));
    linkedList.add(new ObjectT<int>(15));
    linkedList.add(new ObjectT<int>(25));
    linkedList.add(new ObjectT<int>(35));
    Print::print(linkedList);
    std::cout << "Size: " << linkedList.size() << std::endl;
    std::cout << "Iterator: ";
    Iterator* it2 = linkedList.getIterator();
    while (it2->hasNext()) {
        it2->next()->print(std::cout);
        std::cout << " ";
    }
    std::cout << std::endl;
    delete it2;

    std::cout << "\n=== List<int> (template) ===" << std::endl;
    List<int> listInt;
    listInt.add(100);
    listInt.add(200);
    listInt.add(300);
    Print::print(listInt);
    std::cout << "Size: " << listInt.size() << std::endl;

    std::cout << "\n=== List<double> (template) ===" << std::endl;
    List<double> listDouble;
    listDouble.add(1.5);
    listDouble.add(2.5);
    listDouble.add(3.5);
    Print::print(listDouble);

    std::cout << "\n=== ArrayList with different types (Object*) ===" << std::endl;
    ArrayList arrMixed;
    arrMixed.add(new ObjectT<int>(42));
    arrMixed.add(new ObjectT<double>(3.14));
    arrMixed.add(new ObjectT<std::string>("hello"));
    Print::print(arrMixed);

    std::cout << "\n=== LinkedList with std::string (Object*) ===" << std::endl;
    LinkedList linkedStr;
    linkedStr.add(new ObjectT<std::string>("world"));
    linkedStr.add(new ObjectT<std::string>("!"));
    Print::print(linkedStr);

    std::cout << "\n=== Interface demo (ICollection*, IIterable*) ===" << std::endl;
    ICollection* col = &arrList;
    std::cout << "ArrayList isEmpty: " << (col->isEmpty() ? "yes" : "no") << std::endl;
    col->add(new ObjectT<int>(40));
    std::cout << "After add, size: " << col->size() << std::endl;
    col->removeAt(0);
    std::cout << "After removeAt(0): ";
    Print::print(arrList);
    col->clear();
    std::cout << "After clear, isEmpty: " << (col->isEmpty() ? "yes" : "no") << std::endl;

    std::cout << "\n=== IIterable interface demo ===" << std::endl;
    arrList.add(new ObjectT<int>(10));
    arrList.add(new ObjectT<int>(20));
    IIterable* iterable = &arrList;
    Print::print(iterable);

    return 0;
}
