#include "CLotto.h"

CLotto::CLotto(int k, int n, int s)
{
	CZufall z;

	if (s < 0) {
		z.initialisiere(time(NULL));
}
	else {
		z.initialisiere(s);
	}
}

void CLotto::set_TZ(std::vector<int> a)
{
	TZ = a;
}

std::vector<int> CLotto::k_aus_n_Ziehung()
{
	std::vector<int> ziehung;

	//do while (neuziehung waehrend zahl schonmal drin)
	return ziehung;
}
