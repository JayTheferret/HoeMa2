#pragma once
#include <vector>
#include <math.h>

class CMyVektor {
private:
	std::vector<double> vector; //vector mir stl
	int dimension;

public:

	CMyVektor(int dimension); //konstruktor

	int get_dimension();
	void set_Component(int component, double value);
	double get_component(int component);

	double vector_length(CMyVektor vector);
	void print_vector(CMyVektor vector);

};

CMyVektor operator+(CMyVektor a, CMyVektor b); //Vektor addition -> ueverschreibt + fuer vektoren
CMyVektor operator*(double lambda, CMyVektor a); //Vektor multiplikation -> ueberschreibt * fuer Vektoren(CMyVector) -> Reihenfolge wichtig! lambda*a != a*lambda (funktion umdrehen)