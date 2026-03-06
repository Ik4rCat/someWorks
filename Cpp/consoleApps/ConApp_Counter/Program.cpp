#include <iostream>

// task 1

class Counter
{
private:
    int count;
public:
    Counter() : count(5) {}
    int operator++(int) { int old = count; count++; return old; }
    int getCount() const { return count; }
};

// task 2

class Point3d
{
private:
    int x, y, z;
public:
    Point3d() : x(0), y(0), z(0) {}
    Point3d(int x1, int y1, int z1) : x(x1), y(y1), z(z1) {}

    operator bool() const { return x && y && z; }

    friend std::ostream& operator<<(std::ostream& os, const Point3d& p) {
        return os << "(" << p.x << ", " << p.y << ", " << p.z << ")";
    }
};

class Point
{
private:
    int x, y;
public:
    Point() : x(0), y(0) {}
    Point(int x1, int y1) : x(x1), y(y1) {}

    operator bool() const { return x && y; }

    explicit operator Point3d() const { return Point3d(x, y, 0); }

    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        return os << "(" << p.x << ", " << p.y << ")";
    }
};

int main()
{
    std::cout << "=== task1: Counter ===" << std::endl;
    
    Counter c;
    std::cout << "start count: " << c.getCount() << std::endl;
    int oldVal = c++;
    std::cout << "after ++: old = " << oldVal << ", header count = " << c.getCount() << std::endl;

    std::cout << "\n=== task2: Point и Point3d ===" << std::endl;
    
    Point p;                              // (0, 0) — false
    Point p2(3, 4);               // (3, 4) — true
    Point3d p3d;                        // (0, 0, 0) — false
    Point3d p3d2(1, 2, 3);  // true

    std::cout << "p(0,0):  (bool)p = " << (bool)p << ", Point3d: " << (Point3d)p << std::endl;
    std::cout << "p2(3,4): (bool)p2 = " << (bool)p2 << ", Point3d: " << (Point3d)p2 << std::endl;
    std::cout << "p3d:     (bool)p3d = " << (bool)p3d << std::endl;
    std::cout << "p3d2:    (bool)p3d2 = " << (bool)p3d2 << ", " << p3d2 << std::endl;
}