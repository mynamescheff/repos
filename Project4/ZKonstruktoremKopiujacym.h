#pragma once
#ifndef ZKONSTRUKTOREMKOPIUJACYM_H
#define ZKONSTRUKTOREMKOPIUJACYM_H

class ZKonstruktoremKopiujacym {
public:
    int* wsk;

    // Konstruktor
    ZKonstruktoremKopiujacym(int wartosc) : wsk(new int(wartosc)) {}

    // Konstruktor kopiujacy
    ZKonstruktoremKopiujacym(const ZKonstruktoremKopiujacym& z) : wsk(new int(*z.wsk)) {}

    // Destruktor
    ~ZKonstruktoremKopiujacym() { delete wsk; }
};

#endif
