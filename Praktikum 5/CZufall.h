#pragma once

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

class CZufall {

public:
	
	CZufall() = default;

	int wert(int a, int b); //(roughly) evenly distributed random number (a<=n<=b)
	void initialisiere(int s); //zufallsgenerator mit srand(s)
	std::vector<int> test(int a, int b, int N); //N mal zufallszahl zw a und b, ermittelt wie oft werte a, a+1,...b auftreten (häufigkeiten als vektor zurueckgeben)
	std::vector<int> test_falsch(int a, int b, int N); //wie test nur zufallsgenerator mit initialisere(time(NULL)) neu initialisieren
};