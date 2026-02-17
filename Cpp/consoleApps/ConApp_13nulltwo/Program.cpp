#include <iostream>

class Point
{
public:
  int x;
  int y;
  Point(int px, int py) : x(px), y(py) {}

  Point &operator++()
  {
    ++x, ++y;
    return *this;
  }

  Point operator++(int)
  {
    Point temp = *this;
    ++*this;
    return temp;
  }

  Point operator+(const Point &other) const
  {
    return Point(x + other.x, y + other.y);
  }

  Point operator-(const Point &other) const
  {
    return Point(x - other.x, y - other.y);
  }

  Point operator*(int scalar) const
  {
    return Point(x * scalar, y * scalar);
  }

  friend Point operator*(int scalar, const Point &pt)
  {
    return pt * scalar;
  }

  friend std::ostream &operator<<(std::ostream &out, const Point &po)
  {
    out << "(" << po.x << ", " << po.y << ")";
    return out;
  }

  friend std::istream &operator>>(std::istream &in, Point &po)
  {
    in >> po.x;
    in.ignore(1);
    in >> po.y;
    return in;
  }
};

int main()
{
  Point p1(2, 3);
  Point p2(1, 1);

  std::cout << "p1 = " << p1 << std::endl;
  std::cout << "p2 = " << p2 << std::endl;

  Point p3 = p1 + p2;
  std::cout << "p1 + p2 = " << p3 << std::endl;

  Point p4 = p1 - p2;
  std::cout << "p1 - p2 = " << p4 << std::endl;

  Point p5 = p1 * 3;
  std::cout << "p1 * 3 = " << p5 << std::endl;

  Point p6 = 2 * p2;
  std::cout << "2 * p2 = " << p6 << std::endl;

  ++p1;
  std::cout << "++p1 = " << p1 << std::endl;

  Point p7 = p2++;
  std::cout << "p2++ (old) = " << p7 << std::endl;
  std::cout << "p2 (new) = " << p2 << std::endl;

  return 0;
}