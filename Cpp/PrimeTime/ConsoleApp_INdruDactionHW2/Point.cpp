#include <iostream>
#include <fstream>
#include <sstream>
#include "Point.h"

Point::Point(int x, int y, int z) : x(x), y(y), z(z) {}

int Point::getX() const { return x; }
void Point::setX(int x) { this->x = x; }

int Point::getY() const { return y; }
void Point::setY(int y) { this->y = y; }

int Point::getZ() const { return z; }
void Point::setZ(int z) { this->z = z; }

// Определения как member-функций класса Point
void Point::GetFromtxt(const std::string& filename, Point& point) {
	std::ifstream file(filename); 
	if (!file.is_open()) {
		std::cerr << "Error opening file: " << filename << std::endl;
		return;
	}

	std::string line;
	while (std::getline(file, line)) {
		std::istringstream iss(line);
		std::string key;
		int value;
		if (!(iss >> key >> value)) { continue; }
		if (key == "x:") { point.setX(value); }
		else if (key == "y:") { point.setY(value); }
		else if (key == "z:") { point.setZ(value); }
	}
	file.close();
}

void Point::WriteTotxt(const std::string& filename, const Point& point) {
	std::ofstream file(filename); 
	if (!file.is_open()) {
		std::cerr << "Error opening file: " << filename << std::endl;
		return;
	}
	file << "x: " << point.getX() << std::endl;
	file << "y: " << point.getY() << std::endl;
	file << "z: " << point.getZ() << std::endl;
	file.close();
}
