#pragma once
#include <vector>
#include <math.h>

//iomanip -> ausgabe anpassen (kommazahlen anpassen)

class CMyVektor {
private:
	std::vector<double> vector; //vector mir stl
	int dimension;

public:

	CMyVektor(int dimension); //konstruktor

	int get_dimension();
	void set_component(int component, double value);
	double get_component(int component);

	double vector_length(CMyVektor vector);
	void print_vector(CMyVektor vector);

	double& operator[](int index) {return vector[index];};
};

CMyVektor operator+(CMyVektor a, CMyVektor b); //Vektor addition -> ueverschreibt + fuer vektoren
CMyVektor operator*(double lambda, CMyVektor a); //Vektor multiplikation -> ueberschreibt * fuer Vektoren(CMyVector) -> Reihenfolge wichtig! lambda*a != a*lambda (funktion umdrehen)

//Aufgabe 2

double fvx(CMyVektor x);
double gvx(CMyVektor x);

CMyVektor gradient(CMyVektor x, double(*funktion)(CMyVektor x));

//Aufgabe 3

CMyVektor g_verfahren(CMyVektor x, double(*funktion)(CMyVektor x), double lambda );
CMyVektor g_verfahren(CMyVektor x, double(*funktion)(CMyVektor x)); //default lambda = 1.0