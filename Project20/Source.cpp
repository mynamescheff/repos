#include "header.h"
#define _USE_MATH_DEFINES
#include <math.h>

// Implementacja klasy Kolo
Kolo::Kolo(double r) : radius(r) {}
double Kolo::pole() const {
    return M_PI * radius * radius;
}
Kolo::~Kolo() {
    std::cout << "destruktor kolo" << std::endl;
}

// Implementacja klasy Kwadrat
Kwadrat::Kwadrat(double s) : side(s) {}
double Kwadrat::pole() const {
    return side * side;
}
Kwadrat::~Kwadrat() {
    std::cout << "destruktor kwadrat" << std::endl;
}

// Implementacja klasy Walec
Walec::Walec(double r, double h) : radius(r), height(h) {}
double Walec::pole() const {
    return 2 * M_PI * radius * (radius + height);
}
Walec::~Walec() {
    std::cout << "destruktor walca" << std::endl;
}

// Implementacja klasy Szescian
Szescian::Szescian(double s) : side(s) {}
double Szescian::pole() const {
    return 6 * side * side;
}
Szescian::~Szescian() {
    std::cout << "destruktor szescian" << std::endl;
}

void oblicz(const Obiekt* obj) {
    std::cout << "Pole obliczone przez funkcje oblicz: " << obj->pole() << std::endl;
}
