#ifndef PSY_H
#define PSY_H

#include <iostream>
#include <string>

class Psy {
private:
    std::string rasa;
    int dlugoscZycia;
    int koszt;

public:
    // Konstruktor domyslny
    Psy();

    // Konstruktor parametryczny
    Psy(std::string rasa, int dlugoscZycia, int koszt);

    // Destruktor
    ~Psy();

    // Metody do wyswietlania danych
    void wyswietlDane() const;
};

#endif
