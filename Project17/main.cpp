#include "Header.h"

int main() {
    int linie;
    const int szerokosc_konsoli = 120;

    while (true) {
        std::cout << "Wprowadz liczbe linii na wierzcholek drzewa: ";
        std::cin >> linie;

        if (std::cin.fail() || linie <= 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Liczba linii musi byc dodatnia liczba calkowita." << std::endl;
        }
        else if (linie < 2) {
            std::cout << "Drzewo musi miec co najmniej 2 linie, aby wygladac jak drzewo." << std::endl;
        }
        else {
            break;
        }
    }

    drukujDrzewo(linie, szerokosc_konsoli);
    return 0;
}
