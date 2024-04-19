#include "Header.h"

PrzykladowaKlasa::PrzykladowaKlasa(int w) : wartosc(w) {}

PrzykladowaKlasa::PrzykladowaKlasa(const PrzykladowaKlasa& pk) : wartosc(pk.wartosc) {
    std::cout << "Uruchomiono konstruktor kopiujacy." << std::endl;
}

void pokazWartoscIAdres(const PrzykladowaKlasa& x) {
    std::cout << "Wartosc: " << x.wartosc << ", Adres: " << &x << std::endl;
}
