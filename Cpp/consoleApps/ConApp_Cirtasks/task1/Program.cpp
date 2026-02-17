#include <iostream>
#include "Circle.h"

using namespace std;

int main()
{
    cout << "=== Testing Circle class ===" << endl << endl;
    
    Circle c1(5.0f);
    Circle c2(5.0f);
    Circle c3(7.0f);
    
    cout << "Created circles:" << endl;
    cout << "c1: "; c1.display();
    cout << "c2: "; c2.display();
    cout << "c3: "; c3.display();
    cout << endl;
    
    cout << "=== Test operator == (radius equality) ===" << endl;
    cout << "c1 == c2? " << (c1 == c2 ? "Yes" : "No") << endl;
    cout << "c1 == c3? " << (c1 == c3 ? "Yes" : "No") << endl;
    cout << endl;
    
    cout << "=== Test operator > (length comparison) ===" << endl;
    cout << "c3 > c1? " << (c3 > c1 ? "Yes" : "No") << endl;
    cout << "c1 > c3? " << (c1 > c3 ? "Yes" : "No") << endl;
    cout << endl;
    
    cout << "=== Test operator += ===" << endl;
    cout << "c1 before: "; c1.display();
    c1 += 3.0f;
    cout << "c1 after c1 += 3.0: "; c1.display();
    cout << endl;
    
    cout << "=== Test operator -= ===" << endl;
    cout << "c3 before: "; c3.display();
    c3 -= 2.0f;
    cout << "c3 after c3 -= 2.0: "; c3.display();
    cout << endl;
    
    cout << "=== Chain of operations ===" << endl;
    Circle c4(10.0f);
    cout << "c4 initially: "; c4.display();
    c4 += 5.0f;
    cout << "After c4 += 5.0: "; c4.display();
    c4 -= 8.0f;
    cout << "After c4 -= 8.0: "; c4.display();
    cout << endl;
    
}