#include "CZufall.h"

int CZufall::wert(int a, int b)
{
	//v1 = rand() % 100;         // v1 in the range 0 to 99
	//v2 = rand() % 100 + 1;     // v2 in the range 1 to 100
	//v3 = rand() % 30 + 1985;   // v3 in the range 1985-2014 

	//Zahl soll a<= n <=b

	//return(rand() % (b + 1) + a);
	return((rand() % (b + 1 - a)) + a); //zahlen von 0 bis b-a (+a) = a bis b
}

void CZufall::initialisiere(int s)
{
	srand(s);
}

std::vector<int> CZufall::test(int a, int b, int N)
{
	std::vector<int> result;
	result.resize(b + 1 - a); //nur Stellen a+1 etc wichtig

	for (int i = 0; i < N; i++) {
		result.at(wert(a,b) - a) += 1; // wie oft a, a+1 ...,b auftreten
		//++result[wert(a, b) - a];
	}

	return result;
}

std::vector<int> CZufall::test_falsch(int a, int b, int N)
{
	std::vector<int> result;
	result.resize(b + 1 - a); //nur Stellen a+1 etc wichtig

	initialisiere(time(NULL));
	for (int i = 0; i < N; i++) {

		

		++result.at(wert(a, b) - a); // wie oft a, a+1 ...,b auftreten
	}

	return result;
}
