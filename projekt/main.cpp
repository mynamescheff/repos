#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <algorithm>
#include "BankAccount.h"
#include "Currency.h"
#include "Service.h"


int main() {
    std::map<std::string, Currency> currencies; // Mapa przechowujaca dostepne waluty

    std::string input = "T";
    while (toUpperCase(input) == "T"){

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

                currencies[currencyCode] = Currency(currencyCode, currencyName, usdToCurrency,
                                                    currencyToUsd); // Dodaj walute do mapy
            }

            for (const auto &pair: currencies) {
                std::cout << pair.first << " (" << pair.second.name << ")" << std::endl; // Wyswietl dostepne waluty
            }

            BankAccount account;
            std::string fromCurrency;
            std::string toCurrency;
            double amount;
            bool fromCurrencyValid = false, toCurrencyValid = false, amountValid = false;

            // Petla do wprowadzania kodu waluty
            while (!fromCurrencyValid) {
                std::cout << "Wprowadz kod waluty, ktora posiadasz: \n";
                std::getline(std::cin, fromCurrency); // Uzyj getline, aby odczytac cala linie
                fromCurrency = toUpperCase(fromCurrency);
                fromCurrency = trim(fromCurrency);

                if (currencies.find(fromCurrency) == currencies.end()) {
                    std::cout << "Kod waluty nie znaleziony. Sprobuj ponownie.\n";
                } else {
                    fromCurrencyValid = true;
                }
            }

            // Petla do wprowadzania kwoty
            std::string inputAmount;
            while (!amountValid) {
                std::cout << "Wprowadz kwote, ktora posiadasz:\n ";
                std::getline(std::cin, inputAmount); // Uzyj getline, aby odczytac cala linie

                if (!isValidAmount(inputAmount, amount)) {
                    std::cout << "Niepoprawna kwota. Uzywaj tylko cyfr i jednego znaku dziesietnego.\n";
                } else {
                    amountValid = true;
                }
            }

            // Petla do wprowadzania kodu waluty docelowej
            while (!toCurrencyValid) {
                std::cout << "Wprowadz kod waluty, na ktora chcesz zamienic: \n";
                std::getline(std::cin, toCurrency); // Uzyj getline, aby odczytac cala linie
                toCurrency = toUpperCase(toCurrency);
                toCurrency = trim(toCurrency);

                if (currencies.find(toCurrency) == currencies.end()) {
                    std::cout << "Kod waluty nie znaleziony. Sprobuj ponownie.\n";
                } else {
                    toCurrencyValid = true;
                }
            }

            double convertedAmount = account.convert(amount, currencies[fromCurrency], currencies[toCurrency]);
            std::cout << amount << " " << fromCurrency << " to rownowaznosc " << convertedAmount << " " << toCurrency
                      << "." << std::endl;

            displayBankExchange(account, amount, currencies[fromCurrency],
                                currencies[toCurrency]); // Wyswietl szczegoly wymiany walut

            std::cout << "Czy chcesz dokonac kolejnej wymiany? (T/N)";
            std::cin >> input;

            std::cin.ignore();

        }
        catch (const std::exception &e) {
            std::cerr << "Blad: " << e.what() << std::endl;
            return 1;
        }
    }

    return 0;
}