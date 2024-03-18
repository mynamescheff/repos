#include <iostream>
#include "bkk.h"
#include "zkk.h"

int main() {
    BezKonstruktoraKopiujacego obj1(10);
    BezKonstruktoraKopiujacego obj2 = obj1;

    std::cout << "Bez konstruktora kopiujacego:" << std::endl;
    std::cout << "Adres obj1: " << obj1.wsk << ", wartosc: " << *(obj1.wsk) << std::endl;
    std::cout << "Adres obj2: " << obj2.wsk << ", wartosc: " << *(obj2.wsk) << std::endl;

    ZKonstruktoremKopiujacym obj3(20);
    ZKonstruktoremKopiujacym obj4 = obj3;

    std::cout << "\nZ konstruktorem kopiujacym:" << std::endl;
    std::cout << "Adres obj3: " << obj3.wsk << ", wartosc: " << *(obj3.wsk) << std::endl;
    std::cout << "Adres obj4: " << obj4.wsk << ", wartosc: " << *(obj4.wsk) << std::endl;

    return 0;
}
