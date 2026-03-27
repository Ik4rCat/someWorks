

int Point::count = 0;

Point::Point() : x(0), y(0) {
    ++count;
}

Point::Point(double xVal, double yVal) : x(xVal), y(yVal) {
    ++count;
}

Point::~Point() {
    --count;
}

void Point::show() const {
    std::cout << "Количество точек: " << count << std::endl;
}

inline std::ostream& operator<<(std::ostream& os, const Point& p) {
    return os << "(" << p.x << ", " << p.y << ")";
}