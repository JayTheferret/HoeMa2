#pragma once

#include "CMyVektor.h"

class C_DGLSolver {
private:

	bool DGL_nterOrdnung = false;
	CMyVektor f_DGL_System(CMyVektor y, double x);
	double f_DGL_nterOrdnung(CMyVektor y, double x);

public:

	C_DGLSolver(CMyVektor(*f_DGL_System)(CMyVektor y, double x));
	C_DGLSolver(double(*f_DGL_nterOrdnung)(CMyVektor y, double x));

};
