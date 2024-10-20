#include <iostream>
#include <cmath>

class Point {
private:
    double x, y;

public:
    Point(double x = 0, double y = 0) : x(x), y(y) {}

    double getX() const { return x; }
    double getY() const { return y; }

    static double distance(const Point& p1, const Point& p2) {
        return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
    }

    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Point& p) {
        is >> p.x >> p.y;
        return is;
    }
};

int main() {
    Point p1(3, 4);
    Point p2(6, 8);

    std::cout << "Point 1: ";
    std::cin >> p1;
    std::cout << "Point 2: ";
    std::cin >> p2;

    std::cout << "Distance between points: " << Point::distance(p1, p2) << std::endl;

    return 0;
}