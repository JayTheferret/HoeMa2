#include<iostream>
#include "CMyVektor.h"
#include "CMyMatrix.h"

int main() {

	//Praktikum eins, Vektorbeispielaufgaben

	//------------------------
	/*
	CMyVektor x(3);
	x.set_component(0, 0);
	x.set_component(1, 0);
	x.set_component(2, 0);

	g_verfahren(x, gvx, 0.1);
	*/
	//------------------------

	/*CMyVektor x(2);
	x.set_component(0, 0.2);
	x.set_component(1, -2.1);

	g_verfahren(x, fvx);
*/

	//CMyMatrix m_1(2,2);
	//m_1.set_component(0, 0, 1);
	//m_1.set_component(0, 1, 2);
	//m_1.set_component(1, 0, 3);
	//m_1.set_component(1, 1, 4);

	//m_1.print_matrix(m_1);

	//std::cout << "Dimension: " << m_1.get_dimension_m() << "X" << m_1.get_dimension_n() << std::endl;

	//std::cout << "inverse Matrix: " << std::endl;
	//m_1.print_matrix(m_1.invers(m_1));
	////m_1.invers(m_1);

	//std::cout << "Matrix Vektor Multiplikation: ";

	//CMyVektor v_1(2);
	//v_1.set_component(0, 1);
	//v_1.set_component(1, 2);

	//CMyVektor mult(2);
	//mult = m_1 * v_1;
	//mult.print_vector(mult);

	////Beispiel Aufgabe 2
	/*CMyVektor x(4);
	x.set_component(0, 1);
	x.set_component(1, 2);
	x.set_component(2, 0);
	x.set_component(3, 3);

	CMyMatrix j_matrix = jacobi(x, f_1);
	j_matrix.print_matrix(j_matrix);
*/
	//aufgabe 3
	CMyVektor x(2);
	x.set_component(0, 1);
	x.set_component(1, 1);

	newton_verfahren(x, f_2);



	return 0;
	system("PAUSE");
}