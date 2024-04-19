#include "header.h"

int main() {
    int linie;
    while (true) {
        std::cout << "Wprowadz liczbe linii dla czubka drzewa: ";
        std::cin >> linie;
        if (std::cin.fail() || linie <= 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Liczba linii musi byc dodatnia liczba calkowita.\n";
        }
        else if (linie < 2) {
            std::cout << "Drzewo musi miec co najmniej 2 linie, aby wygladalo jak drzewo.\n";
        }
        else if (linie > 11) {
            std::cout << "Drzewo bedzie wygladalo nie do konca idealnie z wiecej niz 11 liniami.\n";
        }
        else {
            break;
        }
    }
    drukujDrzewo(linie);
    return 0;
}
