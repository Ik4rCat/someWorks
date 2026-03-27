#include <iostream>
#include <string>

#include "Point.h"
#include "Vector.h"

using namespace std;

int main()
{
    cout << "int vector: " << endl;
    Vector<int> vecI{ 1, 2, 3, 4, 5 };
    vecI.print();

    cout << "empty: " << (vecI.empty() ? "true" : "false") << endl;
    cout << "size: " << vecI.getSize() << endl;
    cout << "capacity: " << vecI.getCapacity() << endl;

    vecI.push(6);
    cout << "after push(6): " << endl;
    vecI.print();

    vecI.pop();
    cout << "after pop(): " << endl;
    vecI.print();

    vecI.insert(2, 99);
    cout << "after insert(2, 99): " << endl;
    vecI.print();

    vecI.resize(3);
    cout << "after resize(3): " << endl;
    vecI.print();


    cout << "\ndouble vector: " << endl;
    Vector<double> vecII(3);
    vecII[0] = 1.5;
    vecII[1] = 2;
    vecII[2] = 3.5;
    vecII.print();

    cout << "\nstring vector: " << endl;
    Vector<string> vecIII{ " ", "funny", "Vector", "task", "Point class With <3"};
    vecIII.print();
    cout << vecIII[1] << vecIII[0] << vecIII[2] << vecIII[0] << vecIII[3] << endl;
    cout << vecIII[4] << endl;

    cout << "\nfloat vector: " << endl;
    Vector<float> vecIV { 3.143, 3.154, 3.165 };
    vecIV.print();

    cout << "\nPoint's vector: " << endl;
    Vector<Point> vecV{ Point(0, 0), Point(1, 1), Point(2, 2), Point(2, 4), Point(4, 2)};
    vecV.print();

    cout << "\nCalculate & print (int+double)/long:" << endl;
    calculateAndPrint(vecI, 1, 2.0, 1);
    calculateAndPrint(vecI, 10, 0.0, 1);

    cout << endl;
    Point p(10.0, 20.0);
    p.show();

    return 0;
}
