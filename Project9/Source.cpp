#include "Circle.h"
#include <iostream>
#include <cmath>

Punkt::Punkt(double x, double y) : x(x), y(y) {
    std::cout << "Punkt stworzony w " << this << " z koordynatami: " << x << ", " << y << std::endl;
}
Punkt::~Punkt() {
    std::cout << "Punkt w " << this << " zniszczony z koordynatami: " << x << ", " << y << std::endl;
}

double Punkt::getX() const { return x; }
double Punkt::getY() const { return y; }

Okrag::Okrag(double x, double y, double promien) : srodek(x, y), promien(promien) {
    std::cout << "Okrag stworzony " << this << " ze srodkiem: (" << srodek.getX() << ", " << srodek.getY() << ") i promieniem " << promien << std::endl;
}
Okrag::~Okrag() {
    std::cout << "Okrag " << this << " zniszczony ze srodkiem: (" << srodek.getX() << ", " << srodek.getY() << ") i promieniem " << promien << std::endl;
}

// Definicje dla klasy Okrag
bool Okrag::zawieraPunkt(const Punkt& punkt) const {
    double dx = punkt.getX() - srodek.getX();
    double dy = punkt.getY() - srodek.getY();
    double odlegloscKwadrat = dx * dx + dy * dy;
    return odlegloscKwadrat <= promien * promien;
}

// Implementacja funkcji przyjacielskiej
bool sprawdzPunktWOkregu(const Okrag& okrag, const Punkt& punkt) {
    // bezposrednie uzycie prywatnych skladowych klasy Okrag
    return okrag.zawieraPunkt(punkt);
}