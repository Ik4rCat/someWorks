

Point::Point(double xVal, double yVal) : x(xVal), y(yVal) {}
Point::~Point() = default;

void Point::show() const {
    std::cout << "Point has 0 angles" << std::endl;
}