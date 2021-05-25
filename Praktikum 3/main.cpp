#include <iostream>
#include "CMyVektor.h"
#include "C_DGLSolver.h"

int main() {

	int input;

	std::cout	<< "1 - DGL-System with Euler-Method" << std::endl
				<< "2 - DGL-System with Heun-Method" << std::endl
				<< "3 - Difference from exact Solution" << std::endl;
	std::cin >> input;

	// DGL-System

	CMyVektor startw_1(2);

	startw_1.set_component(0, 0);
	startw_1.set_component(1, 1);

	C_DGLSolver solver1(f_DGL);

	switch (input) {
		case 1: {
			std::cout << "Euler-Verfahren:" << std::endl
				<< "\t DGL-System: \t y1' = 2*y2-x*y1 " << std::endl
				<< "\t \t \t y2' = y1*y2 -2*x^3" << std::endl
				<< "\t Startwerte: \t y1(0) = 0, y2(0) = 1" << std::endl << std::endl;
			system("PAUSE");

			//Beispiel Euler-Verfahren
			solver1.euler(startw_1, 0, 2, 100);

			break;
		}

				//----------------------------------------------

		case 2: {
			std::cout << "Heun-Verfahren:" << std::endl
				<< "\t DGL-System: \t y1' = 2*y2-x*y1 " << std::endl
				<< "\t \t \t y2' = y1*y2 -2*x^3" << std::endl
				<< "\t Startwerte: \t y1(0)= 0, y2(0) = 1" << std::endl << std::endl;
			system("PAUSE");

			//Beispiel Heun-Verfahren
			solver1.heun(startw_1, 0, 2, 100);

			break;
		}

				//----------------------------------------------	
				//Abweichung

		case 3: {
			std::cout << "Abweichung:" << std::endl
				<< "\t DGL dritter Ordnung: \t y''' = 2*x*y'*y''+2*y^2*y' " << std::endl
				<< "\t Anfangswerte: \t y(1) = 1, y'(1) = -1, y''(1) = 2" << std::endl << std::endl;
			system("PAUSE");

			CMyVektor y_start(3);

			y_start.set_component(0, 1);
			y_start.set_component(1, -1);
			y_start.set_component(2, 2);

			C_DGLSolver solver(f_DGL_3terO);

			for (int i = 10; i < 100000; i *= 10) {
				std::cout	<< "Abweichung bei Euler bei " << i << " Schritten: " << solver.euler_oa(y_start, 1, 2, i)[0] - 0.5 << std::endl
							<< "Abweichung bei Heun bei " << i << " Schritten: " << solver.heun_oa(y_start, 1, 2, i)[0] - 0.5 << std::endl;

				//y(2) = 0.5 (1/x)
			}
			break;
		}
	}

	system("PAUSE");
	return 0;
}