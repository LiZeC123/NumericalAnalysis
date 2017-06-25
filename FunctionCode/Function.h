#pragma once
#include <stdexcept>


/***************************
[函数]	：计算多项式的值，秦九韶算法
[参数]	：coe：系数数组；N：最高项次数；x：自变量值
[返回值]：多项式的值
[异常]	：无
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
[函数]	：插值方法，拉格朗日插值
[参数]	：插值点x数据；插值点y数据，插值点个数，估计点x值
[返回值]：插值函数在估计点处的函数值
[异常]	：无
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
[函数]	：插值方法，牛顿插值
[参数]	：插值点x数据；插值点y数据，插值点个数，估计点x值
[返回值]：插值函数在估计点处的函数值
[异常]	：无
****************************/
inline double NewtonPolynomial(double x[], double y[], int n, double gx) 
{
	using pointer = double*;
	pointer* dy = new pointer[n];

	//为差分表分配空间
	for (int i = 0; i < n; i++) {
		dy[i] = new double[n - i];
	}

	//为便于统一操作，将y0复制到dy的第0行
	for (int i = 0; i < n; i++) {
		dy[0][i] = y[i];
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			//每一级差商等于相邻的前一级差商之差除以对应的x值
			dy[i][j] = (dy[i - 1][j + 1] - dy[i - 1][j]) / (x[j + i] - x[j]);
		}
	}

	//最后值等于每一级差商中0号元素的值与相应的多项式相乘
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
[函数]	：数值积分，复化辛普森公式
[参数]	：积分下限；积分上限；函数点个数；积分函数
[返回值]：指定区间上的积分值
[异常]	：无
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
[函数]	：数值积分，梯形法
[参数]	：积分下限；积分上限；积分精度；积分函数
[返回值]：指定区间上的积分结果
[异常]	：无
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
[函数]	：数值积分，龙贝格方法
[参数]	：积分下限；积分上限；积分精度；积分函数
[返回值]：指定区间上的积分结果
[异常]	：无
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
[函数]	：常微分方程数值求解，欧拉方法
[参数]	：f：关于x和y的函数；x0，y0：初始值；h：步长；N：计算点数
[返回值]：无
[异常]	：无
[其他]  ：此方法因精度较低，不建议使用
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
[函数]	：常微分方程数值求解，改进欧拉方法
[参数]	：f：关于x和y的函数；x0，y0：初始值；h：步长；N：计算点数
[返回值]：无
[异常]	：无
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
[函数]	：常微分方程数值求解，四阶龙格库塔方法
[参数]	：f：微分表达式函数；x0，y0：初始值；h：步长；N：计算点数
[返回值]：无
[异常]	：无
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
[函数]	：常微分方程组数值求解，四阶龙格库塔方法
[参数]	：f, g：微分表达式函数；x0, y0, z0：初始值；h：步长；N：计算点数
[返回值]：无
[异常]	：无
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
[函数]	：二阶常微分方程数值求解，四阶龙格库塔方法
[参数]	：f：微分表达式函数；x0，y0：初始值；h：步长；N：计算点数
[返回值]：无
[异常]	：无
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
[函数]	：常微分方程数值求解，亚当姆斯预报-校正系统
[参数]	：f：关于x和y的函数；x0，y0：初始值；h：步长；N：计算点数
[返回值]：无
[异常]	：无
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
[函数]	：二分法求方程根
[参数]	：f：迭代函数；a，b：区间端点值；e：精度
[返回值]：迭代结果值
[异常]	：无
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
[函数]	：迭代法求方程根
[参数]	：f：迭代函数；x初始估计点
[返回值]：迭代结果值
[异常]	：迭代结果不收敛，则抛出logic_error异常
****************************/
template<typename Fun>
inline double mathIter(Fun f, double x,double e = 0.0000001,int N = 10000000)
{
	int k;
	double x1, x0;

	for (k = 1,x0 = x, x1 = f(x0); abs(x1 - x0) >= e; k++, x0 = x1, x1 = f(x0)) {
		if (k == N) {
			throw std::logic_error("达到最大迭代次数，且未能到达精度要求");
		}
		//printf("%.4f ", x1);
	}

	return x1;
}


