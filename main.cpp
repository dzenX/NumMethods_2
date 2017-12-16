#include "funcs.h"

int main() {
	printTable1(a1, b1, iter::findRoot, iter::f, "iter");
	printTable1(a1, b1, bisec::findRoot, bisec::f, "bisec");
	printTable2(iter::it,bisec::it);
	return 0;
}