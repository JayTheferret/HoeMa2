#include "C_DGLSolver.h"

C_DGLSolver::C_DGLSolver(CMyVektor(*f_DGL_System)(CMyVektor y, double x))
{
	DGL_nterOrdnung = false;
}

C_DGLSolver::C_DGLSolver(double(*f_DGL_nterOrdnung)(CMyVektor y, double x))
{
	DGL_nterOrdnung = true;
}
