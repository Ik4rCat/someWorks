
#include <iostream>

struct Point {
    int x;
    int y;
};

Point add(Point a, Point b) {
    Point result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    return result;
}

int main() {
    Point p1 = {1, 2};
    Point p2 = {3, 4};
    Point p3 = add(p1, p2);
    std::cout << p3.x << ", " << p3.y << std::endl;
    return 0;
}
