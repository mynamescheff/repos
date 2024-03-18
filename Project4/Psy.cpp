#include "Psy.h"

// Konstruktor domyslny
Psy::Psy() : rasa("domyslna"), dlugoscZycia(10), koszt(1000) {
    std::cout << "Konstruktor domyslny zostal wywolany." << std::endl;
}

// Konstruktor parametryczny
Psy::Psy(std::string r, int dZ, int k) : rasa(r), dlugoscZycia(dZ), koszt(k) {
    std::cout << "Konstruktor parametryczny zostal wywolany." << std::endl;
}

// Destruktor
Psy::~Psy() {
    std::cout << "Destruktor zostal wywolany dla psa rasy: " << rasa << std::endl;
}

// Metoda do wyswietlania danych
void Psy::wyswietlDane() const {
    std::cout << "Rasa: " << rasa << ", Dlugosc zycia: " << dlugoscZycia << ", Koszt: " << koszt << std::endl;
}
