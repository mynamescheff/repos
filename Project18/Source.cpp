#include "header.h"

// Definicje konstruktorow i destruktorow dla Punkt
Punkt::Punkt() { std::cout << "konstruktor domyslny punkt\n"; }
Punkt::Punkt(int x, int y) { std::cout << "konstruktor parametryczny punkt\n"; }
Punkt::~Punkt() { std::cout << "destruktor punkt\n"; }

// Definicje konstruktorow i destruktorow dla Kolo
Kolo::Kolo() : Punkt() { std::cout << "konstruktor domyslny kolo\n"; }
Kolo::Kolo(int x, int y, int r) : Punkt(x, y) { std::cout << "konstruktor parametryczny kolo\n"; }
Kolo::~Kolo() { std::cout << "destruktor kolo\n"; }

// Definicje konstruktorow i destruktorow dla Walec
Walec::Walec() : Kolo() { std::cout << "konstruktor domyslny walec\n"; }
Walec::Walec(int x, int y, int r, int h) : Kolo(x, y, r) { std::cout << "konstruktor parametryczny walec\n"; }
Walec::~Walec() { std::cout << "destruktor walec\n"; }

// Definicje konstruktorow i destruktorow dla Kwadrat
Kwadrat::Kwadrat() : Punkt() { std::cout << "konstruktor domyslny kwadrat\n"; }
Kwadrat::Kwadrat(int x, int y, int sideLength) : Punkt(x, y) { std::cout << "konstruktor parametryczny kwadrat\n"; }
Kwadrat::~Kwadrat() { std::cout << "destruktor kwadrat\n"; }

// Definicje konstruktorow i destruktorow dla Prostopadloscian
Prostopadloscian::Prostopadloscian() : Kwadrat() { std::cout << "konstruktor domyslny prostopadloscian\n"; }
Prostopadloscian::Prostopadloscian(int x, int y, int sideLength, int h) : Kwadrat(x, y, sideLength) { std::cout << "konstruktor parametryczny prostopadloscian\n"; }
Prostopadloscian::~Prostopadloscian() { std::cout << "destruktor prostopadloscian\n"; }
