#include "Function.h"
#include <iostream>

//�˲��ִ���Ӧ�ô����ܽǶȳ����������ܿ��ǰ���C style ��д

using namespace std;
void Lagrange_polynomial()
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

	cout << "�����ڵ�ֵΪ��" << gy << endl;

	delete[] x;
	delete[] y;

	cout << "end";
}

//ţ�ٲ�ֵ�������岽�������
//void Newton_polynomial()
//{
//
//}