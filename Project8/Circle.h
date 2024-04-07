#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H

class Point {
public:
    Point(double x = 0.0, double y = 0.0);
    ~Point();
    double getX() const;
    double getY() const;

private:
    double x;
    double y;
};

class Circle {
public:
    Circle(double x = 0.0, double y = 0.0, double radius = 1.0);
    ~Circle();
    bool containsPoint(const Point& point) const;

private:
    Point center;
    double radius;
};

bool checkPointInCircle(const Circle& circle, const Point& point);

#endif
