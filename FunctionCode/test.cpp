#include "Function.h"
#include <cmath>
#include <iostream>
#include "Elanguage.h"
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
	double x[] = { 100,121,144 };
	double y[] = { 10,11,12 };

	double gy = LagrangePolynomial(x, y, 3,115);
	printf("\n拉格朗日插值结果为：%.4f\n", gy);
	
}


void testNewtonPolynomial()
{
	double x[] = { 100,121,144 };
	double y[] = { 10,11,12 };

	double gy = NewtonPolynomial(x, y, 3, 115);
	printf("\n牛顿插值结果为：%.4f\n", gy);
}

void testCompoundSimpson()
{
	//auto f = [](double x)->double { return 1 + exp(-x)*sin(4 * x); };
	auto r = CompoundSimpson(0, 1, 8, f);
	printf("\n复化辛普森方法计算结果：\n");
	printf("%.7f\n", r);
}

void testTrapezoidMethod()
{
	auto r = TrapezoidMethod(0, 1, 0.0000001, f);
	printf("\n矩形法计算结果：\n");
	printf("%.7f\n", r);
}

void testRombrgMethod()
{
	auto r = RombrgMethod(0, 1, 0.0000001, f);
	printf("\n龙贝格方法计算结果：\n");
	printf("%.7f\n", r);
}

void testEulerMethod()
{
	auto f = [](double x, double y)->double {return y - 2 * x / y; };
	printf("\n欧拉方法计算结果：\n");
	EulerMethod(f, 0, 1, 0.1, 10);
}

void testImprvEulerMethod()
{
	auto f = [](double x, double y)->double {return y - 2 * x / y; };
	printf("\n改进欧拉方法计算结果：\n");
	ImprvEulerMethod(f, 0, 1, 0.1, 10);
}

void testRungeKuttaMethods4() 
{
	auto f = [](double x, double y)->double {return y - 2 * x / y; };
	printf("\n四阶龙格库塔方法计算结果：\n");
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
	printf("\n四阶亚丹姆斯预报系统方法计算结果：\n");
	AdamsMethod4(f, 0, 1, 0.1, 10);
}

void testDichotomy()
{
	auto f = [](double x)->double {return 12 - 3 * x + 2 * cos(x); };
	auto r = dichotomy(f, 3, 4, 0.00001);
	printf("\n二分法计算结果：\n");
	printf("%.5f\n", r);
}

void testMathIter() 
{
	auto f = [](double x)->double {return 4 + 2 * cos(x) / 3; };
	try
	{
		printf("\n迭代法计算结果：\n");
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
		printf("\n艾特金加速法计算结果：\n");
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
		printf("\n牛顿法计算结果：\n");
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
		printf("\n快速弦截法计算结果：\n");
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
	printf("\n雅克比迭代法计算结果\n");
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
	printf("\n高斯-赛德尔迭代法计算结果\n");
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

	printf("\n约当消去法计算结果\n");
	JordanMethod(A, b);
	
	for (int i = 0; i < 3; i++) {
		printf("x[%d] = %.5f ", i, b[i]);
	}
}

void testGaussMethod()
{
	double A[][3] = { { 10,-1,-2 },{ -1,10,-2 },{ -1,-1,5 } };
	double b[] = { 7.2,8.3,4.2 };

	printf("\n高斯消去法计算结果\n");
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

整型 主函数()
{
	常数 实验一 赋值为 1;
	常数 实验二 赋值为 2;
	常数 实验三 赋值为 3;
	常数 实验四 赋值为 4;

	整型 实验值 赋值为 -1;
	标准输出 输出 "请输入实验序号:";
	标准输入 输入 实验值;


	如果 实验值 等于 实验一 那么
		标准输出 输出 "计算115的算术平方根\n";
		testLarange();
		testNewtonPolynomial();
	又如果 实验值 等于 实验二 那么
		标准输出 输出 "计算P98的微分方程\n";
		testEulerMethod();
		testImprvEulerMethod();
		testRungeKuttaMethods4();
		testAdamsMethod4();
	又如果 实验值 等于 实验三 那么
		标准输出 输出 "计算方程12-3x+2cos(x)的根\n";
		testDichotomy();
		testMathIter();
		testAitkenIter();
		testNewtonMethod();
		testqSecantMethod();
	又如果 实验值 等于 实验四 那么
		标准输出 输出 "计算方程组的根\n|10 -1  2| |x1|   |7.2|\n|-1 10 -2|*|x2| = |8.3|\n|-1 -1  5| |x3|   |4.2|\n";
		testJacobiMethod();
		testGaussSeidelMethod();
		testJordanMethod();
		testGaussMethod();
	否则
		标准输出 输出 "计算sin(x)/x在区间[0,1]上的积分\n";
		testCompoundSimpson();
		testTrapezoidMethod();
		testRombrgMethod();	
	结束

	标准输出 输出 标准换行;

	返回 0;
}