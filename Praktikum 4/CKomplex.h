#pragma once
#include "vector"

#include <cmath>;

class CKomplex {

private:

	double j_re; //realteil
	double i_im; //imaginaerteil

public:

	CKomplex(double a, double b); //a+bj
	CKomplex(double phi);//e^(j*phi)

	double re(); //return re
	double im(); //return im
	double abs(); //return betrag der komplexen zahl
};

CKomplex operator+(CKomplex a, CKomplex b); //komplexe add
CKomplex operator*(CKomplex a, CKomplex b); //komplexe mult
CKomplex operator*(CKomplex a, double b); //double ,mit komplex