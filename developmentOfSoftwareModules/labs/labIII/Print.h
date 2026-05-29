#pragma once

#include "ArrayList.h"
#include "LinkedList.h"
#include "List.h"
#include "Iterator.h"
#include "IIterable.h"
#include "Object.h"
#include <iostream>

class Print {
public:
    static void print(ArrayList& list) {
        std::cout << "ArrayList [";
        for (int i = 0; i < list.size(); i++) {
            if (i > 0) std::cout << ", ";
            list.getAt(i)->print(std::cout);
        }
        std::cout << "]" << std::endl;
    }

    static void print(LinkedList& list) {
        std::cout << "LinkedList [";
        Iterator* it = list.getIterator();
        bool first = true;
        while (it->hasNext()) {
            if (!first) std::cout << ", ";
            it->next()->print(std::cout);
            first = false;
        }
        std::cout << "]" << std::endl;
        delete it;
    }

    template<typename T>
    static void print(List<T>& list) {
        std::cout << "List [";
        for (int i = 0; i < list.size(); i++) {
            if (i > 0) std::cout << ", ";
            std::cout << list.getAt(i);
        }
        std::cout << "]" << std::endl;
    }

    static void print(IIterable* iterable) {
        std::cout << "IIterable [";
        Iterator* it = iterable->getIterator();
        bool first = true;
        while (it->hasNext()) {
            if (!first) std::cout << ", ";
            it->next()->print(std::cout);
            first = false;
        }
        std::cout << "]" << std::endl;
        delete it;
    }
};
