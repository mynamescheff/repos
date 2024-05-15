#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <limits>

// Funkcja konwertujaca lancuch znakow na wielkie litery
std::string toUpperCase(const std::string& input) {
    std::string output = input;
    std::transform(output.begin(), output.end(), output.begin(), ::toupper);
    return output;
}

// Funkcja sprawdzajaca i konwertujaca lancuch znakow na liczbe zmiennoprzecinkowa
bool isValidAmount(const std::string& input, double& output) {
    std::string cleanInput;
    bool hasDecimal = false;

    for (char c : input) {
        if (c == ',' || c == '.') {
            if (hasDecimal) return false; // Zwroc false, jesli wiecej niz jeden znak dziesietny
            hasDecimal = true;
            cleanInput += '.'; // Normalizuj do kropki
        }
        else if (std::isdigit(c)) {
            cleanInput += c; // Zbieraj cyfry
        }
        else {
            return false; // Zwroc false, jesli znaleziono niecyfrowy znak lub znak dziesietny
        }
    }

    if (cleanInput.empty()) return false; // Upewnij sie, ze lancuch nie jest pusty

    std::istringstream stream(cleanInput);
    stream >> output;
    return !stream.fail() && stream.eof(); // Zwroc true, jesli konwersja sie powiodla i caly input zostal przeczytany
}

// Klasa reprezentujaca walute
class Currency {
public:
    std::string code; // Kod waluty, np. USD
    std::string name; // Pelna nazwa waluty, np. United States Dollar
    double toUSD;     // Kurs wymiany na USD
    double fromUSD;   // Kurs wymiany z USD

    Currency() : code(""), name(""), toUSD(0.0), fromUSD(0.0) {}
    Currency(std::string c, std::string n, double t, double f) : code(c), name(n), toUSD(t), fromUSD(f) {}
    Currency(const Currency& other) : code(other.code), name(other.name), toUSD(other.toUSD), fromUSD(other.fromUSD) {}
    ~Currency() {}
};

// Klasa reprezentujaca konto bankowe
class BankAccount {
public:
    virtual double convert(double amount, const Currency& from, const Currency& to) const {
        return amount * from.fromUSD * to.toUSD;
    }
    virtual double applyBankFee(double amount) const {
        return amount * 0.98;
    }
    virtual ~BankAccount() {}
};

// Klasa reprezentujaca specjalne konto bankowe
class SpecialAccount : public BankAccount {
public:
    double convert(double amount, const Currency& from, const Currency& to) const override {
        double baseConversion = BankAccount::convert(amount, from, to);
        return baseConversion * 0.95; // Dodatkowa opłata 5%
    }
};

// Funkcja do wyswietlania szczegolow wymiany walut
void displayBankExchange(const BankAccount& account, double amount, const Currency& from, const Currency& to) {
    double initialConversion = account.convert(amount, from, to);
    double afterFee = account.applyBankFee(initialConversion);
    double backConversion = account.convert(afterFee, to, from);
    double finalAmount = account.applyBankFee(backConversion);

    std::cout << "Bezposrednia konwersja: " << amount << " " << from.code << " to rownowaznosc " << initialConversion << " " << to.code << "." << std::endl;
    std::cout << "Po naliczeniu 2% prowizji bankowej: " << amount << " " << from.code << " daje " << afterFee << " " << to.code << "." << std::endl;
    std::cout << "Konwersja z powrotem po 2% prowizji: " << afterFee << " " << to.code << " daje " << finalAmount << " " << from.code << "." << std::endl;
}

