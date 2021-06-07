#include <iostream>
#include "CKomplex.h"

#include <fstream>

int main(){

	int input = 0;

	std::cout << "1- Test Addition zweier komplexer Zahlen" << std::endl;
	std::cout << "2- Test Multiplikation zweier komplexer Zahlen" << std::endl;
	std::cout << "3- Test Multiplikation komplexer Zahl mit double" << std::endl;
	std::cout << "4- Aufgabe 2 -> Test von ein und Ausgabe (nur werte >= 10)" << std::endl;
	std::cout << "5- maximale Abweichung" << std::endl;
	
	CKomplex komp1(2, 3);
	CKomplex komp2(4, 1);

	while (input != 99) {

		std::cin >> input;

		switch (input) {

			//Aufgabe 1

		case 1: {

			std::cout << "Addition zweier komplexer Zahlen:" << std::endl;

			std::cout << "\t (";
			print_komplex(komp1);
			std::cout << ") + (";
			print_komplex(komp2);
			std::cout << ") = ";

			CKomplex add = komp1 + komp2;

			print_komplex(add);

			std::cout << std::endl;

			break;
		}

		case 2: {

			std::cout << "Multiplikation zweier komplexer Zahlen:" << std::endl;

			std::cout << "\t (";
			print_komplex(komp1);
			std::cout << ") * (";
			print_komplex(komp2);
			std::cout << ") = ";

			CKomplex mult = komp1 * komp2;

			print_komplex(mult);

			std::cout << std::endl;

			break;
		}

		case 3: {

			std::cout << "Multiplikation komplexer Zahl mit double:" << std::endl;

			double zahl = 2;

			std::cout << "\t (";
			print_komplex(komp1);
			std::cout << ") * " << zahl << " = ";

			CKomplex mult = komp1 * zahl;

			print_komplex(mult);

			std::cout << std::endl;

			break;
		}

			//Aufgabe 2

		case 4: {

			std::vector<CKomplex> values = werte_einlesen("Daten_original.txt");
			werte_ausgeben("test1.txt", values, 10);
		}

		case 5: {
			
			//for (double epsilon = 0.001; epsilon < 2; epsilon *= 10) {}

				std::vector<CKomplex> values_orig = werte_einlesen("Daten_original.txt");
				std::vector<CKomplex> values_ft = fourier_tf(values_orig, false);

				werte_ausgeben("Daten_fourier.txt", values_ft, 1.0);

				std::vector<CKomplex> values_ft_invers = fourier_tf(values_ft, true);
				werte_ausgeben("Daten_fourier_invers.txt", values_ft_invers, 1.0);

				std::cout << "Maximale Abweichung bei epsilon = ^1: ";

				for (int i = 0; i < values_orig.size(); i++) {
			
				}
			}
		}
	}
	

	system("PAUSE");
	return 0;
}