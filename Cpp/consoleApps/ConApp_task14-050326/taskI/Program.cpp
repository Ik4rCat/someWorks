#include <iostream>

#include "Point.h"
#include "Massiv.h"

int main()
{
    std::cout << "Start program!" << std::endl;

    Massiv<Point<double>> points(3);

    points.setValue(0, Point<double>(1.0, 2.0, 3.0));
    points.setValue(1, Point<double>(4.0, 5.0, 6.0));
    points.setValue(2, Point<double>(7.0, 8.0, 9.0));

    std::cout << "In Massiv Point<double>:" << std::endl;
    for (int i = 0; i < points.getSize(); ++i)
    {
        points.getValue(i).print();
        std::cout << std::endl;
    }

    std::cout << "End program!" << std::endl;
    return 0;
}