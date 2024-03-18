#include <iostream>
#include "BezKonstruktoraKopiujacego.h"
#include "ZKonstruktoremKopiujacym.h"

int main() {
    BezKonstruktoraKopiujacego obiekt1(10);
    BezKonstruktoraKopiujacego kopiaObiektu1 = obiekt1;

    std::cout << "Bez konstruktora kopiujacego:" << std::endl;
    std::cout << "Adres w obiekcie1: " << obiekt1.wsk << std::endl;
    std::cout << "Adres w kopiaObiektu1: " << kopiaObiektu1.wsk << std::endl;

    ZKonstruktoremKopiujacym obiekt2(20);
    ZKonstruktoremKopiujacym kopiaObiektu2 = obiekt2;

    std::cout << "\nZ konstruktorem kopiujacym:" << std::endl;
    std::cout << "Adres w obiekcie2: " << obiekt2.wsk << std::endl;
    std::cout << "Adres w kopiaObiektu2: " << kopiaObiektu2.wsk << std::endl;

    return 0;
}
