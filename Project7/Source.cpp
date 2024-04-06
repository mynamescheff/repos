#include <iostream>
#include <stdexcept>

using namespace std;

class Punkt {
public:
    float x, y;

    Punkt(float px, float py) : x(px), y(py) {}
};

class Kolo {
private:
    Punkt srodek;
    float promien;

public:
    // Konstruktor
    Kolo(Punkt psrodek, float ppromien) : srodek(psrodek), promien(ppromien) {
        if (promien <= 0) {
            throw std::invalid_argument("Promien musi byc wiekszy od 0.");
        }
    }

    // Konstruktor kopiujacy
    Kolo(const Kolo& k) : srodek(k.srodek), promien(k.promien) {
        cout << "Konstruktor kopiujacy wywolany!" << endl;
    }

    // Destruktor
    ~Kolo() {
        cout << "Destruktor Kola: Srodek(" << srodek.x << ", " << srodek.y << "), promien = " << promien << endl;
    }

    // Metoda akcesorowa do promienia
    float getPromien() const {
        return promien;
    }

    friend bool sprawdzCzyPunktNalezyDoKola(const Kolo& k, const Punkt& p);
};

bool sprawdzCzyPunktNalezyDoKola(const Kolo& k, const Punkt& p) {
    float odlegloscKwadrat = (p.x - k.srodek.x) * (p.x - k.srodek.x) + (p.y - k.srodek.y) * (p.y - k.srodek.y);
    return odlegloscKwadrat <= k.promien * k.promien;
}

int main() {
    try {
        Punkt srodek(0, 0);
        Kolo k(srodek, 10); // Tworzymy kolo o promieniu 10
        Kolo kopia(k); // Tworzymy kopie kola, wywoluje konstruktor kopiujacy

        // Sprawdzamy, czy punkt nalezy do kola
        Punkt punkt(1, 2); // Tworzymy punkt o wspólrzednych (1,2)
        if (sprawdzCzyPunktNalezyDoKola(k, punkt)) {
            cout << "Punkt nalezy do kola." << endl;
        }
        else {
            cout << "Punkt nie nalezy do kola." << endl;
        }

        // Sprawdzamy czy kopia jest prawidlowa (tutaj: sprawdzanie promienia)
        cout << "Promien kopii: " << kopia.getPromien() << endl;
    }
    catch (const std::exception& e) {
        cerr << "Wyjatek: " << e.what() << endl;
    }

    return 0;
}
