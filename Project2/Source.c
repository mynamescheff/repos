// Funkcja do obliczania warto?ci wielomianu dla danej warto?ci x
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#ifdef _MSC_VER
#include <conio.h>
#endif
#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS

// Funkcja do obliczania warto?ci wielomianu dla danej warto?ci x
double oblicz_wartosc_wielomianu(double wspolczynniki[], int n, double x) {
    double wynik = 0.0;

    for (int i = 0; i <= n; i++) {
        wynik += wspolczynniki[i] * pow(x, i);
    }

    return wynik;
}

int main() {
    int n;
    double x;

    // Pobranie stopnia wielomianu n i warto?ci x z linii polece?
    printf("Podaj stopien wielomianu n: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Bledne dane. Podaj nieujemna liczbe calkowita.\n");
        return 1;
    }

    printf("Podaj wartosc x: ");
    if (scanf("%lf", &x) != 1) {
        printf("Bledne dane. Podaj poprawna wartosc x.\n");
        return 1;
    }

    // Dynamiczna alokacja pami?ci dla tablicy wspó?czynników wielomianu
    double* wspolczynniki = (double*)malloc((n + 1) * sizeof(double));
    if (wspolczynniki == NULL) {
        printf("Nie mozna przydzielic pamieci.\n");
        return 1;
    }

    // Wczytanie wspó?czynników wielomianu
    printf("Podaj wspolczynniki wielomianu (od a0 do an):\n");
    for (int i = 0; i <= n; i++) {
        printf("Podaj wspolczynnik a%d: ", i);
        if (scanf("%lf", &wspolczynniki[i]) != 1) {
            printf("Bledne dane. Podaj poprawny wspolczynnik.\n");
            free(wspolczynniki); // Zwolnienie pami?ci w przypadku b??du
            return 1;
        }
    }

    // Obliczenie warto?ci wielomianu dla podanej warto?ci x
    double wynik = oblicz_wartosc_wielomianu(wspolczynniki, n, x);

    // Wy?wietlenie wyniku
    printf("Wartosc wielomianu dla x=%.2f wynosi: %.2f\n", x, wynik);

    // Zwolnienie zaalokowanej pami?ci
    free(wspolczynniki);

    _getch();
}