#include "header.h"

void drukujLinie(int spacja, int gwiazdki) {
    spacja = std::max(0, spacja);
    gwiazdki = std::max(0, gwiazdki);
    std::cout << std::string(spacja, ' ') << std::string(gwiazdki, '*') << std::endl;
}

void drukujBlok(int start_gwiazdki, int linie, int poczatkowa_spacja, int maks_szerokosc) {
    for (int i = 0; i < linie; ++i) {
        int biezace_gwiazdki = start_gwiazdki + 2 * i;
        int spacja = poczatkowa_spacja + (maks_szerokosc - biezace_gwiazdki) / 2;
        drukujLinie(spacja, biezace_gwiazdki);
    }
}

void drukujDrzewo(int podstawa_linie) {
    int maks_szerokosc = 1 + 2 * (podstawa_linie - 1 + 2 + podstawa_linie + 2);
    int poczatkowa_spacja = (maks_szerokosc - 1) / 2;

    int pierwsza_linia_spacja = poczatkowa_spacja;

    drukujBlok(1, podstawa_linie, poczatkowa_spacja, maks_szerokosc);
    int start_gwiazdki = 1 + 2 * (podstawa_linie - 1) - 2;
    drukujBlok(start_gwiazdki, podstawa_linie + 2, poczatkowa_spacja, maks_szerokosc);
    start_gwiazdki += 2 * (podstawa_linie + 1) - 6;
    drukujBlok(start_gwiazdki, podstawa_linie + 4, poczatkowa_spacja, maks_szerokosc);

    int szerokosc_pnia = std::max(1, std::min(podstawa_linie, static_cast<int>(std::round(podstawa_linie / 3.0)) * 2 + 1));
    int spacja_pnia = (maks_szerokosc - szerokosc_pnia) / 2;

    for (int i = 0; i < podstawa_linie; ++i) {
        drukujLinie(spacja_pnia, szerokosc_pnia);
    }
}
