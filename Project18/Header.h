#pragma once
#ifndef HEADER_H
#define HEADER_H

#include <iostream>

class Punkt {
public:
    Punkt();
    Punkt(int x, int y);
    ~Punkt();
};

class Kolo : public Punkt {
public:
    Kolo();
    Kolo(int x, int y, int r);
    ~Kolo();
};

class Walec : public Kolo {
public:
    Walec();
    Walec(int x, int y, int r, int h);
    ~Walec();
};

class Kwadrat : public Punkt {
public:
    Kwadrat();
    Kwadrat(int x, int y, int sideLength);
    ~Kwadrat();
};

class Prostopadloscian : public Kwadrat {
public:
    Prostopadloscian();
    Prostopadloscian(int x, int y, int sideLength, int h);
    ~Prostopadloscian();
};

#endif // HEADER_H
