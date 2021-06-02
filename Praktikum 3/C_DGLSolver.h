#pragma once

#include "CMyVektor.h"
#include <iostream>

class C_DGLSolver {
private:

	CMyVektor(*f_DGL_System)(CMyVektor y, double x);
	double(*f_DGL_nterOrdnung)(CMyVektor y, double x);

	bool DGL_nterOrdnung = false;
	//CMyVektor f_DGL_System(CMyVektor y, double x);
	//double f_DGL_nterOrdnung(CMyVektor y, double x);

	CMyVektor ableitungen(CMyVektor y, double x);

public:

	C_DGLSolver(CMyVektor(*f_DGL_System)(CMyVektor y, double x));
	C_DGLSolver(double(*f_DGL_nterOrdnung)(CMyVektor y, double x));

	CMyVektor euler(CMyVektor y_start, double x_start, double x_end, double steps);
	CMyVektor heun(CMyVektor y_start, double x_start, double x_end, double steps);

	CMyVektor euler_oa(CMyVektor y_start, double x_start, double x_end, double steps); //statt extra funktion -> boolean für ausgabe
	CMyVektor heun_oa(CMyVektor y_start, double x_start, double x_end, double steps);

};

CMyVektor f_DGL(CMyVektor y, double x);
double f_DGL_3terO(CMyVektor y,double x);

//void Abweichung(CMyVektor y_start, double x_start,double x_end);