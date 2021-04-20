#include "CMyVektor.h"
#include <iostream>

CMyVektor::CMyVektor(int dimension) {
	vector.resize(dimension); //vector mit platz fuer "dimension" viele elemente
}

int CMyVektor::get_dimension() { //methode fuer dimension... dasselbe wie size
	return vector.size();
}

void CMyVektor::set_Component(int component, double value)
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
			c.set_Component(i, ab);
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
		c.set_Component(i, la);
	}
	return c;
}
