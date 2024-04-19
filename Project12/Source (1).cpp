#include <iostream>
#include <string>
#include <algorithm>

void drukujLinie(int spacja, int gwiazdki) {
    // sprawdzenie, ze spacja i gwiazdki nie sa ujemne
    spacja = std::max(0, spacja);
    gwiazdki = std::max(0, gwiazdki);

    std::cout << std::string(spacja, ' ') << std::string(gwiazdki, '*') << std::endl;
}

void drukujBlok(int start_gwiazdki, int linie, int poczatkowa_spacja, int maks_szerokosc) {
    for (int i = 0; i < linie; ++i) {
        // wysrodkowanie linii
        int biezace_gwiazdki = start_gwiazdki + 2 * i;
        int spacja = poczatkowa_spacja + (maks_szerokosc - biezace_gwiazdki) / 2;
        drukujLinie(spacja, biezace_gwiazdki);
    }
}

void drukujDrzewo(int podstawa_linie) {
    //  maksymalna szerokosc drzewa
    int maks_szerokosc = 1 + 2 * (podstawa_linie - 1 + 2 + podstawa_linie + 2); // to uwzglednia, ze blok 3 jest najszerszy

    // Poczatkowa spacja
    int poczatkowa_spacja = (maks_szerokosc - 1) / 2;

    // wyrownanie pnia
    int pierwsza_linia_spacja = poczatkowa_spacja;

    // Drukuj blok 1
    drukujBlok(1, podstawa_linie, poczatkowa_spacja, maks_szerokosc);

    // Drukuj blok 2, ktory zaczyna sie o 2 gwiazdki mniej niz ostatnia linia bloku 1
    int start_gwiazdki = 1 + 2 * (podstawa_linie - 1) - 2;
    drukujBlok(start_gwiazdki, podstawa_linie + 2, poczatkowa_spacja, maks_szerokosc);

    // Drukuj blok 3, ktory zaczyna sie o 6 gwiazdek mniej niz ostatnia linia bloku 2
    start_gwiazdki += 2 * (podstawa_linie + 1) - 6;
    drukujBlok(start_gwiazdki, podstawa_linie + 4, poczatkowa_spacja, maks_szerokosc);

    int szerokosc_pnia = std::max(1, std::min(podstawa_linie, static_cast<int>(std::round(podstawa_linie / 3.0)) * 2 + 1));
    int spacja_pnia = (maks_szerokosc - szerokosc_pnia) / 2;

    // Drukuj pien
    for (int i = 0; i < podstawa_linie; ++i) {
        drukujLinie(spacja_pnia, szerokosc_pnia);
    }
}

int main() {
    int linie;

    while (true) {
        std::cout << "Wprowadz liczbe linii dla czubka drzewa: ";
        std::cin >> linie;

        if (std::cin.fail() || linie <= 0) {
            std::cin.clear(); // Wyczysc flage bledu
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignoruj zly input
            std::cout << "Liczba linii musi byc dodatnia liczba calkowita." << std::endl;
        }
        else if (linie < 2) {
            std::cout << "Drzewo musi miec co najmniej 2 linie, aby wygladalo jak drzewo." << std::endl;
        }
        else if (linie > 11) {
            std::cout << "Drzewo bedzie wygladalo nie do konca idealnie z wiecej niz 11 liniami." << std::endl;
        }
        else {
            break; // Prawidlowe dane wejsciowe
        }
    }

    drukujDrzewo(linie);
    return 0;
}
