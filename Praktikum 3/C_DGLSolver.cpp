#include "C_DGLSolver.h"


CMyVektor C_DGLSolver::ableitungen(CMyVektor y, double x)
{
	int y_d = y.get_dimension();

	CMyVektor result(y_d);
	if (DGL_nterOrdnung == false) { //DGL-System ?bergeben -> an der Stelle (y;x) auswerten
		return f_DGL_System(y, x);
	}

	//h?here Ordnung -> in DGL transformieren und dann rechte Seite ausgeben
	CMyVektor DGL(y_d);

	//y'0=(y)'=y'=y1

	for (int i = 0; i < y_d-1; i++) {
			DGL.set_component(i, y.get_component(i + 1));
	}
	DGL.set_component(y.get_dimension()-1, f_DGL_nterOrdnung(y, x));

	return DGL;
}

C_DGLSolver::C_DGLSolver(CMyVektor(*_f_DGL_System)(CMyVektor y, double x))
{
	DGL_nterOrdnung = false;
	f_DGL_System = _f_DGL_System;
}

C_DGLSolver::C_DGLSolver(double(*_f_DGL_nterOrdnung)(CMyVektor y, double x))
{
	DGL_nterOrdnung = true;
	f_DGL_nterOrdnung = _f_DGL_nterOrdnung;
}

CMyVektor C_DGLSolver::euler(CMyVektor y_start, double x_start, double x_end, double steps)
{
	//y(x1) = y(x0)+h*f(x0,yo)
	//y' = f(x,y)
	//x1 = x0 + h
	double h = (x_end-x_start)/steps;

	//CMyVektor y(y_start.get_dimension());
	CMyVektor y = y_start;
	CMyVektor y_strich(y_start.get_dimension());

	for (int i = 0; i < steps; i++) {
		y_strich = ableitungen(y, x_start);

		std::cout	<< "Schritt " << i << ":" << std::endl
					<< "     x = " << x_start << std::endl
					<< "     y = ";
		y.print_vector(y);
		std::cout	<< "     y' = ";
		y_strich.print_vector(y_strich);
		std::cout << std::endl;

		y = y + h * y_strich;
		x_start += h;
		//y_old = y;
	}

	std::cout << "Ende bei" << std::endl
		<< "     x = " << x_start << std::endl
		<< "     y = ";
	y.print_vector(y);

	return y;
}

CMyVektor C_DGLSolver::heun(CMyVektor y_start, double x_start, double x_end, double steps)
{
	//testschritt gehen -> y1 = y(x0)+h*f(x0,yo)
	// y'mittel = 1/2(f(x0,y(x0))+f(x1,y1))
	//y(x1) = y(x0)+h* y'mittel

	double h = (x_end - x_start) / steps;

	CMyVektor y = y_start;
	CMyVektor y_strich(y_start.get_dimension());

	CMyVektor y_test = y;
	CMyVektor y_test_strich = y_strich;
	CMyVektor y_strich_mittel = y_strich;

	for (int i = 0; i < steps; i++) {

		y_strich = ableitungen(y, x_start);

		std::cout	<< "Schritt " << i << ":" << std::endl
					<< "     x = " << x_start << std::endl
					<< "     y = ";
		y_start.print_vector(y);
		std::cout	<< "     y'_orig = ";;
		y_strich.print_vector(y_strich);
		std::cout	<< std::endl;

		y_test = y + h * y_strich;

		std::cout	<< "     y_Test = ";
		y_test.print_vector(y_test);

		x_start += h;

		y_test_strich = ableitungen(y_test, x_start);

		std::cout	<< "     y'_Test = ";
		y_test_strich.print_vector(y_test_strich);

		y_strich_mittel = 0.5*(y_strich + y_test_strich); //1/2*(f(x0,y(x0))+f(x1,y1))

		std::cout	<< std::endl
					<< "     y'_Mittel = ";
		y_strich_mittel.print_vector(y_strich_mittel);
		std::cout	<< std::endl;

		y = y + h * y_strich_mittel;
	}

	std::cout << "Ende bei" << std::endl
		<< "     x = " << x_start << std::endl
		<< "     y = ";
	y.print_vector(y);

	return y;
}

CMyVektor C_DGLSolver::euler_oa(CMyVektor y_start, double x_start, double x_end, double steps)
{
	double h = (x_end - x_start) / steps;

	CMyVektor y = y_start;
	CMyVektor y_strich(y_start.get_dimension());

	for (int i = 0; i < steps; i++) {
		y_strich = ableitungen(y, x_start);

		y = y + h * y_strich;
		x_start += h;
	}

	return y;
}

CMyVektor C_DGLSolver::heun_oa(CMyVektor y_start, double x_start, double x_end, double steps)
{
	double h = (x_end - x_start) / steps;

	CMyVektor y = y_start;
	CMyVektor y_strich(y_start.get_dimension());

	CMyVektor y_test = y;
	CMyVektor y_test_strich = y_strich;
	CMyVektor y_strich_mittel = y_strich;

	for (int i = 0; i < steps; i++) {

		y_strich = ableitungen(y, x_start);
		y_test = y + h * y_strich;
		x_start += h;
		y_test_strich = ableitungen(y_test, x_start);
		y_strich_mittel = 0.5*(y_strich + y_test_strich); //1/2*(f(x0,y(x0))+f(x1,y1))
		y = y + h * y_strich_mittel;
	}
	return y;
}

CMyVektor f_DGL(CMyVektor y, double x)
{
	CMyVektor result(2);

	double y1 = y.get_component(0);
	double y2 = y.get_component(1);

	result.set_component(0, (2 * y2) - (x * y1));
	result.set_component(1, (y1*y2) - (2 * (x*x*x)));

	return result;
}

double f_DGL_3terO(CMyVektor y, double x)
{
	double y1 = y.get_component(0); //y
	double y2 = y.get_component(1); //y'
	double y3 = y.get_component(2); //y''

	return (2*x*y2*y3)+(2*(y1*y1)*y2); //2*x*y'*y''+2*y^2*y'
}
