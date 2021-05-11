#include "CMyMatrix.h"
#include <iostream>

CMyMatrix::CMyMatrix(int dimension_m, int dimension_n)
{
	matrix.resize(dimension_m);
	for (int i = 0; i < dimension_m; i++) {
		matrix[i].resize(dimension_n);
	}
	//matrix.resize(dimension_m); //zeilen = m
}

void CMyMatrix::set_component(int component_m, int component_n, double value)
{
	matrix[component_m][component_n] = value;
}

double CMyMatrix::get_component(int component_m, int component_n)
{
	return matrix[component_m][component_n];
}

int CMyMatrix::get_dimension_m()
{
	return matrix.size();
}

int CMyMatrix::get_dimension_n()
{
	return matrix[0].size();
}

void CMyMatrix::print_matrix(CMyMatrix matrix)
{
	for (int i = 0; i < matrix.get_dimension_m(); i++) {
		std::cout << "| ";
		for (int j = 0; j < matrix.get_dimension_n(); j++) {
			std::cout << matrix.get_component(i,j) << " " ;
		}
		std::cout << "|" << std::endl;
	}
}

CMyMatrix CMyMatrix::invers(CMyMatrix matrix)
{
	if (matrix.get_dimension_m() != 2 || matrix.get_dimension_n() != 2) {
		std::cout << "Keine 2X2 Matrix uebergeben!" << std::endl;
		exit(3);
	}

	CMyMatrix m_invers(matrix.get_dimension_m(), matrix.get_dimension_n()); //erstellt matrix mit Dimension von urpsrungsmatrix

	double a = matrix.get_component(0, 0);
	double b = matrix.get_component(0, 1);
	double c = matrix.get_component(1, 0);
	double d = matrix.get_component(1, 1);

	double calc = 1 / ((a*d) - (b*c)); //Zwischenspeicher für Rechnungsergebnis

	m_invers.set_component(0, 0, calc*d);
	m_invers.set_component(0, 1, calc*(-b));
	m_invers.set_component(1, 0, calc*(-c));
	m_invers.set_component(1, 1, calc*a);

	return m_invers;
}

CMyVektor operator*(CMyMatrix A, CMyVektor x)
{
	CMyVektor result(A.get_dimension_m()); //resultat ist Vektor mit Dimension = zeilen Matrix
	double temp = 0;

	for (int i = 0; i < A.get_dimension_m(); i++) { //pro zeile der Matrix
		for (int j = 0; j < A.get_dimension_n(); j++) { //jede Zahl durchgehen
			temp += A.get_component(i, j)*x.get_component(j); //Zahl in Matrix*Zahl im Vektor + nächste zahl
		}
		result.set_component(i, temp);
		temp = 0; // temp zuruecksetzen
	}

	return result;

	/*double a = A.get_component(0, 0);
	double b = A.get_component(0, 1);
	double c = A.get_component(1, 0);
	double d = A.get_component(1, 1);

	double e = x.get_component(0);
	double f = x.get_component(1);

	CMyVektor result(2);

	result.set_component(0, (a*e) + (b*f));
	result.set_component(1, (c*e) + (d*f));

	return result;*/
}

CMyMatrix jacobi(CMyVektor x, CMyVektor(*funktion)(CMyVektor x))
{
	double h = pow(10, -4);

	int funktion_d = funktion(x).get_dimension();
	int x_d = x.get_dimension();

	CMyMatrix jacobi_m(funktion_d, x_d); //matrix mit m = funktion ,n = vektor

	CMyVektor x_h = x; //Kopie von x erstellen

	for (int i = 0; i < funktion_d; i++) { //pro funktion in Vektor
		for (int j = 0; j < x_d; j++) { //für jedes x
			x_h = x; //x_h immer auf x zuruecksetzen
			x_h.set_component(j, x_h.get_component(j) + h); //aktuelles x in x_h +h

			jacobi_m.set_component(i, j, (funktion(x_h).get_component(i) - funktion(x).get_component(i)) / h); //einsetzen in funktion(en)-> nur interessantes ergebnis uebernehmen
			//(f(x+h)-f(x))/h
		}
	}
	return jacobi_m;
}

CMyVektor f_1(CMyVektor x)
{
	CMyVektor funktion(3);

	const long double e = 2.7182818284590452353602874713526625L; //e von math.h

	double x1 = x.get_component(0);
	double x2 = x.get_component(1);
	double x3 = x.get_component(2);
	double x4 = x.get_component(3);

	funktion.set_component(0, x1*x2*pow(e,x3));
	funktion.set_component(1, x2*x3*x4);
	funktion.set_component(2, x4);

	return funktion;
}

CMyVektor newton_verfahren(CMyVektor x, CMyVektor(*funktion)(CMyVektor x))
{
	//xn+1 = xn + delta_x_n
	CMyVektor x_n = x;
	int steps = 0;
	

	do {

		CMyMatrix jacobi_m = jacobi(x_n, funktion);
		CMyMatrix invers_m = jacobi_m.invers(jacobi_m);
		CMyVektor delta_x = -1*(invers_m*funktion(x_n)); //delta x = -(J(x_n)^-1*f(x_n))

		//CMyVektor x_n1 = ;

		std::cout << "Schritt " << steps << ":" << std::endl;
		std::cout << "        x = ( " << x_n.get_component(0) << "; " << x_n.get_component(1) << ")" << std::endl;
		std::cout << "        f(x) = ( " << funktion(x_n).get_component(0) << "; " << funktion(x_n).get_component(1) << ")" << std::endl;
		std::cout << "        f'(x) =" << std::endl;
		std::cout << "        ( " << jacobi_m.get_component(0,0) << "; " << jacobi_m.get_component(0,1) << std::endl;
		std::cout << "        " << jacobi_m.get_component(1,0) << "; " << jacobi_m.get_component(1,1) << " )" << std::endl;
		std::cout << "        (f'(x))^(-1) = " << std::endl;
		std::cout << "        ( " << invers_m.get_component(0, 0) << "; " << invers_m.get_component(0, 1) << std::endl;
		std::cout << "        " << invers_m.get_component(1, 0) << "; " << invers_m.get_component(1, 1) << " )" << std::endl;
		std::cout << "        dx = (" << delta_x.get_component(0) << "; " << delta_x.get_component(1) << " )" << std::endl;
		std::cout << "        ||f(x)|| = " << x_n.vector_length(funktion(x_n)) << std::endl << std::endl;

		x_n.set_component(0, x_n.get_component(0) + delta_x.get_component(0));
		x_n.set_component(1, x_n.get_component(1) + delta_x.get_component(1));

		steps += 1;
	} while (!(x_n.vector_length(funktion(x_n)) < pow(10,-5)) && steps < 50);

	if (steps != 50) {
		std::cout << "Ende wegen ||f(x)||<1e-5 bei " << std::endl;
	}

	std::cout << "        x = ( " << x_n.get_component(0) << "; " << x_n.get_component(1) << ")" << std::endl;
	std::cout << "        f(x) = ( " << funktion(x_n).get_component(0) << "; " << funktion(x_n).get_component(1) << ")" << std::endl;
	std::cout << "        ||f(x)|| = " << x_n.vector_length(funktion(x_n)) << std::endl;

	return x_n;
}

CMyVektor f_2(CMyVektor x_vec)
{
	CMyVektor result(2);
	double x = x_vec.get_component(0);
	double y = x_vec.get_component(1);

	result.set_component(0, ((x*x*x)*(y*y*y)) - 2 * y); //x^3*y^3-2y
	result.set_component(1, x - 2); //x-2

	return result;
}