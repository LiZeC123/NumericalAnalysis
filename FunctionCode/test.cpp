#include "Function.h"
#include <cmath>
#include <iostream>

using namespace std;

//特殊处理的函数，避免在x=0时产生NaN
double f(double x)
{
	if (x == 0) {
		return 1;
	}
	else {
		return sin(x) / x;
	}
}

void testQinJiushaoMethod()
{
	//系数数组从低向高排列
	double coe[] = { 1,2,3,4 };
	auto r = QinJiushaoMethod(coe, 3, 0);
	printf("%.2f", r);
}

void testLarange()
{
	cout << "请输入插值点个数" << endl;
	int n;
	cin >> n;

	double* x = new double[n];
	double* y = new double[n];
	cout << "请依次输入插值点，每行一组数据，格式为 x y" << endl;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}

	double gx;
	cout << "请输入待估计函数值:";
	cin >> gx;

	double gy = LagrangePolynomial(x, y, n,gx);

	cout << "待估节点值为：" << gy << endl;

	delete[] x;
	delete[] y;

	cout << "end";
}

void testCompoundSimpson()
{
	auto f = [](double x)->double { return 1 + exp(-x)*sin(4 * x); };
	auto r = CompoundSimpson(0, 1, 3, f);
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
	auto f = [](double x, double y)->double {return 2 * x*x*x / y; };
	RungeKuttaMethod4(f, -1, -1, 0.1, 30);
}

void testRungeKuttaMethods42()
{
	auto f = [](double x, double y, double z)-> double {return z; };
	auto g = [](double x, double y, double z)-> double {return 2 * y*y*y; };
	
	RungeKuttaMethod4(f, g, 1, -1, -1, 0.1, 5);

}

void testRungeKuttaMethods2th4()
{
	auto f = [](double x, double y, double Dy)-> double {return 2 * y*y*y; };
	RungeKuttaMethod2th4(f, 1, -1, -1, 0.1, 5);
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
	auto f = [](double x)->double {return 4 + 2 * cos(x) / 3; };
	try
	{
		auto a = mathIter(f, 0.4);
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

void testNewtonMethod()
{
	auto f = [](double x)->double {return pow(x, 3) + 2 * pow(x, 2) + 10 * x - 20; };
	auto Df = [](double x)->double {return 3 * pow(x, 2) + 4 * x + 10; };

	
	try
	{
		auto r = NewtonMethod(f, Df, 1, 0.0001);
		printf("%.7f", r);
	}
	catch (const std::exception&e)
	{
		cout << e.what();
	}
}

void testqSecantMethod()
{
	auto f = [](double x)->double {return pow(x, 3) + 2 * pow(x, 2) + 10 * x - 20; };

	try
	{
		auto r = qSecantMethod(f, 1, 2, 0.0001);
		printf("%.7f", r);
	}
	catch (const std::exception& e)
	{
		cout << e.what();
	}
}

int main()
{
	//testQinJiushaoMethod();

	//testLarange()
	
	//testCompoundSimpson();
	//testTrapezoidMethod();
	//testNewtonCotesMethod();

	//testEulerMethod();
	//testRungeKuttaMethods4();
	testRungeKuttaMethods42();
	testRungeKuttaMethods2th4();
	//testAdamsMethod4();

	//testMathIter();
	//testAitkenIter();
	//testNewtonMethod();
	//testqSecantMethod();
	


	return 0;
}