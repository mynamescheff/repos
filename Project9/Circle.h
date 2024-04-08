#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H

class Punkt {
public:
    Punkt(double x = 0.0, double y = 0.0);
    ~Punkt();
    double getX() const;
    double getY() const;

private:
    double x;
    double y;
};

class Okrag {
public:
    Okrag(double x = 0.0, double y = 0.0, double promien = 1.0);
    ~Okrag();
    bool zawieraPunkt(const Punkt& punkt) const;
    friend bool sprawdzPunktWOkregu(const Okrag& okrag, const Punkt& punkt);

private:
    Punkt srodek;
    double promien;
};

#endif
