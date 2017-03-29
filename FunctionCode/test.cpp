#include "Function.h"
#include <cmath>
#include <iostream>

using namespace std;

double f(double x)
{
	if (x == 0) {
		return 1;
	}
	else {
		return sin(x) / x;
	}
}

double g(double x)
{
	static double s[] = { 1.0,0.9973978,0.9896158,0.9767267,0.9588510,0.9361556,0.9088516,0.8771925,0.8414709 };
	int i = x * 8;
	return s[i];
}

int main()
{
	double h = 1.0 / 8;
	for (double i = h; i < 2; i += h) {
		cout << f(i) << endl;
	}
	double s = Compound_Simpson(0, 1, 10240, f);
	printf("%.10f", s);
	
	//double s = Romberg(0, 1, 0.001, f);
	//cout << s;
	return 0;
}