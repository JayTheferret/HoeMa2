#include <iostream>
#include "CMyVektor.h"
#include "C_DGLSolver.h"

int main() {

	CMyVektor startw_1(2);

	startw_1.set_component(0, 0);
	startw_1.set_component(1, 1);

	C_DGLSolver solver1 = C_DGLSolver(f_DGL);

	solver1.euler(startw_1, 0, 2, 100);

	system("PAUSE");
	return 0;
}