#ifndef CURRENCY_H
#define CURRENCY_H

#include <string>

class Currency {
public:
    std::string code; // Kod waluty, np. USD
    std::string name; // Pelna nazwa waluty, np. United States Dollar
    double toUSD;     // Kurs wymiany na USD
    double fromUSD;   // Kurs wymiany z USD

    Currency();
    Currency(std::string c, std::string n, double t, double f);
    Currency(const Currency& other);
    ~Currency();
};

#endif // CURRENCY_H
