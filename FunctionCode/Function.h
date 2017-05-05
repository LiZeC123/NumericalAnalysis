#pragma once
#include <stdexcept>


/***************************
[����]	��
[����]	��
[����ֵ]��
[�쳣]	��
****************************/


/***************************
[����]	����ֵ�������������ղ�ֵ
[����]	����ֵ��x���ݣ���ֵ��y���ݣ���ֵ����������Ƶ�xֵ
[����ֵ]����ֵ�����ڹ��Ƶ㴦�ĺ���ֵ
[�쳣]	����
****************************/
inline double LagrangePolynomial(double x[], double y[], int n, double gx)
{
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

	return gy;
}


/***************************
[����]	����ֵ���֣���������ɭ��ʽ
[����]	���������ޣ��������ޣ���������������ֺ���
[����ֵ]��ָ�������ϵĻ���ֵ
[�쳣]	����
****************************/
template<typename Func>
inline double CompoundSimpson(double a, double b, int n, Func f)
{
	double h = (b - a) / n;
	double S = f(a) - f(b);
	double x = a;
	int k = 1;
	while (true)
	{
		x += h / 2;
		S += 4 * f(x);
		x += h / 2;	
		S += 2 * f(x);
		if (k == n) {
			break;
		}
		else {
			k++;
		}
	}

	S *= (h / 6);

	return S;
}


/***************************
[����]	����ֵ���֣����η�
[����]	���������ޣ��������ޣ����־��ȣ����ֺ���
[����ֵ]��ָ�������ϵĻ��ֽ��
[�쳣]	����
****************************/
template<typename Fun>
inline double TrapezoidMethod(double a, double b, double e, Fun f) 
{
	double h = b - a;
	double T1 = (h / 2)*(f(a) + f(b));
	double T2,S,x;

	do
	{
		S = 0;
		x = a + h / 2;
		do
		{
			S = S + f(x);
			x = x + h;
		} while (x < b);

		T2 = T1 / 2 + h*S / 2;

		if (abs(T2 - T1) < e) {
			break;
		}
		else {
			h = h / 2;
			T1 = T2;
		}
		//printf("T1:%.7f\tT2:%.7f\n", T1, T2);
	} while (true);

	return T2;
}


/***************************
[����]	����ֵ���֣�ţ��-��˹�ط���
[����]	���������ޣ��������ޣ����־��ȣ����ֺ���
[����ֵ]��ָ�������ϵĻ��ֽ��
[�쳣]	����
****************************/
template<typename Fun>
inline double NewtonCotesMethod(double a, double b, double e, Fun f)
{
	double h = b - a;
	double T1 = (h / 2)*(f(a) + f(b));
	int k = 1;

	double S, x;
	double T2, S1, S2;
	double C1, C2;
	double R1, R2;
	do
	{
		S = 0;
		x = a + h / 2;
		do
		{
			S = S + f(x);
			x = x + h;
		} while (x < b);

		T2 = T1 / 2 + h*S / 2;

		S2 = T2 + (T2 - T1) / 3;
		if (k == 1) {
			k++;
			h = h / 2;
			T1 = T2;
			S1 = S2;
			continue;
		}
		
		C2 = S2 + (S2 - S1) / 15;

		if (k == 2) {
			C1 = C2;

			k++;
			h = h / 2;
			T1 = T2;
			S1 = S2;
			continue;
		}

		R2 = C2 + (C2 - C1) / 63;

		if (k == 3) {
			R1 = R2;

			C1 = C2;

			k++;
			h = h / 2;
			T1 = T2;
			S1 = S2;
			continue;
		}
		
		if (abs(R2 - R1) < e) {
			break;
		}
	} while (true);

	return R2;

}


/***************************
[����]	����΢�ַ�����ֵ��⣬ŷ������
[����]	��f������x��y�ĺ�����x0��y0����ʼֵ��h��������N���������
[����ֵ]����
[�쳣]	����
****************************/
template<typename Fun>
inline void EulerMethod(Fun f, double x0, double y0, double h, double N) 
{
	int n = 1;
	double x1,yp,yc,y1;
	do
	{
		x1 = x0 + h;
		yp = y0 + h*f(x0, y0);
		yc = y0 + h*f(x1, yp);
		y1 = (yp + yc) / 2;
		printf("%.4f %.4f\n", x1, y1);

		if (n == N) {
			break;
		}
		else {
			n++;
			x0 = x1; y0 = y1;
		}
	} while (true);
}


/***************************
[����]	����΢�ַ�����ֵ��⣬�Ľ������������
[����]	��f������x��y�ĺ�����x0��y0����ʼֵ��h��������N���������
[����ֵ]����
[�쳣]	����
****************************/
template<typename Fun>
inline void RungeKuttaMethods4(Fun f, double x0, double y0, double h, double N) 
{
	int n = 1;
	double x1, y1, K1, K2, K3, K4;
	do
	{
		x1 = x0 + h;

		K1 = f(x0, y0);
		K2 = f(x0 + h / 2, y0 + h*K1 / 2);
		K3 = f(x0 + h / 2, y0 + h*K2 / 2);
		K4 = f(x1, y0 + h*K3);

		y1 = y0 + (K1 + 2 * K2 + 2 * K3 + K4)*h / 6;
		
		printf("%.4f %.4f\n", x1, y1);

		if (n == N) {
			break;
		}
		else {
			n++;
			x0 = x1; y0 = y1;
		}
	} while (true);
}


///***************************
//[����]	����΢�ַ�����ֵ��⣬�ǵ�ķ˹Ԥ��-У��ϵͳ
//[����]	��f������x��y�ĺ�����x0��y0����ʼֵ��h��������N���������
//[����ֵ]����
//[�쳣]	����
//****************************/
//template<typename Fun>
//inline void RungeKuttaMethods4(Fun f, double x0, double y0, double h, double N)
//{
//	double x[4]; double y[4];
//	int n = 1;
//	double x1, y1, K1, K2, K3, K4;
//	do
//	{
//		x1 = x0 + h;
//
//		K1 = f(x0, y0);
//		K2 = f(x0 + h / 2, y0 + h*K1 / 2);
//		K3 = f(x0 + h / 2, y0 + h*K2 / 2);
//		K4 = f(x1, y0 + h*K3);
//
//		y1 = y0 + (K1 + 2 * K2 + 2 * K3 + K4)*h / 6;
//
//		//printf("%.4f %.4f\n", x1, y1);
//		x[n] = x1;
//		y[n] = y1;
//
//		if (n == 3) {
//			break;
//		}
//		else {
//			n++;
//			x0 = x1; y0 = y1;
//		}
//	} while (true);
//
//	n = 4;
//	double x4, y4,dy4;
//	double yp, dyp;
//	do
//	{
//		x4 = x[3] + h;
//		yp = y[3]+h*(55)
//	} while (true);
//
//
//}

/***************************
[����]	���������󷽳̸�
[����]	��f������������x��ʼ���Ƶ�
[����ֵ]���������ֵ
[�쳣]	��������������������׳�logic_error�쳣
****************************/
template<typename Fun>
inline double mathIter(Fun f, double x) 
{
	const static int N = 10000000;
	const static double e = 0.0000001;

	int k;
	double x1, x0;

	for (k = 1,x0 = x, x1 = f(x0); abs(x1 - x0) >= e; k++, x0 = x1, x1 = f(x0)) {
		if (k == N) {
			throw std::logic_error("�ﵽ��������������δ�ܵ��ﾫ��Ҫ��");
		}
	}

	return x1;
}