#include <iostream>
#include <string>
#include "Samochod.h"



	int main() {
		Samochod samochod1;
		samochod1.wyswietlInformacje();

		Samochod samochod2("Toyota", 2005);
		samochod2.wyswietlInformacje();

		return 0;
	}