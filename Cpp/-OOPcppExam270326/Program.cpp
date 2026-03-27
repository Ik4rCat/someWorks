#include <iostream>
#include <string>

#include "Point.h"
#include "Vector.h"

using namespace std;

int main()
{
    Vector<int> vecI{ 1, 2, 3, 4, 5 };
    vecI.print();

    Vector<double> vecII(3);
    vecII[0] = 1.5;
    vecII[1] = 2.5;
    vecII[2] = 3.5;
    vecII.print();

    Vector<string> vecIII{ " ", "funny", "Vector", "task", "Point class With <3"};
    vecIII.print();
    cout << vecIII[1] << vecIII[0] << vecIII[2] << vecIII[0] << vecIII[3] << endl;
    cout << vecIII[4] << endl;

    Vector<float> vecIV { 3.14 };
    cout << vecIV[0] << endl;
    vecIV.print();

    calculateAndPrint(vecI, 1, 2.0, 1);
    calculateAndPrint(vecI, 10, 0.0, 1);

    Point p(10.0, 20.0);
    p.show();

    return 0;
}