#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <iomanip>
#include <limits>

// Funkcja konwertujaca lancuch znakow na wielkie litery
std::string naDuzeLitery(const std::string& input) {
    std::string output = input;
    std::transform(output.begin(), output.end(), output.begin(), ::toupper);
    return output;
}

// Funkcja usuwajaca biale znaki z poczatku i konca lancucha
std::string trim(const std::string& str) {
    size_t start = str.find_first_not_of(" \t\n\r\f\v");
    size_t end = str.find_last_not_of(" \t\n\r\f\v");
    return (start == std::string::npos) ? "" : str.substr(start, end - start + 1);
}

// Funkcja sprawdzajaca i konwertujaca lancuch znakow na liczbe zmiennoprzecinkowa
bool czyPoprawnaKwota(const std::string& input, double& output) {
    std::string czystyInput;
    bool maPrzecinek = false;

    for (char c : input) {
        if (c == ',' || c == '.') {
            if (maPrzecinek) return false; // Zwroc false, jesli wiecej niz jeden znak dziesietny
            maPrzecinek = true;
            czystyInput += '.'; // Normalizuj do kropki
        }
        else if (std::isdigit(c)) {
            czystyInput += c; // Zbieraj cyfry
        }
        else {
            return false; // Zwroc false, jesli znaleziono niecyfrowy znak lub znak dziesietny
        }
    }

    if (czystyInput.empty()) return false; // Upewnij sie, ze lancuch nie jest pusty

    std::istringstream stream(czystyInput);
    stream >> output;
    return !stream.fail() && stream.eof(); // Zwroc true, jesli konwersja sie powiodla i caly input zostal przeczytany
}

// Klasa reprezentujaca walute
class Waluta {
public:
    std::string kod; // Kod waluty, np. USD
    std::string nazwa; // Pelna nazwa waluty, np. United States Dollar
    double naUSD;     // Kurs wymiany na USD
    double zUSD;   // Kurs wymiany z USD

    Waluta() : kod(""), nazwa(""), naUSD(0.0), zUSD(0.0) {}
    Waluta(std::string k, std::string n, double t, double f) : kod(k), nazwa(n), naUSD(t), zUSD(f) {}
    Waluta(const Waluta& other) : kod(other.kod), nazwa(other.nazwa), naUSD(other.naUSD), zUSD(other.zUSD) {}
    ~Waluta() {}
};

// Klasa reprezentujaca konto bankowe
class KontoBankowe {
public:
    virtual double konwertuj(double kwota, const Waluta& z, const Waluta& na) const {
        return kwota * z.zUSD * na.naUSD;
    }
    virtual double naliczOplateBankowa(double kwota) const {
        return kwota * 0.98;
    }
    virtual ~KontoBankowe() {}
};

// Klasa reprezentujaca specjalne konto bankowe
class SpecjalneKonto : public KontoBankowe {
public:
    double konwertuj(double kwota, const Waluta& z, const Waluta& na) const override {
        double podstawowaKonwersja = KontoBankowe::konwertuj(kwota, z, na);
        return podstawowaKonwersja * 0.95; // Dodatkowa oplate 5%
    }
};

// Funkcja do wyswietlania szczegolow wymiany walut
void wyswietlWymianeBankowa(const KontoBankowe& konto, double kwota, const Waluta& z, const Waluta& na) {
    double poczatkowaKonwersja = konto.konwertuj(kwota, z, na);
    double poOplacie = konto.naliczOplateBankowa(poczatkowaKonwersja);
    double ponownaKonwersja = konto.konwertuj(poOplacie, na, z);
    double koncowaKwota = konto.naliczOplateBankowa(ponownaKonwersja);

    std::cout << std::fixed << std::setprecision(2); // Ustawianie precyzji na 2 miejsca po przecinku
    std::cout << "Bezposrednia konwersja: " << kwota << " " << z.kod << " to rownowaznosc " << poczatkowaKonwersja << " " << na.kod << "." << std::endl;
    std::cout << "Po naliczeniu 2% prowizji bankowej: " << kwota << " " << z.kod << " daje " << poOplacie << " " << na.kod << "." << std::endl;
    std::cout << "Konwersja z powrotem po 2% prowizji: " << poOplacie << " " << na.kod << " daje " << koncowaKwota << " " << z.kod << "." << std::endl;
}

