#ifndef HEADER_H
#define HEADER_H
#define _USE_MATH_DEFINES
#include <math.h>

#include <iostream>
#include <cmath>

// Szablon funkcji max
template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

// Szablon funkcji max dla trzech argumentow
template <typename T>
T max(T a, T b, T c) {
    return max(max(a, b), c);
}

// Szablon klasy Walec
template <typename T>
class Walec {
    T radius;
    T height;
public:
    Walec(T r, T h);
    template <typename U>
    U pole() const;
};

// Implementacja metod szablonu klasy Walec
template <typename T>
Walec<T>::Walec(T r, T h) : radius(r), height(h) {}

template <typename T>
template <typename U>
U Walec<T>::pole() const {
    return static_cast<U>(2 * M_PI * radius * (radius + height));
}

#endif // HEADER_H