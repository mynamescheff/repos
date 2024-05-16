#include "header.h"

int main() {
    Kolo kolo1(3);
    Kwadrat kwadrat1(5);
    Walec walec1(11, 10);
    Szescian szescian1(10);

    Obiekt* wsk = &kolo1;
    std::cout << "Pole kola obliczone przez metode pole: " << wsk->pole() << std::endl;
    oblicz(wsk);
    std::cout << std::endl;

    wsk = &kwadrat1;
    std::cout << "Pole kwadratu obliczone przez metode pole: " << wsk->pole() << std::endl;
    oblicz(wsk);
    std::cout << std::endl;

    wsk = &walec1;
    std::cout << "Pole walca obliczone przez metode pole: " << wsk->pole() << std::endl;
    oblicz(wsk);
    std::cout << std::endl;

    wsk = &szescian1;
    std::cout << "Pole szescianu obliczone przez metode pole: " << wsk->pole() << std::endl;
    oblicz(wsk);
    std::cout << std::endl;

    return 0;
}
