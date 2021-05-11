#pragma once

#include "CMyVektor.h"
#include <vector>
#include <math.h>

//m = Zeilen, n = Spalten

class CMyMatrix {
private:

	std::vector<std::vector<double>> matrix;

public:
	CMyMatrix(int dimension_m,int dimension_n); //Konstruktor
	~CMyMatrix() {};

	void set_component(int component_m, int component_n ,double value);
	double get_component(int component_m, int component_n);

	int get_dimension_m();
	int get_dimension_n();

	void print_matrix(CMyMatrix matrix);

	CMyMatrix invers(CMyMatrix matrix);
};

CMyVektor operator*(CMyMatrix A, CMyVektor x);
CMyMatrix jacobi(CMyVektor x, CMyVektor(*funktion)(CMyVektor x));

CMyVektor f_1(CMyVektor x); //a2 funktion

CMyVektor newton_verfahren(CMyVektor x,CMyVektor(*funktion)(CMyVektor x));
CMyVektor f_2(CMyVektor x_vec); //Aufgabe 3

CMyVektor f_prak(CMyVektor x_vec);