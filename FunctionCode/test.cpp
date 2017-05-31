#include "Function.h"
#include <cmath>
#include <iostream>
#include "Elanguage.h"
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

void testQinJiushaoMethod()
{
	//ϵ������ӵ��������
	double coe[] = { 1,2,3,4 };
	auto r = QinJiushaoMethod(coe, 3, 0);
	printf("%.2f", r);
}

void testLarange()
{
	double x[] = { 100,121,144 };
	double y[] = { 10,11,12 };

	double gy = LagrangePolynomial(x, y, 3,115);
	printf("\n�������ղ�ֵ���Ϊ��%.4f\n", gy);
	
}


void testNewtonPolynomial()
{
	double x[] = { 100,121,144 };
	double y[] = { 10,11,12 };

	double gy = NewtonPolynomial(x, y, 3, 115);
	printf("\nţ�ٲ�ֵ���Ϊ��%.4f\n", gy);
}

void testCompoundSimpson()
{
	//auto f = [](double x)->double { return 1 + exp(-x)*sin(4 * x); };
	auto r = CompoundSimpson(0, 1, 8, f);
	printf("\n��������ɭ������������\n");
	printf("%.7f\n", r);
}

void testTrapezoidMethod()
{
	auto r = TrapezoidMethod(0, 1, 0.0000001, f);
	printf("\n���η���������\n");
	printf("%.7f\n", r);
}

void testRombrgMethod()
{
	auto r = RombrgMethod(0, 1, 0.0000001, f);
	printf("\n�����񷽷���������\n");
	printf("%.7f\n", r);
}

void testEulerMethod()
{
	auto f = [](double x, double y)->double {return y - 2 * x / y; };
	printf("\nŷ��������������\n");
	EulerMethod(f, 0, 1, 0.1, 10);
}

void testImprvEulerMethod()
{
	auto f = [](double x, double y)->double {return y - 2 * x / y; };
	printf("\n�Ľ�ŷ��������������\n");
	ImprvEulerMethod(f, 0, 1, 0.1, 10);
}

void testRungeKuttaMethods4() 
{
	auto f = [](double x, double y)->double {return y - 2 * x / y; };
	printf("\n�Ľ��������������������\n");
	RungeKuttaMethod4(f, 0, 1, 0.1, 10);
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
	printf("\n�Ľ��ǵ�ķ˹Ԥ��ϵͳ������������\n");
	AdamsMethod4(f, 0, 1, 0.1, 10);
}

void testDichotomy()
{
	auto f = [](double x)->double {return 12 - 3 * x + 2 * cos(x); };
	auto r = dichotomy(f, 3, 4, 0.00001);
	printf("\n���ַ���������\n");
	printf("%.5f\n", r);
}

void testMathIter() 
{
	auto f = [](double x)->double {return 4 + 2 * cos(x) / 3; };
	try
	{
		printf("\n��������������\n");
		auto a = mathIter(f, 1.2);
		printf("%.7f\n",a);
	}
	catch (const std::exception&e)
	{
		cout << e.what();
	}
}

void testAitkenIter()
{
	auto f = [](double x)-> double {return 4 + 2 * cos(x) / 3; };
	try
	{
		printf("\n���ؽ���ٷ���������\n");
		auto r = AitkenIter(f, 1);
		printf("%.7f\n", r);
	}
	catch (const std::exception&e)
	{
		cout << e.what();
	}
}

void testNewtonMethod()
{
	auto f = [](double x)->double {return  12 - 3 * x + 2 * cos(x); };
	auto Df = [](double x)->double {return -3 - 2 * sin(x); };

	
	try
	{
		printf("\nţ�ٷ���������\n");
		auto r = NewtonMethod(f, Df, 1, 0.0001);
		printf("%.7f\n", r);
	}
	catch (const std::exception&e)
	{
		cout << e.what();
	}
}

