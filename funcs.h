#pragma once

#define _USE_MATH_DEFINES
#define a1 -5.
#define b1 -4.6
#define a2 1
#define b2 1.3

#include <math.h>
#include <iostream>

using std::cout;
using std::endl;

namespace iter {
	extern int NOI;
	extern int it[5];
	double f(double x);
	double df(double x);
	double findRoot(double eps, double a, double b);
}

namespace bisec {
	extern int NOI;
	extern int it[5];
	double f(double x);
	double findRoot(double eps, double a, double b);
}

void printTable1(double a, double b, double(*findRoot)(double, double, double), double(*f)(double), const char* name);
void printTable2(const int * it1, const int* it2);