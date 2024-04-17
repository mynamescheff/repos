#include <iostream>

// Base class Punkt
class Punkt {
public:
    Punkt() { std::cout << "konstruktor domyslny punkt\n"; }
    Punkt(int x, int y) { std::cout << "konstruktor parametryczny punkt\n"; }
    ~Punkt() { std::cout << "destruktor punkt\n"; }
};

// Derived class Kolo from Punkt
class Kolo : public Punkt {
public:
    Kolo() : Punkt() { std::cout << "konstruktor domyslny kolo\n"; }
    Kolo(int x, int y, int r) : Punkt(x, y) { std::cout << "konstruktor parametryczny kolo\n"; }
    ~Kolo() { std::cout << "destruktor kolo\n"; }
};

// Derived class Walec from Kolo
class Walec : public Kolo {
public:
    Walec() : Kolo() { std::cout << "konstruktor domyslny walec\n"; }
    Walec(int x, int y, int r, int h) : Kolo(x, y, r) { std::cout << "konstruktor parametryczny walec\n"; }
    ~Walec() { std::cout << "destruktor walec\n"; }
};

// Derived class Kwadrat from Punkt
class Kwadrat : public Punkt {
public:
    Kwadrat() : Punkt() { std::cout << "konstruktor domyslny kwadrat\n"; }
    Kwadrat(int x, int y, int sideLength) : Punkt(x, y) { std::cout << "konstruktor parametryczny kwadrat\n"; }
    ~Kwadrat() { std::cout << "destruktor kwadrat\n"; }
};

// Derived class Prostopadloscian from Kwadrat
class Prostopadloscian : public Kwadrat {
public:
    Prostopadloscian() : Kwadrat() { std::cout << "konstruktor domyslny prostopadloscian\n"; }
    Prostopadloscian(int x, int y, int sideLength, int h) : Kwadrat(x, y, sideLength) { std::cout << "konstruktor parametryczny prostopadloscian\n"; }
    ~Prostopadloscian() { std::cout << "destruktor prostopadloscian\n"; }
};

int main() {
    // Create objects using default constructors
    {
        Walec walecDomyslny;
        Prostopadloscian prostokatDomyslny;
    }

    std::cout << "**********\n";

    // Create objects using parameterized constructors
    {
        Walec walecParam(0, 0, 10, 20);
        Prostopadloscian prostokatParam(0, 0, 10, 20);
    }

    return 0;
}
