#include "header.h"

int main() {
    Przyklad p1(10);
    Przyklad p2(20);
    Przyklad p3;

    // Testowanie jednoargumentowego operatora w klasie: operator++
    std::cout << "p1 przed inkrementacja: " << p1 << std::endl;
    ++p1;
    std::cout << "p1 po inkrementacji: " << p1 << std::endl;

    // Testowanie dwuargumentowego operatora w klasie: operator+=
    std::cout << "p2 przed dodaniem p1: " << p2 << std::endl;
    p2 += p1;
    std::cout << "p2 po dodaniu p1: " << p2 << std::endl;

    // Testowanie jednoargumentowego operatora globalnie: operator-
    std::cout << "Negacja p1: " << -p1 << std::endl;

    // Testowanie dwuargumentowego operatora globalnie: operator+
    p3 = p1 + p2;
    std::cout << "p1 + p2: " << p3 << std::endl;

    return 0;
}
