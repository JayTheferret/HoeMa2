#pragma once
#include <fstream>
#include <vector>
#include <cmath>
#include <iostream>

class CKomplex {

private:

	double j_re = 0; //realteil
	double i_im = 0; //imaginaerteil

public:
	CKomplex() = default;

	CKomplex(double re, double im); //a+bj
	CKomplex(double phi);//e^(j*phi)

	double re(); //return re
	double im(); //return im
	double abs(); //return betrag der komplexen zahl

};

void print_komplex(CKomplex a);

CKomplex operator+(CKomplex a, CKomplex b); //komplexe add
CKomplex operator*(CKomplex a, CKomplex b); //komplexe mult
CKomplex operator*(CKomplex a, double b); //double ,mit komplex
CKomplex operator*(double b, CKomplex a); //double ,mit komplex

CKomplex operator-(CKomplex a, CKomplex b);

//Aufgabe 3

std::vector<CKomplex> fourier_tf(std::vector<CKomplex> a, bool invers);

double difference(std::vector<CKomplex> original, std::vector<CKomplex> invers);

//---------------------------------------------------------------
// --------------Hoeversches Funktionsgebiet---------------------
//---------------------------------------------------------------

std::vector<CKomplex>  werte_einlesen(const char *dateiname);
void werte_ausgeben(const char *dateiname, std::vector<CKomplex> werte, double epsilon = -1.0);



