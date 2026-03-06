#include <iostream>
#include "Point.h"

int main()
{
	Point point(0, 0, 0);
	Point::WriteTotxt("point.txt", point);
	std::cout << "Point written to file: (" << point.getX() << ", " << point.getY() << ", " << point.getZ() << ")" << std::endl;
	point.setX(10);
	point.setY(20);
	point.setZ(30);
	Point::GetFromtxt("point.txt", point);
	std::cout << "Point read from file: (" << point.getX() << ", " << point.getY() << ", " << point.getZ() << ")" << std::endl;
	return 0;
}