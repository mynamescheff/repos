#include "header.h"

int main() {
    // Testowanie szablonu funkcji max
    int a = 10, b = 20, c = 15;
    double x = 10.5, y = 20.3, z = 15.8;

    std::cout << "Najwieksza z dwoch liczb (int): " << max(a, b) << std::endl;
    std::cout << "Najwieksza z dwoch liczb (double): " << max(x, y) << std::endl;
    std::cout << "Najwieksza z trzech liczb (int): " << max(a, b, c) << std::endl;
    std::cout << "Najwieksza z trzech liczb (double): " << max(x, y, z) << std::endl;

    // Testowanie szablonu klasy Walec
    Walec<int> walec1(3, 5);
    Walec<double> walec2(4.5, 7.2);

    std::cout << "Pole powierzchni walca (int -> double): " << walec1.pole<double>() << std::endl;
    std::cout << "Pole powierzchni walca (double -> float): " << walec2.pole<float>() << std::endl;

    return 0;
}
