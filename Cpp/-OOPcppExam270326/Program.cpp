#include <iostream>

#include "Point.h"
#include "Vector.h"

using namespace std;

int main()
{
    Vector<int> vec1{ 1, 2, 3, 4, 5 };
    vec1.print();

    Vector<double> vec2(3);
    vec2[0] = 1.5;
    vec2[1] = 2.5;
    vec2[2] = 3.5;
    vec2.print();

    calculateAndPrint(vec1, 1, 2.0, 1);
    calculateAndPrint(vec1, 10, 0.0, 1);

    Point p(10.0, 20.0);
    p.show();

    return 0;
}