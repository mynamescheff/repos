#include "Circle.h"
#include <iostream>
#include <cmath>

Point::Point(double x, double y) : x(x), y(y) {
    std::cout << "Point created at " << this << " with coordinates: " << x << ", " << y << std::endl;
}
Point::~Point() {
    std::cout << "Point at " << this << " destroyed with coordinates: " << x << ", " << y << std::endl;
}

double Point::getX() const { return x; }
double Point::getY() const { return y; }

Circle::Circle(double x, double y, double radius) : center(x, y), radius(radius) {
    std::cout << "Circle created at " << this << " with center: (" << center.getX() << ", " << center.getY() << ") and radius " << radius << std::endl;
}
Circle::~Circle() {
    std::cout << "Circle at " << this << " destroyed with center: (" << center.getX() << ", " << center.getY() << ") and radius " << radius << std::endl;
}

bool Circle::containsPoint(const Point& point) const {
    double dx = point.getX() - center.getX();
    double dy = point.getY() - center.getY();
    double distanceSquared = dx * dx + dy * dy;
    return distanceSquared <= radius * radius;
}

bool checkPointInCircle(const Circle& circle, const Point& point) {
    return circle.containsPoint(point);
}
