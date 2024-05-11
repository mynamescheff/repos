#include "header.h"

int main() {
    // Tworzenie obiektow przy uzyciu konstruktorow domyslnych
    {
        Walec walecDomyslny;
        Prostopadloscian prostokatDomyslny;
    }

    std::cout << "**********\n";

    // Tworzenie obiektow przy uzyciu konstruktorow parametrycznych
    {
        Walec walecParam(0, 0, 10, 20);
        Prostopadloscian prostokatParam(0, 0, 10, 20);
    }

    return 0;
}
