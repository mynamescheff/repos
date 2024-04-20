#include "Header.h"

void drukujLinie(int spacje, int gwiazdki) {
    spacje = std::max(0, spacje);
    gwiazdki = std::max(0, gwiazdki);

    std::cout << std::string(spacje, ' ') << std::string(gwiazdki, '*') << std::endl;
}

void drukujBlok(int poczatkowe_gwiazdki, int linie, int poczatkowe_spacje, int maks_szerokosc) {
    for (int i = 0; i < linie; ++i) {
        int biezace_gwiazdki = poczatkowe_gwiazdki + 2 * i;
        int spacje = poczatkowe_spacje + (maks_szerokosc - biezace_gwiazdki) / 2;
        drukujLinie(spacje, biezace_gwiazdki);
    }
}

void drukujDrzewo(int podstawa_linii, int szerokosc_konsoli) {
    int maks_szerokosc = 1 + 2 * (podstawa_linii - 1 + 2 + 4);

    int dodatkowe_wypelnienie = (szerokosc_konsoli - maks_szerokosc) / 2;
    dodatkowe_wypelnienie = std::max(0, dodatkowe_wypelnienie);

    int poczatkowa_spacja = ((maks_szerokosc - 1) / 2) + dodatkowe_wypelnienie;

    int spacja_pierwszej_linii = poczatkowa_spacja;

    drukujBlok(1, podstawa_linii, poczatkowa_spacja, maks_szerokosc);

    int poczatkowe_gwiazdki = 1 + 2 * (podstawa_linii - 1) - 2;
    drukujBlok(poczatkowe_gwiazdki, podstawa_linii + 2, poczatkowa_spacja, maks_szerokosc);

    poczatkowe_gwiazdki += 2 * (podstawa_linii + 1) - 6;
    drukujBlok(poczatkowe_gwiazdki, podstawa_linii + 4, poczatkowa_spacja, maks_szerokosc);

    int szerokosc_pnia = std::max(1, (podstawa_linii % 2 == 0) ? podstawa_linii + 1 : podstawa_linii) / 3;

    int spacja_pnia = spacja_pierwszej_linii + (maks_szerokosc - szerokosc_pnia) / 2;

    for (int i = 0; i < podstawa_linii; ++i) {
        drukujLinie(spacja_pnia, szerokosc_pnia);
    }
}
