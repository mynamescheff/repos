#include <iostream>

class PrzykladowaKlasa {
    int wartosc;
public:
    PrzykladowaKlasa(int w) : wartosc(w) {} // Konstruktor
    PrzykladowaKlasa(const PrzykladowaKlasa& pk) : wartosc(pk.wartosc) {
        std::cout << "Uruchomiono konstruktor kopiujacy." << std::endl;
    } // Konstruktor kopiujacy
    friend void pokazWartoscIAdres(const PrzykladowaKlasa& x);
};

void pokazWartoscIAdres(const PrzykladowaKlasa& x) {
    std::cout << "Wartosc: " << x.wartosc << ", Adres: " << &x << std::endl;
}

int main() {
    PrzykladowaKlasa obiekt1(10);
    PrzykladowaKlasa obiekt2 = obiekt1; // Kopiowanie obiektu

    std::cout << "Obiekt1 - ";
    pokazWartoscIAdres(obiekt1);
    std::cout << "Obiekt2 (kopia Obiekt1) - ";
    pokazWartoscIAdres(obiekt2);

    return 0;
}
