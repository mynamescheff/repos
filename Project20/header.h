#pragma once
#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <cmath>

class Obiekt {
public:
    virtual double pole() const = 0;  // Czyscie wirtualna funkcja
    virtual ~Obiekt() {
        std::cout << "wirtualny destruktor" << std::endl;
    }
};

class Kolo : public Obiekt {
    double radius;
public:
    Kolo(double r);
    double pole() const override;
    ~Kolo();
};

class Kwadrat : public Obiekt {
    double side;
public:
    Kwadrat(double s);
    double pole() const override;
    ~Kwadrat();
};

class Walec : public Obiekt {
    double radius, height;
public:
    Walec(double r, double h);
    double pole() const override;
    ~Walec();
};

class Szescian : public Obiekt {
    double side;
public:
    Szescian(double s);
    double pole() const override;
    ~Szescian();
};

void oblicz(const Obiekt* obj);

#endif // HEADER_H
