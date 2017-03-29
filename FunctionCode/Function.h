#pragma once

//拉格朗日插值
void Lagrange_polynomial();


inline double Lagrange_polynomial(double x[], double y[], int n, double gx)
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


template<typename Func>
inline double Compound_Simpson(double a, double b, int n, Func f)
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

template<typename Fun>
inline double Romberg(double a, double b, double d, Fun f)
{
	double h = b - a;
	double T1 = h * (f(b) - f(a)) / 2;
	int k = 1;
	double S, S1, S2, T2, C1, C2, R1, R2;
	do {
	BEGIN:
		S = 0;
		double x = a + h / 2;
		do {
			S += f(x);
			x += h;
		} while (x < b);

		T2 = T1 / 2 + S*h / 2;

		S2 = T2 + (T2 - T1) / 3;
		if (k == 1) {
			k += 1;
			h /= 2;
			T1 = T2;
			S1 = S2;
			goto BEGIN;
		}
		C2 = S2 + (S2 - S1) / 15;
		if (k == 2) {
			C1 = C2;
			k += 1;
			h /= 2;
			T1 = T2;
			S1 = S2;
			goto BEGIN;
		}
		R2 = C2 + (C2 - C1) / 63;
		if (k == 3) {
			R1 = R2;
			C1 = C2;
			k += 1;
			h /= 2;
			T1 = T2;
			S1 = S2;
			goto BEGIN;
		}
	} while (abs(R2-R1)>d);

	return R2;
}
