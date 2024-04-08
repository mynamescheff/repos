#include "Circle.h"
#include <iostream>
#include <limits>

int main() {
    double x, y, promien;

    std::cout << "Wprowadz srodek kola o koordynatach x, y: ";
    std::cin >> x >> y;
    do {
        std::cout << "Wprowadz promien kola (wiekszy jak 0): ";
        std::cin >> promien;
        if (promien <= 0) {
            std::cout << "promien musi byc wiekszy niz 0.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (promien <= 0);

    Okrag kolo(x, y, promien);

    std::cout << "Wprowadz punkt o koordynatach x, y: ";
    std::cin >> x >> y;
    Punkt punkt(x, y);

    if (sprawdzPunktWOkregu(kolo, punkt)) {
        std::cout << "Punkt jest w srodku okregu.\n";
    }
    else {
        std::cout << "Punkt nie jest w okregu.\n";
    }

    return 0;
}
