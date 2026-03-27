

Point::Point() : x(0), y(0) {}
Point::Point(double xVal, double yVal) : x(xVal), y(yVal) {}
Point::~Point() = default;

void Point::show() const {
    std::cout << "Point has 0 angles" << std::endl;
}

inline std::ostream& operator<<(std::ostream& os, const Point& p) {
    return os << "(" << p.x << ", " << p.y << ")";
}