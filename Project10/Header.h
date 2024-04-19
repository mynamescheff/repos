#pragma once
#ifndef HEADER_H
#define HEADER_H

#include <iostream>

class PrzykladowaKlasa {
    int wartosc;
public:
    PrzykladowaKlasa(int w);
    PrzykladowaKlasa(const PrzykladowaKlasa& pk);
    friend void pokazWartoscIAdres(const PrzykladowaKlasa& x);
};

void pokazWartoscIAdres(const PrzykladowaKlasa& x);

#endif
