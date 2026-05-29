#include <iostream>
#include "Country.h"

int main() {
    std::cout << "Creating object r1 with default constructor:" << std::endl;
    Country r1;
    r1.show();

    std::cout << "\nCreating object r2 with parameterized constructor:" << std::endl;
    Country r2((char*)"CountryA", 1000000, (char*)"President A");
    r2.show();

    std::cout << "\nCreating object r3 with copy constructor (copy of r2):" << std::endl;
    Country r3(r2);
    r3.show();

    std::cout << "\nUsing pointer to object:" << std::endl;
    Country* ptr = &r2;
    ptr->show();
    ptr->setCitizens(1500000);
    std::cout << "After modification via pointer: ";
    ptr->show();

    std::cout << "\nUsing pointer to member function:" << std::endl;
    void (Country::*showFunc)() const = &Country::show;
    (r1.*showFunc)();
    (ptr->*showFunc)();

    std::cout << "\nCreating dynamic object:" << std::endl;
    Country* dynPtr = new Country((char*)"CountryB", 500000, (char*)"President B");
    dynPtr->show();
    delete dynPtr;

    std::cout << "\nProgram end - destructors will be called for r1, r2, r3:" << std::endl;
    return 0;
}
