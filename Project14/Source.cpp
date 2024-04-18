#include <iostream>

// Klasa bazowa Punkt
class Punkt {
public:
    Punkt() { std::cout << "konstruktor domyslny punkt\n"; }
    Punkt(int x, int y) { std::cout << "konstruktor parametryczny punkt\n"; }
    ~Punkt() { std::cout << "destruktor punkt\n"; }
};

// Klasa pochodna Kolo od Punkt
class Kolo : public Punkt {
public:
    Kolo() : Punkt() { std::cout << "konstruktor domyslny kolo\n"; }
    Kolo(int x, int y, int r) : Punkt(x, y) { std::cout << "konstruktor parametryczny kolo\n"; }
    ~Kolo() { std::cout << "destruktor kolo\n"; }
};

// Klasa pochodna Walec od Kolo
class Walec : public Kolo {
public:
    Walec() : Kolo() { std::cout << "konstruktor domyslny walec\n"; }
    Walec(int x, int y, int r, int h) : Kolo(x, y, r) { std::cout << "konstruktor parametryczny walec\n"; }
    ~Walec() { std::cout << "destruktor walec\n"; }
};

// Klasa pochodna Kwadrat od Punkt
class Kwadrat : public Punkt {
public:
    Kwadrat() : Punkt() { std::cout << "konstruktor domyslny kwadrat\n"; }
    Kwadrat(int x, int y, int dlugoscBoku) : Punkt(x, y) { std::cout << "konstruktor parametryczny kwadrat\n"; }
    ~Kwadrat() { std::cout << "destruktor kwadrat\n"; }
};

// Klasa pochodna Prostopadloscian od Kwadrat
class Prostopadloscian : public Kwadrat {
public:
    Prostopadloscian() : Kwadrat() { std::cout << "konstruktor domyslny prostopadloscian\n"; }
    Prostopadloscian(int x, int y, int dlugoscBoku, int h) : Kwadrat(x, y, dlugoscBoku) { std::cout << "konstruktor parametryczny prostopadloscian\n"; }
    ~Prostopadloscian() { std::cout << "destruktor prostopadloscian\n"; }
};

int main() {
    // Tworzenie obiektow przy uzyciu konstruktorow domyslnych
    {
        Walec walecDomyslny;
        Prostopadloscian prostokatDomyslny;
    }

    std::cout << "**********\n";

    // Tworzenie obiektow przy uzyciu konstruktorow parametrycznych
    {
        Walec walecParam(0, 0, 10, 20);
        Prostopadloscian prostokatParam(0, 0, 10, 20);
    }

    return 0;
}
