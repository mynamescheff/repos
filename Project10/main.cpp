#include "header.h"

int main() {
    PrzykladowaKlasa obiekt1(10);
    PrzykladowaKlasa obiekt2 = obiekt1; // Kopiowanie obiektu

    std::cout << "Obiekt1 - ";
    pokazWartoscIAdres(obiekt1);
    std::cout << "Obiekt2 (kopia Obiekt1) - ";
    pokazWartoscIAdres(obiekt2);

    return 0;
}
