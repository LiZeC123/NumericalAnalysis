#include "Function.h"
#include <cmath>
#include <iostream>

using namespace std;

//���⴦��ĺ�����������x=0ʱ����NaN
double f(double x)
{
	if (x == 0) {
		return 1;
	}
	else {
		return sin(x) / x;
	}
}

void testLarange()
{
	cout << "�������ֵ�����" << endl;
	int n;
	cin >> n;

	double* x = new double[n];
	double* y = new double[n];
	cout << "�����������ֵ�㣬ÿ��һ�����ݣ���ʽΪ x y" << endl;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}

	double gx;
	cout << "����������ƺ���ֵ:";
	cin >> gx;

	double gy = LagrangePolynomial(x, y, n,gx);

	cout << "�����ڵ�ֵΪ��" << gy << endl;

	delete[] x;
	delete[] y;

	cout << "end";
}

void testCompoundSimpson()
{
	auto r = CompoundSimpson(0, 1, 10, f);
	printf("The Answer of CompoundSimpson is %.7f\n", r);
}

void testTrapezoidMethod()
{
	auto r = TrapezoidMethod(0, 1, 0.0000001, f);
	printf("The Answer of TrapezoidMethod is %.7f\n", r);
}

void testNewtonCotesMethod()
{
	auto r = NewtonCotesMethod(0, 1, 0.0000001, f);
	printf("The Answer of NewtonCotesMethod is %.7f\n", r);
}

void testRungeKuttaMethods4() 
{
	auto f = [](double x, double y)->double {return y - 2 * x / y; };
	RungeKuttaMethod4(f, 0, 1, 0.2, 5);
}

void testAdamsMethod4()
{
	auto f = [](double x, double y)->double {return y - 2 * x / y; };
	AdamsMethod4(f, 0, 1, 0.1, 10);
}

void testEulerMethod()
{
	auto f = [](double x, double y)->double {return y - 2 * x / y; };
	EulerMethod(f, 0, 1, 0.1, 10);
}


void testMathIter() 
{
	auto f = [](double x)->double {return sqrt(x + 1); };
	try
	{
		auto a = mathIter(f, 1);
		printf("%.7f\n",a);
	}
	catch (const std::exception&e)
	{
		cout << e.what();
	}
}

void testAitkenIter()
{
	auto f = [](double x)-> double {return exp(-x); };
	try
	{
		auto r = AitkenIter(f, 0.5);
		printf("%.7f\n", r);
	}
	catch (const std::exception&e)
	{
		cout << e.what();
	}
}

int main()
{

	//testLarange()
	
	//testCompoundSimpson();
	//testTrapezoidMethod();
	//testNewtonCotesMethod();

	//testEulerMethod();
	//testRungeKuttaMethods4();
	//cout << endl;
	//testAdamsMethod4();

	//testMathIter();
	testAitkenIter();

	return 0;
}