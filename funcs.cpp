#include "funcs.h"

int iter::NOI = 0;
int iter::it[5];

double iter::f(double x)
{
	return (0.1*x*x - sin(x - M_PI_4) - 1.5);
}

double iter::df(double x) {
	return (0.2*x - cos(x - M_PI_4));
}

double iter::findRoot(double eps, double a, double b)
{
	double x0, xk;
	double q, M1, m1, lambda;
	int iterations = 0;
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
		iterations++;
		x0 = xk;
		if ((df(a) < 0) && (df(b) < 0))
			xk = x0 - lambda * (-f(x0));
		else
			xk = x0 - lambda * f(x0);
	}
	it[NOI] = iterations;
	NOI++;
	return xk;
}

int bisec::NOI = 0;
int bisec::it[5];

double bisec::f(double x)
{
	return (0.1*x*x - sin(x - 0.785398) - 1.5);
}

double bisec::findRoot(double eps, double a, double b)
{
	double x1, x2;
	double c;
	int iterations = 0;
	if (a > b) {
		x1 = b;
		x2 = a;
	}
	else {
		x1 = a;
		x2 = b;
	}
	while ((x2 - x1) / 2 >= eps) {
		iterations++;
		c = (x1 + x2) / 2;
		if (f(c)*f(x1) < 0) 
			x2 = c;
		else
			x1 = c;
	}
	c = (x1 + x2) / 2;
	it[NOI] = iterations;
	NOI++;
	return c;
}

void printTable1(double a, double b, double(*findRoot)(double, double, double), double(*f)(double), const char* name)
{
	double x = 0;
	double fx = 0;
	double eps = 1e-2;
	printf("Table 1 for %s\n", name);
	while (eps >= 1e-14) {
		x = findRoot(eps, a, b);
		fx = f(x);
		printf("| eps: %.0e | x: %.14f | err: %.14f |\n", eps, x, fabs(fx));
		eps *= 1e-3;
	}
}

void printTable2(const int * it1, const int * it2) {
	double eps = 1e-2;
	int i = 0, j = 0;
	printf("Table 2\n");
	while (eps >= 1e-14) {
		printf("| eps: %.0e | iter: %2d | bisec: %2d |\n", eps, it1[i], it2[j]);
		i++;
		j++;
		eps *= 1e-3;
	}
}
