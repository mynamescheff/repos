#include "Header.h"
#include <iostream>

int main() {
    A a;
    B b;
    C c;
    int x;

    a.methodA();
    b.methodB();
    c.methodC();

    // Dostepne sa tylko czlonkowie publiczni odpowiednich klas:
    x = a.publiczny; // Poprawny dostep do publicznego czlonka klasy A

    // B i C dziedzicza prywatnie z A i B, wiec czlonkowie a i b nie sa dostepni:
    // x = b.publiczny; // Blad, nie mozna uzyskac dostepu
    // x = c.publiczny; // Blad, nie mozna uzyskac dostepu

    // Dostep do czlonkow zdefiniowanych jako publiczne w B i C:
    x = b.publicznyB; // Poprawny dostep do publicznego czlonka klasy B
    x = c.publicznyC; // Poprawny dostep do publicznego czlonka klasy C

    return 0;
}
