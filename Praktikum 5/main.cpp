#include <iostream>
#include "CZufall.h"

int main() {

	int input = 0;

	std::cout << "\t 1- Test von wert" << std::endl;
	std::cout << "\t 2- Test von Methoden mit gleichem s" << std::endl;
	std::cout << "\t 3- Test von Methoden mit verschiedenen s" << std::endl;

	while (input != 99) {

		std::cin >> input;

		switch (input) {

			case 1: {

				std::cout << "Test von Wert mit a = 1 und b = 10:" << std::endl;

				int b = 10;
				int a = 1;

				std::cout << "[";
				for (int i = 0; i < 20; i++) {
					std::cout << rand() % (b + 1) + a << " ";	
				}
				std::cout << "]";

				break;
			}

			case 2: {

				int a = 3;
				int b = 7;
				int s = 0;

				CZufall z;

				std::cout << "Verteilung von 10000 Zahlen, von " << a << " bis " << b << std::endl;
				std::cout << "\t mit s = " << s << std::endl;

				//z.initialisiere(s);

				for (int j = 0; j < 4; j++) {
					std::cout << "Durchlauf: " << j+1 << std::endl;
					z.initialisiere(s);
					std::vector<int> res = z.test(a, b, 10000);

					for (int i = 0; i < res.size(); i++) {
						std::cout << "\t  " << a + i << ": " << res.at(i);
					}
					std::cout << std::endl;
				}
				break;
			}

			case 3: {

				int a = 3;
				int b = 7;
				
				CZufall z;

				std::cout << "Verteilung von 10000 Zahlen, von " << a << " bis " << b << std::endl;

				int s[4] = { 1,4,8,3 };

				for (int i = 0; i < 4; i++) {
					std::cout << "\t mit s = " << s[i] << std::endl;
					z.initialisiere(s[i]);
					std::vector<int> res = z.test(a, b, 10000);

					for (int j = 0; j < res.size(); j++) {
						std::cout << "\t  " << a + j << ": " << res.at(j);
					}
					std::cout << std::endl;
				}

				break;
			}

			case 4: {

				int a = 3;
				int b = 7;
				int s = time(NULL);

				CZufall z;

				std::cout << "Verteilung von 10000 Zahlen, von " << a << " bis " << b << std::endl;
				std::cout << "\t mit s = " << s << std::endl;

				//z.initialisiere(s);

				for (int j = 0; j < 4; j++) {
					std::cout << "Durchlauf: " << j + 1 << std::endl;
					z.initialisiere(s);
					std::vector<int> res = z.test(a, b, 10000);

					for (int i = 0; i < res.size(); i++) {
						std::cout << "\t  " << a + i << ": " << res.at(i);
					}
					std::cout << std::endl;
				}
				break;
			}
		}
	}
}