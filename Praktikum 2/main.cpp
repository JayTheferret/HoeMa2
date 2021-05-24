#include<iostream>
#include "CMyVektor.h"
#include "CMyMatrix.h"

int main() {
	
	//-------------------------------------------------------------------------------------------
	//Aufgabe 1

	//-------------------------------------------------------------------------------------------
	//inverse Matrix Beispiel

	/*CMyMatrix m_1(2,2);
	m_1.set_component(0, 0, 1);
	m_1.set_component(0, 1, 2);
	m_1.set_component(1, 0, 3);
	m_1.set_component(1, 1, 4);

	m_1.print_matrix(m_1);

	std::cout << "Dimension: " << m_1.get_dimension_m() << "X" << m_1.get_dimension_n() << std::endl;

	std::cout << "inverse Matrix: " << std::endl;
	m_1.print_matrix(m_1.invers(m_1));*/

	//-------------------------------------------------------------------------------------------
	//Mult test

	/*CMyMatrix mult(2, 3);
	mult.set_component(0, 0, 4);
	mult.set_component(0, 1, 3);
	mult.set_component(0, 2, 2);
	mult.set_component(1, 0, 1);
	mult.set_component(1, 1, 2);
	mult.set_component(1, 2, 3);

	std::cout << "Matrix Vektor Multiplikation: " << std::endl;
	mult.print_matrix(mult);
	std::cout << "mal" << std::endl;

	CMyVektor mult_v(3);
	mult_v.set_component(0, 2);
	mult_v.set_component(1, 3);
	mult_v.set_component(2, 4);

	mult_v.print_vector(mult_v);

	std::cout << "=" << std::endl;
	mult_v.print_vector(mult*mult_v);*/

	//-------------------------------------------------------------------------------------------
	//Aufgabe 2

	/*CMyVektor x(4);
	x.set_component(0, 1);
	x.set_component(1, 2);
	x.set_component(2, 0);
	x.set_component(3, 3);

	CMyMatrix j_matrix = jacobi(x, f_1);
	j_matrix.print_matrix(j_matrix);
*/
	//-------------------------------------------------------------------------------------------
	//Aufgabe 3

	CMyVektor x(2); //startwert
	x.set_component(0, 1);
	x.set_component(1, 1); 

	newton_verfahren(x, f_2);

	//-------------------------------------------------------------------------------------------
	
	return 0;
	system("PAUSE");
}