// Funkcja do wyswietlania szczegolow wymiany walut dla specjalnego konta
void displaySpecialExchange(const SpecialAccount& account, double amount, const Currency& from, const Currency& to) {
    double initialConversion = account.convert(amount, from, to);
    double afterFee = account.applyBankFee(initialConversion);
    double backConversion = account.convert(afterFee, to, from);
    double finalAmount = account.applyBankFee(backConversion);

    std::cout << "Bezposrednia konwersja (specjalne konto): " << amount << " " << from.code << " to rownowaznosc " << initialConversion << " " << to.code << "." << std::endl;
    std::cout << "Po naliczeniu 2% prowizji bankowej (i 5% kantor): " << amount << " " << from.code << " daje " << afterFee << " " << to.code << "." << std::endl;
    std::cout << "Konwersja z powrotem po 2% prowizji (i 5% kantor): " << afterFee << " " << to.code << " daje " << finalAmount << " " << from.code << "." << std::endl;
}

int main() {
    std::map<std::string, Currency> currencies; // Mapa przechowujaca dostepne waluty

    try {
        std::ifstream file("CurrencyExchangeRates.txt"); // Otworz plik z kursami walut
        if (!file.is_open())
            throw std::runtime_error("Nie udalo sie otworzyc pliku. Sprawdz sciezke do pliku.");

        std::string line;
        std::getline(file, line); // Pomin pierwszy wiersz komentarza
        std::getline(file, line); // Pomin wiersz z opisem formatu

        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string currencyCode, currencyName;
            double usdToCurrency, currencyToUsd;
            if (!(iss >> currencyCode >> currencyName >> usdToCurrency >> currencyToUsd))
                throw std::runtime_error("Niepoprawny format pliku.");

            currencies[currencyCode] = Currency(currencyCode, currencyName, usdToCurrency, currencyToUsd); // Dodaj walute do mapy
        }

        for (const auto& pair : currencies) {
            std::cout << pair.first << " (" << pair.second.name << ")" << std::endl; // Wyswietl dostepne waluty
        }

        BankAccount account;
        SpecialAccount specialAccount;
        std::string fromCurrency, toCurrency;
        double amount;
        bool fromCurrencyValid = false, toCurrencyValid = false, amountValid = false;

        // Petla do wprowadzania kodu waluty
        while (!fromCurrencyValid) {
            std::cout << "Wprowadz kod waluty, ktora posiadasz: ";
            std::getline(std::cin, fromCurrency); // Uzyj getline, aby odczytac cala linie
            fromCurrency = toUpperCase(fromCurrency);

            if (currencies.find(fromCurrency) == currencies.end()) {
                std::cout << "Kod waluty nie znaleziony. Sprobuj ponownie.\n";
            }
            else {
                fromCurrencyValid = true;
            }
        }

        // Petla do wprowadzania kwoty
        std::string inputAmount;
        while (!amountValid) {
            std::cout << "Wprowadz kwote, ktora posiadasz: ";
            std::getline(std::cin, inputAmount); // Uzyj getline, aby odczytac cala linie

            if (!isValidAmount(inputAmount, amount)) {
                std::cout << "Niepoprawna kwota. Uzywaj tylko cyfr i jednego znaku dziesietnego.\n";
            }
            else {
                amountValid = true;
            }
        }

        // Petla do wprowadzania kodu waluty docelowej
        while (!toCurrencyValid) {
            std::cout << "Wprowadz kod waluty, na ktora chcesz zamienic: ";
            std::getline(std::cin, toCurrency); // Uzyj getline, aby odczytac cala linie
            toCurrency = toUpperCase(toCurrency);

            if (currencies.find(toCurrency) == currencies.end()) {
                std::cout << "Kod waluty nie znaleziony. Sprobuj ponownie.\n";
            }
            else {
                toCurrencyValid = true;
            }
        }

        double convertedAmount = account.convert(amount, currencies[fromCurrency], currencies[toCurrency]);
        std::cout << amount << " " << fromCurrency << " to rownowaznosc " << convertedAmount << " " << toCurrency << "." << std::endl;

        displayBankExchange(account, amount, currencies[fromCurrency], currencies[toCurrency]); // Wyswietl szczegoly wymiany walut
        displaySpecialExchange(specialAccount, amount, currencies[fromCurrency], currencies[toCurrency]); // Wyswietl szczegoly wymiany walut dla specjalnego konta

    }
    catch (const std::exception& e) {
        std::cerr << "Blad: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
