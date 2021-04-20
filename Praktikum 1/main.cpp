#include<iostream>
#include "CMyVektor.h"

int main() {

	/*std::cout	<< "1 - Create a new Vector with Dimension" << std::endl
				<< "2 - Get Dimension of Vector" << std::endl
				<< "3 - set specific elements of Vector" << std::endl
				<< "4 - get specific element of Vector" << std::endl;*/

	CMyVektor test1(3);

	/*test1.set_component(0, 1);
	test1.set_component(1, 2);
	test1.set_component(2, 3);

	test1.print_vector(test1);
	std::cout << std::endl;

	std::cout << "Dimension: " << test1.get_dimension() << std::endl;
	std::cout << "laenge: " << test1.vector_length(test1) << std::endl << std::endl;

	CMyVektor test2(3);

	test2.set_component(0, 4);
	test2.set_component(1, 5);
	test2.set_component(2, 6);

	test2.print_vector(test2);
	std::cout << std::endl;

	std::cout << "Dimension: " << test2.get_dimension() << std::endl;
	std::cout << "length: " << test2.vector_length(test2) << std::endl;

	std::cout << std::endl;
	std::cout << "Vector addition: ";

	CMyVektor add(3);
	add = test1 + test2;

	add.print_vector(add);

	std::cout << std::endl;
	std::cout << "Vector Multiplikation: ";

	CMyVektor mult(3);
	mult = 2 * test2;

	mult.print_vector(mult);*/

	//------------------------
	/*
	CMyVektor x(3);
	x.set_component(0, 0);
	x.set_component(1, 0);
	x.set_component(2, 0);

	g_verfahren(x, gvx, 0.1);
	*/
	//------------------------

	CMyVektor x(2);
	x.set_component(0, 0.2);
	x.set_component(1, -2.1);

	g_verfahren(x, fvx);
		
	
	//std::cout << "x = ";
	//x.print_vector(x);

	//CMyVektor x_erg(3);
	//x_erg = gradient(x, funktion);

	//std::cout << "grad g(x) = ";
	//x_erg.print_vector(x_erg);

	//x_erg = g_verfahren(x_erg, funktion);
	//std::cout << "x_n = ";
	//x_erg.print_vector(x_erg);


	return 0;
	system("PAUSE");
}