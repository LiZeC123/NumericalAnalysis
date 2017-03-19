#include "Function.h"
#include <iostream>

//此部分代码应该从性能角度出发，尽可能考虑按照C style 编写

using namespace std;
void Lagrange_polynomial()
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

	double gy = 0;
	for (int k = 0; k < n; k++) {
		double u = 1, d = 1;

		for (int j = 0; j < n; j++) {
			if (j != k) {
				u *= (gx - x[j]);
				d *= (x[k] - x[j]);
			}
		}

		gy += (u / d)*y[k];
	}

	cout << "待估节点值为：" << gy << endl;

	delete[] x;
	delete[] y;

	cout << "end";
}

//牛顿插值法，具体步骤待补充
//void Newton_polynomial()
//{
//
//}