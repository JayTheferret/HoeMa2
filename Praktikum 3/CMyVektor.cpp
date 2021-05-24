#include "CMyVektor.h"
#include <iostream>

CMyVektor::CMyVektor(int dimension) {
	vector.resize(dimension); //vector mit platz fuer "dimension" viele elemente
}

int CMyVektor::get_dimension() { //methode fuer dimension... dasselbe wie size
	return vector.size();
}

void CMyVektor::set_component(int component, double value)
{
	vector[component] = value;
}

double CMyVektor::get_component(int component)
{
	return vector[component];
}

double CMyVektor::vector_length(CMyVektor vector)
{
	double length = 0;
	for (int i = 0; i < vector.get_dimension(); i++) {
		length += vector.get_component(i) * vector.get_component(i);
	}

	length = sqrt(length);

	return length;
}

void CMyVektor::print_vector(CMyVektor vector)
{
	std::cout << "(";

	for (int i = 0; i < vector.get_dimension() - 1; i++) {
		std::cout << vector.get_component(i) << ",";
	}

	std::cout << vector.get_component(vector.get_dimension() - 1);
	std::cout << ")" << std::endl;
}

CMyVektor operator+(CMyVektor a, CMyVektor b)
{
	CMyVektor c(a.get_dimension());

	if (a.get_dimension() == b.get_dimension()) {

		for (int i = 0; i < a.get_dimension(); i++) {
			double ab = a.get_component(i) + b.get_component(i);
			c.set_component(i, ab);
		}
	}

	else {
		std::cout << "Error: Dimensions of Vectors are not equal." << std::endl;
	}

	return c;
}

CMyVektor operator*(double lambda, CMyVektor a)
{
	CMyVektor c(a.get_dimension());

	for (int i = 0; i < a.get_dimension(); i++) {
		double la = a.get_component(i)*lambda;
		c.set_component(i, la);
	}
	return c;
}

double gvx(CMyVektor x)
{
	double x1 = x.get_component(0);
	double x2 = x.get_component(1);
	double x3 = x.get_component(2);

	//pow(base,exp)
	return (-(2 * pow((x1), 2) - (2 * (x1*x2)) + pow(x2, 2) + pow(x3, 2) - (2 * x1) - (4 * x3)));

	//mult schneller als pow -> pow(2,2) = 2*2
}

double fvx(CMyVektor x)
{
	double x1 = x.get_component(0);
	double y = x.get_component(1);

	//pow(base,exp)

	return sin(x1*y) + sin(x1) + cos(y);
}

CMyVektor gradient(CMyVektor x, double(*funktion)(CMyVektor x), double h)
{
	CMyVektor grad(x.get_dimension());

	//double h = pow(10, -8);

	for (int i = 0; i < x.get_dimension(); i++) {

		CMyVektor temp(x.get_dimension());
		temp = x; //vektoren gleichsetzen
		temp.set_component(i, temp.get_component(i) + h); //vektor an stelle i ändern in i+h

		grad.set_component(i, (funktion(temp) - funktion(x)) / h);

		//temp am ende zurücksetzen auf x -> kein neuer vektor pro itteration
	}

	return grad;
}

CMyVektor gradient(CMyVektor x, double(*funktion)(CMyVektor x)) {
	return gradient(x, funktion, pow(10, -8));
}

CMyVektor g_verfahren(CMyVektor x, double(*funktion)(CMyVektor x), double lambda)//lambda= 0.1 kann auch in header
{
	//double lambda = 1; //->default
	//double lambda = 0.1;   

	CMyVektor x_n(x.get_dimension()); //nächster zu x -> xn+1

	//1.Testschritt
	x_n = x + (lambda * gradient(x, funktion));
	int steps = 0;

	do {
		//Ausgabe
		std::cout << "Schritt " << steps << ":" << std::endl << "     x = ";
		x.print_vector(x);
		std::cout << "     lambda = " << lambda << std::endl;
		std::cout << "     f(x) = " << funktion(x) << std::endl
			<< "     grad f(x) = ";
		gradient(x, funktion).print_vector(gradient(x, funktion));
		std::cout << "     ||grad f(x)|| = " << gradient(x, funktion).vector_length(gradient(x, funktion)) << std::endl << std::endl;
		std::cout << "     x_neu = ";
		x_n.print_vector(x_n);
		std::cout << "     f(x_neu) = " << funktion(x_n) << std::endl;

		std::cout << std::endl;

		//2.halbieren -> wenn kleiner aktuellem wert
		if (funktion(x_n) <= funktion(x)) { //neuer wert kleiner oder gleich aktuellem

			do {
				lambda = lambda / 2; //Schrittweite halbieren
				std::cout << "     halbiere Schrittweite (lambda = " << lambda << "):" << std::endl;
				x_n = x + (lambda * gradient(x, funktion));

				std::cout << "     x_neu = ";
				x_n.print_vector(x_n);
				std::cout << "     f(x_neu) = " << funktion(x_n) << std::endl;
				std::cout << std::endl;

			} while (funktion(x_n) <= funktion(x)); //funktion x vor schleife einmal in variable packen -> nur einmal berechnen


		}

		//3.verdoppeln wenn größer als aktuell (dann mit größerem arbeiten)
		else {
			std::cout << "     Test mit doppelter Schrittweite (lambda = " << lambda * 2 << "): " << std::endl;

			CMyVektor x_test(x.get_dimension());
			x_test = x + ((lambda * 2) * gradient(x, funktion)); //doppelte Schrittweite

			std::cout << "     x_test = ";
			x_test.print_vector(x_test);
			std::cout << "     f(x_test) = " << funktion(x_test) << std::endl;

			if (funktion(x_test) > funktion(x_n)) {
				lambda = (lambda * 2);
				std::cout << "     verdoppele Schrittweite!" << std::endl;
				x_n = x_test;
			}

			else {
				std::cout << "     behalte alte Schrittweite!" << std::endl;
			}
		}

		x = x_n;
		x_n = x + (lambda * gradient(x, funktion));
		steps += 1;

		std::cout << std::endl;

	} while (steps < 25 && !(gradient(x_n, funktion).vector_length(gradient(x_n, funktion)) <= pow(10, -5))); //pow in variable -> weniger rechenarbeit!

	if (steps >= 25) {
		std::cout << "Ende wegen Schrittanzahl = 25 bei " << std::endl;
	}
	else {
		std::cout << "Ende wegen ||grad f(x)||<1e-5 bei" << std::endl;
	}

	std::cout << "     x = ";
	x.print_vector(x);
	std::cout << "     lambda = " << lambda << std::endl;
	std::cout << "     f(x) = " << funktion(x) << std::endl
		<< "     grad f(x) = ";
	gradient(x, funktion).print_vector(gradient(x, funktion));
	std::cout << "     ||grad f(x)|| = " << gradient(x, funktion).vector_length(gradient(x, funktion)) << std::endl;

	return x_n;
}

CMyVektor g_verfahren(CMyVektor x, double(*funktion)(CMyVektor x))
{
	return g_verfahren(x, funktion, 1.0);
}
