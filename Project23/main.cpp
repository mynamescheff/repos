#include "header.h"

int main() {
    double a, b;
    int x, y;

    std::cout << "Podaj dwie liczby do dzielenia: ";
    a = wczytajLiczbeDouble();
    b = wczytajLiczbeDouble();

    try {
        double wynik = dzielenie(a, b);
        std::cout << "Wynik dzielenia: " << wynik << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "Podaj dwie liczby do modulo: ";
    x = wczytajLiczbeInt();
    y = wczytajLiczbeInt();

    try {
        int wynik = modulo(x, y);
        std::cout << "Wynik modulo: " << wynik << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