// Funkcja do wyswietlania szczegolow wymiany walut dla specjalnego konta
void wyswietlWymianeSpecjalna(const SpecjalneKonto& konto, double kwota, const Waluta& z, const Waluta& na) {
    double poczatkowaKonwersja = konto.konwertuj(kwota, z, na);
    double poOplacie = konto.naliczOplateBankowa(poczatkowaKonwersja);
    double ponownaKonwersja = konto.konwertuj(poOplacie, na, z);
    double koncowaKwota = konto.naliczOplateBankowa(ponownaKonwersja);

    std::cout << std::fixed << std::setprecision(2); // Ustawianie precyzji na 2 miejsca po przecinku
    std::cout << "Bezposrednia konwersja (specjalne konto): " << kwota << " " << z.kod << " to rownowaznosc " << poczatkowaKonwersja << " " << na.kod << "." << std::endl;
    std::cout << "Po naliczeniu 2% prowizji bankowej (i 5% kantor): " << kwota << " " << z.kod << " daje " << poOplacie << " " << na.kod << "." << std::endl;
    std::cout << "Konwersja z powrotem po 2% prowizji (i 5% kantor): " << poOplacie << " " << na.kod << " daje " << koncowaKwota << " " << z.kod << "." << std::endl;
}

int main() {
    std::map<std::string, Waluta> waluty; // Mapa przechowujaca dostepne waluty

    try {
        std::ifstream plik("CurrencyExchangeRates.txt"); // Otworz plik z kursami walut
        if (!plik.is_open())
            throw std::runtime_error("Nie udalo sie otworzyc pliku. Sprawdz sciezke do pliku.");

        std::string linia;
        std::getline(plik, linia); // Pomin pierwszy wiersz komentarza
        std::getline(plik, linia); // Pomin wiersz z opisem formatu

        while (std::getline(plik, linia)) {
            std::istringstream iss(linia);
            std::string kodWaluty, nazwaWaluty;
            double usdDoWaluty, walutaDoUsd;
            if (!(iss >> kodWaluty >> nazwaWaluty >> usdDoWaluty >> walutaDoUsd))
                throw std::runtime_error("Niepoprawny format pliku.");

            waluty[kodWaluty] = Waluta(kodWaluty, nazwaWaluty, usdDoWaluty, walutaDoUsd); // Dodaj walute do mapy
        }

        for (const auto& pair : waluty) {
            std::cout << pair.first << " (" << pair.second.nazwa << ")" << std::endl; // Wyswietl dostepne waluty
        }

        KontoBankowe konto;
        SpecjalneKonto specjalneKonto;
        std::string zWaluty, naWaluty;
        double kwota;
        bool zWalutyPoprawny = false, naWalutyPoprawny = false, kwotaPoprawna = false;

        // Petla do wprowadzania kodu waluty
        while (!zWalutyPoprawny) {
            std::cout << "Wprowadz kod waluty, ktora posiadasz: ";
            std::getline(std::cin, zWaluty); // Uzyj getline, aby odczytac cala linie
            zWaluty = trim(naDuzeLitery(zWaluty));

            if (waluty.find(zWaluty) == waluty.end()) {
                std::cout << "Kod waluty nie znaleziony. Sprobuj ponownie.\n";
            }
            else {
                zWalutyPoprawny = true;
            }
        }

        // Petla do wprowadzania kwoty
        std::string inputKwota;
        while (!kwotaPoprawna) {
            std::cout << "Wprowadz kwote, ktora posiadasz: ";
            std::getline(std::cin, inputKwota); // Uzyj getline, aby odczytac cala linie

            if (!czyPoprawnaKwota(trim(inputKwota), kwota)) {
                std::cout << "Niepoprawna kwota. Uzywaj tylko cyfr i jednego znaku dziesietnego.\n";
            }
            else {
                kwotaPoprawna = true;
            }
        }

        // Petla do wprowadzania kodu waluty docelowej
        while (!naWalutyPoprawny) {
            std::cout << "Wprowadz kod waluty, na ktora chcesz zamienic: ";
            std::getline(std::cin, naWaluty); // Uzyj getline, aby odczytac cala linie
            naWaluty = trim(naDuzeLitery(naWaluty));

            if (waluty.find(naWaluty) == waluty.end()) {
                std::cout << "Kod waluty nie znaleziony. Sprobuj ponownie.\n";
            }
            else {
                naWalutyPoprawny = true;
            }
        }

        double kwotaPoKonwersji = konto.konwertuj(kwota, waluty[zWaluty], waluty[naWaluty]);
        std::cout << std::fixed << std::setprecision(2); // Ustawianie precyzji na 2 miejsca po przecinku
        std::cout << kwota << " " << zWaluty << " to rownowaznosc " << kwotaPoKonwersji << " " << naWaluty << "." << std::endl;

        wyswietlWymianeBankowa(konto, kwota, waluty[zWaluty], waluty[naWaluty]); // Wyswietl szczegoly wymiany walut
        wyswietlWymianeSpecjalna(specjalneKonto, kwota, waluty[zWaluty], waluty[naWaluty]); // Wyswietl szczegoly wymiany walut dla specjalnego konta

    }
    catch (const std::exception& e) {
        std::cerr << "Blad: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
