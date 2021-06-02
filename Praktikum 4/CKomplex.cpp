#include "CKomplex.h"

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
