#pragma once
#include <string>

class Point 
{
private:
	int x, y, z;
public:
	Point(int x, int y, int z);
	int getX() const;
	void setX(int x);

	int getY() const;
	void setY(int y);

	int getZ() const;
	void setZ(int z);

	static void GetFromtxt(const std::string& filename, Point& point);
	static void WriteTotxt(const std::string& filename, const Point& point);
};	