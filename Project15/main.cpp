#include "Header.h"
#include <iostream>

void A::methodA()
{
    std::cout << "Start method A\n";
    publiczny = 1;
    prywatny = 2;
    chroniony = 3;
    std::cout << "End method A\n";
}

void B::methodB()
{
    std::cout << "Start method B\n";
    publiczny = 1;  // Otrzymuje dostep, pomimo ze jest prywatnie dziedziczony, poniewaz jest wewnatrz klasy B
    prywatny = 2;   // Dostepny wewnatrz metody klasy B
    chroniony = 3;  // Dostepny wewnatrz metody klasy B
    publicznyB = 4;
    prywatnyB = 5;
    chronionyB = 6;
    std::cout << "End method B\n";
}

void C::methodC()
{
    std::cout << "Start method C\n";
    publiczny = 1;  // Dostep do dziedziczonego prywatnie czlonka A
    prywatny = 2;   // Nie bedzie dostepny, zwroci blad kompilacji
    chroniony = 3;  // Dostep do dziedziczonego prywatnie czlonka A
    publicznyB = 4; // Dostep do dziedziczonego prywatnie czlonka B
    prywatnyB = 5;  // Nie bedzie dostepny, zwroci blad kompilacji
    chronionyB = 6; // Dostep do dziedziczonego prywatnie czlonka B
    publicznyC = 7;
    prywatnyC = 8;
    chronionyC = 9;
    std::cout << "End method C\n";
}

int main() {
    A a;
    B b;
    C c;
    a.methodA();
    b.methodB();
    c.methodC();

    // Przykladowe uzycie i komentarze dotyczace dostepu
    // Komentarze zakladaja, ze odpowiednie czlonki sa publiczne tam, gdzie mozna
    int x;
    x = a.publiczny; // Poprawny dostep do publicznego czlonka klasy A
    // x = b.publiczny; // Blad, publicznyB jest dostepny jako publicznyB
    // x = c.publiczny; // Blad, publicznyC jest dostepny jako publicznyC

    return 0;
}
