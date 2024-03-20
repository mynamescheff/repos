#pragma once

class BezKonstruktoraKopiujacego {
public:
    int* wsk;

    BezKonstruktoraKopiujacego(int wartosc) : wsk(new int(wartosc)) {}

    BezKonstruktoraKopiujacego(const BezKonstruktoraKopiujacego& kopia) : wsk(new int(*(kopia.wsk))) {}

    ~BezKonstruktoraKopiujacego() {
        delete wsk;
    }
};
