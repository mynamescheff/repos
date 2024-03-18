#include <stdio.h>
#include <stdlib.h>

#define MAX_PRODUCTS 32

typedef struct {
    float cena;
    char opis[50];
} Produkt;

// funkcja znajdująca i drukująca poprawne konfiguracje w ramach budżetu
void znajdzPrawidloweKombinacje(float docelowaKwota, float aktualnaKwota, Produkt* produkty, int iloscProduktow, int* wybraneProdukty, int wybranaIlosc, FILE* plikWyjsciowy) {
    if (aktualnaKwota == docelowaKwota) {
        // drukowanie aktualnej kombinacji
        fprintf(plikWyjsciowy, "Kombinacja: ");

        for (int i = 0; i < wybranaIlosc; i++) {
            fprintf(plikWyjsciowy, "produkt %d (%s)", wybraneProdukty[i], produkty[wybraneProdukty[i] - 1].opis);

            if (i < wybranaIlosc - 1) {
                fprintf(plikWyjsciowy, ", ");
            }
        }

        fprintf(plikWyjsciowy, " - suma: %.2f\n", docelowaKwota);
        return;
    }

    if (aktualnaKwota > docelowaKwota || iloscProduktow <= 0) {
        return;
    }

    // zaliczenie aktualnego produktu do konfiguracji
    wybraneProdukty[wybranaIlosc] = iloscProduktow;
    znajdzPrawidloweKombinacje(docelowaKwota, aktualnaKwota + produkty[iloscProduktow - 1].cena, produkty, iloscProduktow - 1, wybraneProdukty, wybranaIlosc + 1, plikWyjsciowy);

    // wykluczenie aktualnego produktu z konfiguracji
    znajdzPrawidloweKombinacje(docelowaKwota, aktualnaKwota, produkty, iloscProduktow - 1, wybraneProdukty, wybranaIlosc, plikWyjsciowy);
}

int main() {
    FILE* plikWejsciowy;
    FILE* plikWyjsciowy;

    fopen_s(&plikWejsciowy, "wej.txt", "r");
    fopen_s(&plikWyjsciowy, "wyj.txt", "w");

    if (plikWejsciowy == NULL || plikWyjsciowy == NULL) {
        printf("Błąd otwierania pliku.\n");
        return 1;
    }

    float calaKwota;
    fscanf_s(plikWejsciowy, "%f", &calaKwota);

    printf("Budget from the first line: %.2f\n", calaKwota);

    Produkt produkty[MAX_PRODUCTS];
    int iloscProduktow = 0;

    // przeczytanie produktów z pliku
    while (fscanf_s(plikWejsciowy, "%f %[^\n]", &produkty[iloscProduktow].cena, produkty[iloscProduktow].opis, (unsigned)_countof(produkty[iloscProduktow].opis)) != EOF) {
        printf("Product %d: %s - %.2f\n", iloscProduktow + 1, produkty[iloscProduktow].cena, produkty[iloscProduktow].cena);
        iloscProduktow++;
    }

    printf("Read %d products from the file.\n", iloscProduktow);

    int wybraneProdukty[MAX_PRODUCTS];

    // Find and print valid configurations within the budget
    znajdzPrawidloweKombinacje(calaKwota, 0, produkty, iloscProduktow, wybraneProdukty, 0, plikWyjsciowy);

    printf("Valid configurations written to 'output.txt'.\n");

    fclose(plikWejsciowy);
    fclose(plikWyjsciowy);

    return 0;
}