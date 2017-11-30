#include "funcs.h"

double iter::f(double x)
{
	return (0.1*x*x - sin(x - 0.785398) - 1.5);
}

double iter::df(double x) {
	return (0.2*x - cos(x - M_PI_4));
}

double iter::findRoot(double eps, double a, double b)
{
	double x0, xk;
	double q, M1, m1, lambda;
	//NOI = 0;
	if ((df(a) < 0) && (df(b) < 0))
	{
		m1 = ((df(a)) > (df(b))) ? -df(a) : -df(b);
		M1 = ((df(a)) < (df(b))) ? -df(a) : -df(b);
	}
	else
	{
		m1 = ((df(a)) < (df(b))) ? df(a) : df(b);
		M1 = ((df(a)) > (df(b))) ? df(a) : df(b);
	}
	lambda = 1 / M1;
	q = 1 - m1 / M1;
	x0 = (a + b) / 2;
	if ((df(a) < 0) && (df(b) < 0)) 
		xk = x0 - lambda * (-f(x0));
	else
		xk = x0 - lambda * f(x0);
	while (abs(xk - x0) > (((1 - q) / q)*eps)) 
	{
		//NOI++;
		x0 = xk;
		if ((df(a) < 0) && (df(b) < 0))
			xk = x0 - lambda * (-f(x0));
		else
			xk = x0 - lambda * f(x0);
	}
	return xk;
}



