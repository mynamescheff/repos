#pragma once
#ifndef BEZKONSTRUKTORAKOPIUJACEGO_H
#define BEZKONSTRUKTORAKOPIUJACEGO_H

class BezKonstruktoraKopiujacego {
public:
    int* wsk;

    BezKonstruktoraKopiujacego(int wartosc) {
        wsk = new int(wartosc);
    }

    ~BezKonstruktoraKopiujacego() {
        delete wsk;
    }
};

#endif
