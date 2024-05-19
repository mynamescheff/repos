#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <stdexcept>
#include <limits>

// Funkcja dzielenia z obsluga wyjatku dzielenia przez zero
double dzielenie(double a, double b);

// Funkcja modulo z obsluga wyjatku, gdy zmienne sa rowne lub swoimi wielokrotnosciami
int modulo(int a, int b);

// Funkcja do bezpiecznego wczytywania liczby zmiennoprzecinkowej
double wczytajLiczbeDouble();

// Funkcja do bezpiecznego wczytywania liczby calkowitej
int wczytajLiczbeInt();

#endif // HEADER_H
