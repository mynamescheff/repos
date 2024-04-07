#include "Circle.h"
#include <iostream>
#include <limits>

int main() {
    double x, y, radius;

    std::cout << "Enter circle center x, y coordinates: ";
    std::cin >> x >> y;
    do {
        std::cout << "Enter circle radius (greater than 0): ";
        std::cin >> radius;
        if (radius <= 0) {
            std::cout << "Radius must be greater than 0.\n";
            // Clear error flag and skip to the next line if input was not a number
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (radius <= 0);

    Circle circle(x, y, radius);

    std::cout << "Enter point x, y coordinates: ";
    std::cin >> x >> y;
    Point point(x, y);

    if (checkPointInCircle(circle, point)) {
        std::cout << "The point is inside the circle.\n";
    }
    else {
        std::cout << "The point is not inside the circle.\n";
    }

    return 0;
}