void testqSecantMethod()
{
	auto f = [](double x)->double {return 12 - 3 * x + 2 * cos(x); };

	try
	{
		printf("\n�����ҽط���������\n");
		auto r = qSecantMethod(f, 1, 2, 0.0001);
		printf("%.7f\n", r);
	}
	catch (const std::exception& e)
	{
		cout << e.what();
	}
}

void testJacobiMethod()
{
	double A[][3] = { {10,-1,-2},{-1,10,-2},{-1,-1,5} };
	double b[] = { 7.2,8.3,4.2 };
	double r[3];
	printf("\n�ſ˱ȵ�����������\n");
	try
	{
		JacobiMethod(A, b, r);

		for (int i = 0; i < 3; i++) {
			printf("x[%d] = %.5f ", i, r[i]);
		}
	}
	catch (const std::exception&e)
	{
		cout << e.what();
	}
}

void testGaussSeidelMethod()
{
	double A[][3] = { { 10,-1,-2 },{ -1,10,-2 },{ -1,-1,5 } };
	double b[] = { 7.2,8.3,4.2 };
	double r[3];
	printf("\n��˹-���¶�������������\n");
	try
	{
		GaussSeidelMethod(A, b, r);

		for (int i = 0; i < 3; i++) {
			printf("x[%d] = %.5f ", i, r[i]);
		}
	}
	catch (const std::exception&e)
	{
		cout << e.what();
	}
}

void testJordanMethod()
{
	//double A[][3] = { {2,-1,3},{4,2,5},{1,2,0} };
	//double b[] = { 1,4,7 };
	double A[][3] = { { 10,-1,-2 },{ -1,10,-2 },{ -1,-1,5 } };
	double b[] = { 7.2,8.3,4.2 };

	printf("\nԼ����ȥ��������\n");
	JordanMethod(A, b);
	
	for (int i = 0; i < 3; i++) {
		printf("x[%d] = %.5f ", i, b[i]);
	}
}

void testGaussMethod()
{
	double A[][3] = { { 10,-1,-2 },{ -1,10,-2 },{ -1,-1,5 } };
	double b[] = { 7.2,8.3,4.2 };

	printf("\n��˹��ȥ��������\n");
	try
	{
		GaussMethod(A, b);
		for (int i = 0; i < 3; i++) {
			printf("x[%d] = %.5f ", i, b[i]);
		}
	}
	catch (const std::exception&e)
	{
		cout << e.what();
	}
}

���� ������()
{
	���� ʵ��һ ��ֵΪ 1;
	���� ʵ��� ��ֵΪ 2;
	���� ʵ���� ��ֵΪ 3;
	���� ʵ���� ��ֵΪ 4;

	���� ʵ��ֵ ��ֵΪ -1;
	��׼��� ��� "������ʵ�����:";
	��׼���� ���� ʵ��ֵ;


	��� ʵ��ֵ ���� ʵ��һ ��ô
		��׼��� ��� "����115������ƽ����\n";
		testLarange();
		testNewtonPolynomial();
	����� ʵ��ֵ ���� ʵ��� ��ô
		��׼��� ��� "����P98��΢�ַ���\n";
		testEulerMethod();
		testImprvEulerMethod();
		testRungeKuttaMethods4();
		testAdamsMethod4();
	����� ʵ��ֵ ���� ʵ���� ��ô
		��׼��� ��� "���㷽��12-3x+2cos(x)�ĸ�\n";
		testDichotomy();
		testMathIter();
		testAitkenIter();
		testNewtonMethod();
		testqSecantMethod();
	����� ʵ��ֵ ���� ʵ���� ��ô
		��׼��� ��� "���㷽����ĸ�\n|10 -1  2| |x1|   |7.2|\n|-1 10 -2|*|x2| = |8.3|\n|-1 -1  5| |x3|   |4.2|\n";
		testJacobiMethod();
		testGaussSeidelMethod();
		testJordanMethod();
		testGaussMethod();
	����
		��׼��� ��� "����sin(x)/x������[0,1]�ϵĻ���\n";
		testCompoundSimpson();
		testTrapezoidMethod();
		testRombrgMethod();	
	����

	��׼��� ��� ��׼����;

	���� 0;
}