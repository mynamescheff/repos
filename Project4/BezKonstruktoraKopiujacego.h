#pragma once
#ifndef BEZKONSTRUKTORAKOPIUJACEGO_H
#define BEZKONSTRUKTORAKOPIUJACEGO_H

class BezKonstruktoraKopiujacego {
public:
    int* wsk;

    // Konstruktor
    BezKonstruktoraKopiujacego(int wartosc) : wsk(new int(wartosc)) {}

    // Destruktor
    ~BezKonstruktoraKopiujacego() { delete wsk; }
};

#endif
