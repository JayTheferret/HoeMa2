#include <iostream>
#include "CMyVektor.h"
#include "C_DGLSolver.h"

int main() {
	// DGL-System

	//Beispiel Euler-Verfahren

	/*CMyVektor startw_1(2);

	startw_1.set_component(0, 0);
	startw_1.set_component(1, 1);

	C_DGLSolver solver1 = C_DGLSolver(f_DGL);

	solver1.euler(startw_1, 0, 2, 100);*/

	//----------------------------------------------

	//Beispiel Heun-Verfahren

	/*CMyVektor startw_1(2);

	startw_1.set_component(0, 0);
	startw_1.set_component(1, 1);

	C_DGLSolver solver1(f_DGL);

	solver1.heun(startw_1, 0, 2, 100);*/

	//----------------------------------------------
	//----------------------------------------------

	//Abweichung
	CMyVektor y_start(3);

	y_start.set_component(0, 1);
	y_start.set_component(1, -1);
	y_start.set_component(2, 2);

	//double exact_result = 0.5;
	C_DGLSolver solver(f_DGL_3terO);
	//solver.euler_oa(y_start, 0, 2, 10).print_vector(solver.euler_oa(y_start, 1, 2, 10));

	for (int i = 10; i < 100000; i *= 10) {
		std::cout	<< "Abweichung bei Euler bei " << i << " Schritten: " << solver.euler_oa(y_start, 1, 2, i)[0] - 0.5 << std::endl
					<< "Abweichung bei Heun bei "  << i << " Schritten: " << solver.heun_oa(y_start, 1, 2, i)[0] - 0.5 << std::endl;

		//y(2) = 0.5 (1/x)
	}

	system("PAUSE");
	return 0;
}