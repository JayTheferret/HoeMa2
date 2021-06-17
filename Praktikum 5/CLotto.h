#pragma once
#include "CZufall.h"

class CLotto {

private:

	std::vector<int> TZ;

public:

	CLotto(int k, int n, int s);

	void set_TZ(std::vector<int> a);
	std::vector<int> k_aus_n_Ziehung();
	int matches(std::vector<int> ziehung, std::vector<int> TZ);
};