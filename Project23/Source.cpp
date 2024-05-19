#include "header.h"

// Implementacja funkcji dzielenia z obsluga wyjatku dzielenia przez zero
double dzielenie(double a, double b) {
    if (b == 0) {
        throw std::invalid_argument("Blad: Dzielenie przez zero!");
    }
    return a / b;
}

// Implementacja funkcji modulo z obsluga wyjatku, gdy zmienne sa rowne lub swoimi wielokrotnosciami
int modulo(int a, int b) {
    if (a == b || a % b == 0 || b % a == 0) {
        throw std::invalid_argument("Blad: Zmienne sa rowne lub swoimi wielokrotnosciami!");
    }
    return a % b;
}

// Funkcja do bezpiecznego wczytywania liczby zmiennoprzecinkowej
double wczytajLiczbeDouble() {
    double liczba;
    while (true) {
        std::cin >> liczba;
        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the invalid input
            std::cerr << "Blad: Wprowadzono nieprawidlowa liczbe. Sprobuj ponownie: ";
        }
        else {
            break;
        }
    }
    return liczba;
}

// Funkcja do bezpiecznego wczytywania liczby calkowitej
int wczytajLiczbeInt() {
    int liczba;
    while (true) {
        std::cin >> liczba;
        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the invalid input
            std::cerr << "Blad: Wprowadzono nieprawidlowa liczbe. Sprobuj ponownie: ";
        }
        else {
            break;
        }
    }
    return liczba;
}
