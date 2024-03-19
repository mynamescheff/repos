#include <iostream>
#include <string>

class Samochod {
private:
	std::string marka;
	int rokProdukcji;

public:
	Samochod() : marka("Nieznana"), rokProdukcji(0) {
		std::cout << "Utworzono samochod.\n";
	}

	Samochod(std::string m, int r) : marka(m), rokProdukcji(r) {
		std::cout << "Utworzono samochod marki " << marka << ", rok: " << rokProdukcji << ".\n";
	}

	~Samochod() {
		std::cout << "Zniszczono samochod marki " << marka << ".\n";
	}

	void wyswietlInformacje();
};