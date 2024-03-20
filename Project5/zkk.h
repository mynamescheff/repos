#pragma once

class ZKonstruktoremKopiujacym {
public:
    int* wsk;

    ZKonstruktoremKopiujacym(int wartosc) : wsk(new int(wartosc)) {}

    ZKonstruktoremKopiujacym(const ZKonstruktoremKopiujacym& kopia) : wsk(new int(*(kopia.wsk))) {}

    ~ZKonstruktoremKopiujacym() {
        delete wsk;
    }
};
