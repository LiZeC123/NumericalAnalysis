#pragma once
#include <stdexcept>


/***************************
[����]	���������ʽ��ֵ���ؾ����㷨
[����]	��coe��ϵ�����飻N������������x���Ա���ֵ
[����ֵ]������ʽ��ֵ
[�쳣]	����
****************************/
inline double QinJiushaoMethod(double coe[], int N,int x)
{
	
	double r = coe[N];
	for (int k = 1; k < N+1; k++) {
		r = x*r + coe[N - k];
	}
	return r;
}
 

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
[����]	����ֵ������ţ�ٲ�ֵ
[����]	����ֵ��x���ݣ���ֵ��y���ݣ���ֵ����������Ƶ�xֵ
[����ֵ]����ֵ�����ڹ��Ƶ㴦�ĺ���ֵ
[�쳣]	����
****************************/
inline double NewtonPolynomial(double x[], double y[], int n, double gx) 
{
	using pointer = double*;
	pointer* dy = new pointer[n];

	//Ϊ��ֱ����ռ�
	for (int i = 0; i < n; i++) {
		dy[i] = new double[n - i];
	}

	//Ϊ����ͳһ��������y0���Ƶ�dy�ĵ�0��
	for (int i = 0; i < n; i++) {
		dy[0][i] = y[i];
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			//ÿһ�����̵������ڵ�ǰһ������֮����Զ�Ӧ��xֵ
			dy[i][j] = (dy[i - 1][j + 1] - dy[i - 1][j]) / (x[j + i] - x[j]);
		}
	}

	//���ֵ����ÿһ��������0��Ԫ�ص�ֵ����Ӧ�Ķ���ʽ���
	double gy = y[0];
	for (int i = 1; i < n; i++) {
		double ty = 1;
		for (int j = 0; j < i; j++) {
			ty *= (gx - x[j]);
		}
		gy += dy[i][0] * ty;
	}

	for (int i = 0; i < n; i++) {
		delete[] dy[i];
	}
	delete[] dy;

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

	for (int k = 0; k < n; k++) {
		x += h / 2;
		S += 4 * f(x);
		x += h / 2;
		S += 2 * f(x);
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
[����]	����ֵ���֣������񷽷�
[����]	���������ޣ��������ޣ����־��ȣ����ֺ���
[����ֵ]��ָ�������ϵĻ��ֽ��
[�쳣]	����
****************************/
template<typename Fun>
inline double RombrgMethod(double a, double b, double e, Fun f)
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
[����]  ���˷����򾫶Ƚϵͣ�������ʹ��
****************************/
template<typename Fun>
inline void EulerMethod(Fun f, double x0, double y0, double h, double N)
{
	int n = 1;
	double x1, y1;
	do {
		x1 = x0 + h;
		y1 = y0 + h*f(x0, y0);
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
[����]	����΢�ַ�����ֵ��⣬�Ľ�ŷ������
[����]	��f������x��y�ĺ�����x0��y0����ʼֵ��h��������N���������
[����ֵ]����
[�쳣]	����
****************************/
template<typename Fun>
inline void ImprvEulerMethod(Fun f, double x0, double y0, double h, double N) 
{
	double x1,yp,yc,y1;
	for (int n = 0; n < N; n++, x0 = x1, y0 = y1) {
		x1 = x0 + h;
		yp = y0 + h*f(x0, y0);
		yc = y0 + h*f(x1, yp);
		y1 = (yp + yc) / 2;
		printf("%.4f %.4f\n", x1, y1);
	}
}


/***************************
[����]	����΢�ַ�����ֵ��⣬�Ľ������������
[����]	��f��΢�ֱ��ʽ������x0��y0����ʼֵ��h��������N���������
[����ֵ]����
[�쳣]	����
****************************/
template<typename Fun>
inline void RungeKuttaMethod4(Fun f, double x0, double y0, double h, double N) 
{
	double x1, y1, K1, K2, K3, K4;
	for (int n = 0; n < N; n++, x0 = x1, y0 = y1) {
		x1 = x0 + h;

		K1 = f(x0, y0);
		K2 = f(x0 + h / 2, y0 + h*K1 / 2);
		K3 = f(x0 + h / 2, y0 + h*K2 / 2);
		K4 = f(x1, y0 + h*K3);

		y1 = y0 + (K1 + 2 * K2 + 2 * K3 + K4)*h / 6;

		printf("%.4f %.4f\n", x1, y1);
	}
}


/***************************
[����]	����΢�ַ�������ֵ��⣬�Ľ������������
[����]	��f, g��΢�ֱ��ʽ������x0, y0, z0����ʼֵ��h��������N���������
[����ֵ]����
[�쳣]	����
****************************/
template<typename Fun1,typename Fun2>
inline void RungeKuttaMethod4(Fun1 f, Fun2 g, double x0, double y0, double z0, double h, double N)
{
	int n = 1;
	double x1, y1, z1;
	double K1, K2, K3, K4;
	double L1, L2, L3, L4;
	do
	{
		x1 = x0 + h;

		K1 = f(x0, y0,z0);
		L1 = g(x0, y0, z0);

		K2 = f(x0 + h / 2, y0 + h*K1 / 2, z0 + h*L1 / 2);
		L2 = g(x0 + h / 2, y0 + h*K1 / 2, z0 + h*L1 / 2);

		K3 = f(x0 + h / 2, y0 + h*K2 / 2, z0 + h*L2 / 2);
		L3 = g(x0 + h / 2, y0 + h*K2 / 2, z0 + h*L2 / 2);

		K4 = f(x1, y0 + h*K3, z0 + h*L3);
		L4 = g(x1, y0 + h*K3, z0 + h*L3);

		y1 = y0 + (K1 + 2 * K2 + 2 * K3 + K4)*h / 6;
		z1 = z0 + (L1 + 2 * L2 + 2 * L3 + L4)*h / 6;

		printf("%.4f %.4f %.4f\n", x1, y1,z1);

		if (n == N) {
			break;
		}
		else {
			n++;
			x0 = x1; y0 = y1; z0 = z1;
		}
	} while (true);
}


/***************************
[����]	�����׳�΢�ַ�����ֵ��⣬�Ľ������������
[����]	��f��΢�ֱ��ʽ������x0��y0����ʼֵ��h��������N���������
[����ֵ]����
[�쳣]	����
****************************/
template<typename Fun>
inline void RungeKuttaMethod2th4(Fun f, double x0, double y0, double z0, double h, double N)
{
	int n = 1;
	double x1, y1,z1;
	
	double L1, L2, L3, L4;
	do
	{
		x1 = x0 + h;

		L1 = f(x0, y0, z0);
		L2 = f(x0 + h / 2, y0 + h*z0 / 2, z0 + h*L1 / 2);
		L3 = f(x0 + h / 2, y0 + h*z0 / 2 + h*h*L1 / 4, z0 + h*L2 / 2);
		L4 = f(x0 + h, y0 + h*z0 + h*h*L2 / 2, z0 + h*L3);

		y1 = y0 + h*z0 + (L1 + L2 + L3)*h*h / 6;
		z1 = z0 + (L1 + 2 * L2 + 2 * L3 + L4)*h / 6;
		printf("%.4f %.4f\n", x1, y1);

		if (n == N) {
			break;
		}
		else {
			n++;
			x0 = x1; y0 = y1; z0 = z1;
		}
	} while (true);
}


/***************************
[����]	����΢�ַ�����ֵ��⣬�ǵ�ķ˹Ԥ��-У��ϵͳ
[����]	��f������x��y�ĺ�����x0��y0����ʼֵ��h��������N���������
[����ֵ]����
[�쳣]	����
****************************/
template<typename Fun>
inline void AdamsMethod4(Fun f, double x0, double y0, double h, double N)
{
	double x[5]; double y[5];
	x[0] = x0; y[0] = y0;

	int n = 1;
	double xi, yi, K1, K2, K3, K4;
	do
	{
		xi = x0 + h;

		K1 = f(x0, y0);
		K2 = f(x0 + h / 2, y0 + h*K1 / 2);
		K3 = f(x0 + h / 2, y0 + h*K2 / 2);
		K4 = f(xi, y0 + h*K3);

		yi = y0 + (K1 + 2 * K2 + 2 * K3 + K4)*h / 6;

		x[n] = xi;
		y[n] = yi;

		if (n == 3) {
			break;
		}
		else {
			n++;
			x0 = xi; y0 = yi;
		}
	} while (true);
	
	double dy[5];
	for (int i = 0; i < 4; i++) {
		dy[i] = f(x[i], y[i]);
	}

	for (int i = 0; i < 4; i++) {
		printf("%.4f\t%.4f\n", x[i], y[i]);
	}

	n = 4;

	double yp, dyp;
	do
	{
		x[4] = x[3] + h;
		yp = y[3] + h*(55 * dy[3] - 59 * dy[2] + 37 * dy[1] - 9 * dy[0]) / 24;
		dyp = f(x[4], yp);
		y[4] = y[3] + h*(9 * dyp + 19 * dy[3] - 5 * dy[2] + dy[1]) / 24;
		dy[4] = f(x[4], y[4]);
		printf("%.4f\t%.4f\n", x[4], y[4]);

		if (n == N) {
			break;
		}
		else {
			n++;
			x[3] = x[4];
			y[3] = y[4];

			for (int k = 0; k < 4; k++) {
				dy[k] = dy[k + 1];
			}
		}
	} while (true);


}

/***************************
[����]	�����ַ��󷽳̸�
[����]	��f������������a��b������˵�ֵ��e������
[����ֵ]���������ֵ
[�쳣]	����
****************************/
template<typename Fun>
inline double dichotomy(Fun f, double a, double b, double e)
{
	double y0 = f(a);
	double x, y;

	do
	{
		x = (a + b) / 2;
		y = f(x);
		if (y*y0 > 0) {
			a = x;
		}
		else {
			b = x;
		}

		if (b - a < e) {
			break;
		}
	} while (true);
	return x;
}


/***************************
[����]	���������󷽳̸�
[����]	��f������������x��ʼ���Ƶ�
[����ֵ]���������ֵ
[�쳣]	��������������������׳�logic_error�쳣
****************************/
template<typename Fun>
inline double mathIter(Fun f, double x,double e = 0.0000001,int N = 10000000)
{
	int k;
	double x1, x0;

	for (k = 1,x0 = x, x1 = f(x0); abs(x1 - x0) >= e; k++, x0 = x1, x1 = f(x0)) {
		if (k == N) {
			throw std::logic_error("�ﵽ��������������δ�ܵ��ﾫ��Ҫ��");
		}
		//printf("%.4f ", x1);
	}

	return x1;
}


/***************************
[����]	���������󷽳̸�,���ؽ���ٷ���
[����]	��f������������x0��ʼ���Ƶ�
[����ֵ]���������ֵ
[�쳣]	��������������������׳�logic_error�쳣
****************************/
template<typename Fun>
inline double AitkenIter(Fun f, double x0, double e = 0.0000001, int N = 10000000)
{
	int k = 1;
	double x1, x2;

	do
	{
		x1 = f(x0);
		x2 = f(x1);
		x2 = x2 - (x2 - x1)*(x2 - x1) / (x2 - 2 * x1 + x0);
		if (abs(x1 - x2) < e) {
			break;
		}
		else if (k == N) {
			throw std::logic_error("�ﵽ��������������δ�ܵ��ﾫ��Ҫ��");
		}
		else {
			k++;
			x0 = x2;
		}
	} while (true);

	return x2;
}


/***************************
[����]	���������󷽳̸�,ţ�ٷ�
[����]	��f��������Df����������x0��ʼ���Ƶ�
[����ֵ]���������ֵ
[�쳣]	�������������������ֵΪ�㣬���׳�logic_error�쳣
****************************/
template<typename Fun1,typename Fun2>
inline double NewtonMethod(Fun1 f, Fun2 Df, double x0, double e = 0.0000001, int N = 1000000)
{
	double x1;
	for (int k = 0; k < N; k++, x0 = x1) {
		if (Df(x0) == 0) {
			throw std::logic_error("��������ֵΪ��");
		}

		x1 = x0 - f(x0) / Df(x0);
		if (abs(x1 - x0) < e) {
			return x1;
		}
	}
	throw std::logic_error("�ﵽ��������������δ�ܵ��ﾫ��Ҫ��");
}


/***************************
[����]	���������󷽳̸�,�����ҽط�
[����]	��f��������x0��x1����ʼ���Ƶ�
[����ֵ]���������ֵ
[�쳣]	��������������������׳�logic_error�쳣
****************************/
template<typename Fun>
inline double qSecantMethod(Fun f, double x0,double x1, double e = 0.0000001, int N = 1000000)
{
	int k = 1;
	double x2;
	do
	{
		x2 = x1 - f(x1) / (f(x1) - f(x0))*(x1 - x0);
		if (abs(x1 - x0) < e) {
			break;
		}

		if (k == N) {
			throw std::logic_error("�ﵽ��������������δ�ܵ��ﾫ��Ҫ��");
		}

		k++;
		x0 = x1; x1 = x2;
		//printf("%.4f ", x2);
	} while (true);

	return x2;
}

/***************************
[����]	���������󷽳���,�ſ˱ȵ�����ʽ
[����]	��A��ϵ������b���Ҳ�ֵ������ansewr�����淵�ؽ�������飻e:���㾫�ȣ�N������������
[����ֵ]���ޣ�ͨ��answer���ؽ������
[�쳣]	��������������������׳�logic_error�쳣
****************************/
template<unsigned n>
inline void JacobiMethod(double A[][n], double* b, double* ansewr, double e = 0.00001,double N = 1000000)
{
	double* x = new double[n];
	double* y = new double[n];

	for (int i = 0; i < n; i++) {
		x[i] = y[i] = 0;
	}

	int k = 1;
	do
	{
		for (int i = 0; i < n; i++) {
			double temp = 0;
			for (int j = 0; j < n; j++) {
				if (j != i) {
					temp += A[i][j]*x[j];
				}
			}
			y[i] = (b[i] - temp) / A[i][i];
		}

		bool needReturn = true;
		for (int i = 0; i < n; i++) {
			if (abs(x[i] - y[i]) >= e) {
				needReturn = false;
				break;
			}
		}

		if (needReturn) {
			break;
		}

		if (k == N) {
			throw std::logic_error("�ﵽ��������������δ�ܵ��ﾫ��Ҫ��");
			//�����ڴ�й¶�ķ���
		}
		else {
			k++;
			for(int i=0;i<n;i++){
				x[i] = y[i];
			}
		}
		
	} while (true);

	for (int i = 0; i < n; i++) {
		ansewr[i] = y[i];
	}

	delete[] x;
	delete[] y;
}

/***************************
[����]	���������󷽳���,��˹-���¶�������ʽ
[����]	��A��ϵ������b���Ҳ�ֵ������ansewr�����淵�ؽ�������飻e:���㾫�ȣ�N������������
[����ֵ]���ޣ�ͨ��answer���ؽ������
[�쳣]	��������������������׳�logic_error�쳣
****************************/
template<unsigned n>
inline void GaussSeidelMethod(double A[][n], double* b, double* ansewr, double e = 0.00001, double N = 1000000)
{
	double* x = new double[n];
	double* y = new double[n];

	for (int i = 0; i < n; i++) {
		x[i] = y[i] = 0;
	}

	int k = 1;
	do
	{
		for (int i = 0; i < n; i++) {
			double temp = 0;
			for (int j = 0; j < n; j++) {
				if (j != i) {
					temp += A[i][j] * x[j];
				}
			}
			x[i] = (b[i] - temp) / A[i][i];
		}

		bool needReturn = true;
		for (int i = 0; i < n; i++) {
			if (abs(x[i] - y[i]) >= e) {
				needReturn = false;
				break;
			}
		}

		if (needReturn) {
			break;
		}

		if (k == N) {
			throw std::logic_error("�ﵽ��������������δ�ܵ��ﾫ��Ҫ��");
		}
		else {
			k++;
			for (int i = 0; i<n; i++) {
				y[i] = x[i];
			}
		}

	} while (true);

	for (int i = 0; i < n; i++) {
		ansewr[i] = y[i];
	}

	delete[] x;
	delete[] y;
}

/***************************
[����]	����ȥ���󷽳���,Լ����ȥ��ʽ
[����]	��A��ϵ������b���Ҳ�ֵ������
[����ֵ]���ޣ�ͨ��b���ؽ������
[�쳣]	����
****************************/
template<unsigned n>
inline void JordanMethod(double A[][n], double* b)
{
	int k = 0;

	for (int k = 0; k < n; k++) {
		for (int j = k + 1; j < n; j++) {
			A[k][j] /= A[k][k];	
		}
		b[k] /= A[k][k];

		for (int i = 0; i < n; i++) {
			if (i != k)
			{
				for (int j = k + 1; j < n; j++) {
					A[i][j] -= (A[i][k] * A[k][j]);
				}
				b[i] -= (A[i][k] * b[k]);
			}
		}

	}
}

/***************************
[����]	����ȥ���󷽳���,��˹��ȥ��ʽ
[����]	��A��ϵ������b���Ҳ�ֵ������
[����ֵ]���ޣ�ͨ��b���ؽ������
[�쳣]	���޷�ѡ����ʵ���Ԫ���׳�logic_error�쳣
****************************/
template<unsigned n>
inline void GaussMethod(double A[][n], double* b)
{
	for (int k = 0; k < n; k++) {
		//ѡ��Ԫ��
		double d = A[k][k];
		int l = k;
		int i = k + 1;

		for (int i = k + 1; i < n; i++) {
			if (abs(A[i][k]) > d) {
				d = A[i][k];
				l = i;
			}
		}

		if (d == 0) {
			throw std::logic_error("�޷�ѡ�������Ԫ");
		}

		if (l != k) {
			for (int j = k; j < n; j++) {
				std::swap(A[l][j], A[k][j]);
			}
			std::swap(b[k], b[l]);
		}

			

		//����
		for (int j = k + 1; j < n; j++) {
			A[k][j] /= A[k][k];
		}
		b[k] /= A[k][k];

		for (int i = k + 1; i < n; i++) {
			for (int j = k + 1; j < n; j++) {
				A[i][j] -= (A[i][k] * A[k][j]);
			}
			b[i] -= (A[i][k] * b[k]);
		}
	}

	//�ش�
	for (int i = n - 2; i >= 0; i--) {
		for (int j = i + 1; j < n; j++) {
			b[i] -= (A[i][j] * b[j]);
		}
	}
}

