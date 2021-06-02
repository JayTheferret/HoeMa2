#include "CKomplex.h"

using namespace std;

CKomplex::CKomplex(double a, double b)
{
	i_im = a;
	j_re = b;

}

CKomplex::CKomplex(double phi)
{
	i_im = sin(phi);
	j_re = cos(phi);
}

double CKomplex::re()
{
	return j_re;
}

double CKomplex::im()
{
	return i_im;
}

double CKomplex::abs()
{
	return sqrt(j_re*j_re+i_im*i_im);
}

CKomplex operator+(CKomplex a, CKomplex b)
{
	return (a.re() + b.re(), a.im()+b.im());
}

CKomplex operator*(CKomplex a, CKomplex b)
{
	//z1*z2 = (x1*x2-y1*y2)+(x1*y2+x2*y1)*i

	return (a.re() * b.re()- a.im() * b.im(), a.re() * b.im() + b.re() * a.im());
}

CKomplex operator*(CKomplex a, double b)
{
	return (a.re() * b, a.im() * b);
}


//---------------------------------------------------------------
// --------------Hoeversches Funktionsgebiet---------------------
//---------------------------------------------------------------

vector<CKomplex>  werte_einlesen(const char *dateiname)
{
	int i, N, idx;
	double re, im;
	vector<CKomplex> werte;
	// File oeffnen
	ifstream fp;
	fp.open(dateiname);
	// Dimension einlesen
	fp >> N;
	// Werte-Vektor anlegen
	werte.resize(N);
	CKomplex null(0, 0);
	for (i = 0; i < N; i++)
		werte[i] = null;
	// Eintraege einlesen und im Werte-Vektor ablegen
	while (!fp.eof())
	{
		fp >> idx >> re >> im;
		CKomplex a(re, im);
		werte[idx] = a;
	}
	// File schliessen
	fp.close();

	return werte;
}

void werte_ausgeben(const char *dateiname, vector<CKomplex> werte, double epsilon)
{
	int i;
	int N = werte.size();
	// File oeffnen
	ofstream fp;
	fp.open(dateiname);
	// Dimension in das File schreiben
	fp << N << endl;
	// Eintraege in das File schreiben
	fp.precision(10);
	for (i = 0; i < N; i++)
		if (werte[i].abs() > epsilon)
			fp << i << "\t" << werte[i].re() << "\t" << werte[i].im() << endl;
	// File schliessen
	fp.close();
}