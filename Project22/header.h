#ifndef HEADER_H
#define HEADER_H

#include <iostream>

// Klasa przykladowa do przeladowania operatorow
class Przyklad {
    int wartosc;
public:
    Przyklad(int v = 0) : wartosc(v) {}

    // Jednoargumentowy operator w klasie: operator++
    Przyklad& operator++();

    // Dwuargumentowy operator w klasie: operator+=
    Przyklad& operator+=(const Przyklad& inny);

    // Metoda do uzyskania wartosci
    int getWartosc() const { return wartosc; }

    // Deklaracja przyjazni dla funkcji globalnych
    friend Przyklad operator-(const Przyklad& p);
    friend Przyklad operator+(const Przyklad& p1, const Przyklad& p2);
    friend std::ostream& operator<<(std::ostream& os, const Przyklad& p);
};

// Jednoargumentowy operator globalnie: operator-
Przyklad operator-(const Przyklad& p);

// Dwuargumentowy operator globalnie: operator+
Przyklad operator+(const Przyklad& p1, const Przyklad& p2);

#endif // HEADER_H
