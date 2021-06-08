#include <iostream>
#include "CKomplex.h"

#include <fstream>

int main(){

	int input = 0;
	std::cout << "\t --------------------------------------------------------------" << std::endl;
	std::cout << "\t | 1- Test Addition zweier komplexer Zahlen                   |" << std::endl;
	std::cout << "\t | 2- Test Multiplikation zweier komplexer Zahlen             |" << std::endl;
	std::cout << "\t | 3- Test Multiplikation komplexer Zahl mit double           |" << std::endl;
	std::cout << "\t | 4- Aufgabe 2 -> Test von ein und Ausgabe (nur werte >= 10) |" << std::endl;
	std::cout << "\t | 5- Ausgabe der maximalen Abweichung                        |" << std::endl;
	std::cout << "\t | 6- Test Ausgabe von eingelesenem Vektor                    |" << std::endl;
	std::cout << "\t | 7- Praktikumstest A1                                       |" << std::endl;
	std::cout << "\t --------------------------------------------------------------" << std::endl;
	std::cout << std::endl;
	
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

			break;
		}

		case 5: {

			std::vector<CKomplex> values_orig = werte_einlesen("Daten_original.txt");
			std::vector<CKomplex> values_ft = fourier_tf(values_orig, false);

			werte_ausgeben("FT.txt", values_ft,-1.0);
			std::vector<CKomplex> values_ft_invers = fourier_tf(werte_einlesen("FT.txt"), true);
			//werte_ausgeben("FTinvers.txt", values_ft_invers, -1.0);
			std::cout << "Maximale Abweichung bei Epsilon = -1.0: " << difference(values_orig, values_ft_invers) << std::endl;

			for (double epsilon = 0.001; epsilon < 2; epsilon *= 10) {

				werte_ausgeben("FT.txt", values_ft, epsilon);
				std::vector<CKomplex> values_ft_invers = fourier_tf(werte_einlesen("FT.txt"), true);
				//werte_ausgeben("FTinvers.txt", values_ft_invers, epsilon);
				std::cout << "Maximale Abweichung bei Epsilon = " << epsilon << ": " << difference(values_orig, values_ft_invers) << std::endl;
			}
				break;
			}

		case 6: {
			std::vector<CKomplex> values_orig = werte_einlesen("Daten_original.txt");
			for (int i = 0; i < values_orig.size(); i++) {
				print_komplex(values_orig[i]);
				std::cout << std::endl;
			}
			break;
		}

		case 7: {
			
			std::cout << "a)" << std::endl;

			std::vector<CKomplex> a1;
			a1.push_back(CKomplex (3, 1));
			a1.push_back(CKomplex(-3, -3));
			a1.push_back(CKomplex(1, -2));
			a1.push_back(CKomplex(0, 2));
		
			a1 = fourier_tf(a1, false);

			for (int i = 0; i < a1.size(); i++) {
				print_komplex(a1[i]);
				std::cout << std::endl;
			}

			std::cout << std::endl;

			std::cout << "b)" << std::endl;

			std::vector<CKomplex> b1;
			b1.push_back(CKomplex(2, 0));
			b1.push_back(CKomplex(0, 0));
			b1.push_back(CKomplex(1, 0));
			b1.push_back(CKomplex(3, 0));
			b1.push_back(CKomplex(-3, 0));
			b1.push_back(CKomplex(0, 0));

			b1 = fourier_tf(b1, false);

			print_komplex(b1[2]);
			std::cout << std::endl;

			std::cout << std::endl;

			std::cout << "c)" << std::endl;

			std::vector<CKomplex> c1;
			c1.push_back(CKomplex(1, 0));
			c1.push_back(CKomplex(2, 2));
			c1.push_back(CKomplex(-1, -1));

			c1 = fourier_tf(c1, true);
			print_komplex(c1[2]);
			std::cout << std::endl;






			break;
		}

		}
	}

	system("PAUSE");
	return 0;
}