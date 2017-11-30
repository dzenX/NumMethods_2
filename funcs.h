#pragma once

#define _USE_MATH_DEFINES
#define a1 -5.
#define b1 -4.6

#include <math.h>
#include <iostream>

using std::cout;
using std::endl;

namespace iter {
	//int NOI;
	double f(double x);
	double df(double x);
	double findRoot(double eps, double a, double b);
}