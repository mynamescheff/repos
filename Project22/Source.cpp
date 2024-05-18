#include "header.h"

// Implementacja jednoargumentowego operatora w klasie: operator++
Przyklad& Przyklad::operator++() {
    ++wartosc;
    return *this;
}

// Implementacja dwuargumentowego operatora w klasie: operator+=
Przyklad& Przyklad::operator+=(const Przyklad& inny) {
    wartosc += inny.wartosc;
    return *this;
}

// Implementacja jednoargumentowego operatora globalnie: operator-
Przyklad operator-(const Przyklad& p) {
    return Przyklad(-p.wartosc);
}

// Implementacja dwuargumentowego operatora globalnie: operator+
Przyklad operator+(const Przyklad& p1, const Przyklad& p2) {
    return Przyklad(p1.wartosc + p2.wartosc);
}

// Implementacja operatora strumieniowego << jako funkcji globalnej
std::ostream& operator<<(std::ostream& os, const Przyklad& p) {
    os << p.wartosc;
    return os;
}
