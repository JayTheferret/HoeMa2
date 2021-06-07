#include <iostream>
#include "CKomplex.h"

int main(){

	int input;

	std::cout << "1- Test Addition zweier komplexer Zahlen" << std::endl;
	std::cout << "2- Test Multiplikation zweier komplexer Zahlen" << std::endl;
	std::cout << "3- Test Multiplikation komplexer Zahl mit double" << std::endl;
	std::cin >> input;

	CKomplex komp1(2, 3);
	CKomplex komp2(4, 1);

	switch (input) {
		case 1: {
			
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

			double zahl = 2;

			std::cout << "\t (";
			print_komplex(komp1);
			std::cout << ") * " << zahl << " = ";

			CKomplex mult = komp1 * zahl;

			print_komplex(mult);

			std::cout << std::endl;

			break;
		}
	}

	

}