/***************************
[函数]	：迭代法求方程根,艾特金加速方法
[参数]	：f：迭代函数；x0初始估计点
[返回值]：迭代结果值
[异常]	：迭代结果不收敛，则抛出logic_error异常
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
			throw std::logic_error("达到最大迭代次数，且未能到达精度要求");
		}
		else {
			k++;
			x0 = x2;
		}
	} while (true);

	return x2;
}


/***************************
[函数]	：迭代法求方程根,牛顿法
[参数]	：f：函数；Df：导函数；x0初始估计点
[返回值]：迭代结果值
[异常]	：迭代结果不收敛或导数值为零，则抛出logic_error异常
****************************/
template<typename Fun1,typename Fun2>
inline double NewtonMethod(Fun1 f, Fun2 Df, double x0, double e = 0.0000001, int N = 1000000)
{
	double x1;
	for (int k = 0; k < N; k++, x0 = x1) {
		if (Df(x0) == 0) {
			throw std::logic_error("函数导数值为零");
		}

		x1 = x0 - f(x0) / Df(x0);
		if (abs(x1 - x0) < e) {
			return x1;
		}
	}
	throw std::logic_error("达到最大迭代次数，且未能到达精度要求");
}


/***************************
[函数]	：迭代法求方程根,快速弦截法
[参数]	：f：函数；x0，x1：初始估计点
[返回值]：迭代结果值
[异常]	：迭代结果不收敛，则抛出logic_error异常
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
			throw std::logic_error("达到最大迭代次数，且未能到达精度要求");
		}

		k++;
		x0 = x1; x1 = x2;
		//printf("%.4f ", x2);
	} while (true);

	return x2;
}

/***************************
[函数]	：迭代法求方程组,雅克比迭代公式
[参数]	：A：系数矩阵；b：右侧值向量；ansewr：保存返回结果的数组；e:计算精度；N：最大迭代次数
[返回值]：无，通过answer返回结果向量
[异常]	：迭代结果不收敛，则抛出logic_error异常
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
			throw std::logic_error("达到最大迭代次数，且未能到达精度要求");
			//存在内存泄露的风险
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
[函数]	：迭代法求方程组,高斯-赛德尔迭代公式
[参数]	：A：系数矩阵；b：右侧值向量；ansewr：保存返回结果的数组；e:计算精度；N：最大迭代次数
[返回值]：无，通过answer返回结果向量
[异常]	：迭代结果不收敛，则抛出logic_error异常
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
			throw std::logic_error("达到最大迭代次数，且未能到达精度要求");
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
[函数]	：消去法求方程组,约当消去公式
[参数]	：A：系数矩阵；b：右侧值向量；
[返回值]：无，通过b返回结果向量
[异常]	：无
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
[函数]	：消去法求方程组,高斯消去公式
[参数]	：A：系数矩阵；b：右侧值向量；
[返回值]：无，通过b返回结果向量
[异常]	：无法选择合适的主元，抛出logic_error异常
****************************/
template<unsigned n>
inline void GaussMethod(double A[][n], double* b)
{
	for (int k = 0; k < n; k++) {
		//选主元素
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
			throw std::logic_error("无法选择非零主元");
		}

		if (l != k) {
			for (int j = k; j < n; j++) {
				std::swap(A[l][j], A[k][j]);
			}
			std::swap(b[k], b[l]);
		}

			

		//消除
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

	//回代
	for (int i = n - 2; i >= 0; i--) {
		for (int j = i + 1; j < n; j++) {
			b[i] -= (A[i][j] * b[j]);
		}
	}
}

