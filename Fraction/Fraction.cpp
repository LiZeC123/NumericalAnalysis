#include "Fraction.h"

//相关的数学函数
static int gcd(long long int a, long long int b);


double Fraction::printWithDouble()
{
	double ret = mem / den;
	return ret;
}

inline void Fraction::Reduce()
{
	long long int gcdnum = gcd(mem, den);
	mem /= gcdnum;
	den /= gcdnum;
}

static int gcd(long long int a, long long int b)
{
	int r;
	while (b != 0)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

std::ostream & operator<<(std::ostream& os,const Fraction & frac)
{
	if (frac.sign == -1) {
		os << "-";
	}
	if (frac.den == 1) {
		std::cout << frac.mem;
	}
	else {
		std::cout << frac.mem << "/" << frac.den;
	}

	return os;
}
Fraction operator-(Fraction frac)
{
	frac.sign = -frac.sign;
	return frac;
}

Fraction::Fraction(long long int m, long long int d)
{
	if (m < 0) {
		m = -m;
		sign = -sign;
	}
	if (d < 0) {
		d = -d;
		sign = -sign;
	}

	mem = m;
	den = d;

	this->Reduce();
}

Fraction::Fraction(long long int n)
{
	if (n < 0) {
		sign = -sign;
		mem = - n;
	}
	else {
		mem = n;
	}
}

bool Fraction::operator==(const Fraction & rfr) const 
{
	if (sign == rfr.sign && rfr.den * mem == rfr.mem * den) {
		return true;
	}
	return false;
}

bool Fraction::operator!=(const Fraction & rfr) const 
{
	return !(*this == rfr);
}

bool Fraction::operator<(const Fraction & rfr) const 
{
	if (sign == 1 && rfr.sign == 1) {
		return mem * rfr.den < den * rfr.mem;
	}
	if (sign == -1 && rfr.sign == -1) {
		return !(mem * rfr.den < den * rfr.mem);
	}
	if (sign == 1 && rfr.sign == -1) {
		return false;
	}
	if (sign == -1 && rfr.sign == 1) {
		return true;
	}
	
}

bool Fraction::operator>(const Fraction & rfr) const 
{
	return !((*this) < rfr || (*this) == rfr);
}

bool Fraction::operator<=(const Fraction & rfr) const
{
	return ((*this) < rfr || (*this) == rfr);
}

bool Fraction::operator>=(const Fraction & rfr) const
{
	return !((*this) < rfr);
}

Fraction Fraction::operator+(const Fraction & rfr) const
{
	Fraction ret;

	ret.den = den * rfr.den;
	ret.mem = sign * mem * rfr.den + rfr.sign * rfr.mem * den;


	if (ret.mem < 0) {
		ret.mem = -ret.mem;
		ret.sign = -1;
	}

	ret.Reduce();
	return ret;
}

Fraction Fraction::operator-(const Fraction & rfr) const
{
	Fraction ret;

	ret.den = den * rfr.den;
	ret.mem = sign *  mem * rfr.den - rfr.sign * rfr.mem * den;
	
	if (ret.mem < 0) {
		ret.mem = -ret.mem;
		ret.sign = -1;
	}

	ret.Reduce();
	return ret;
}

inline Fraction Fraction::operator*(const Fraction & rfr) const
{
	Fraction ret(mem * rfr.mem, den * rfr.den);
	ret.sign = sign * rfr.sign;
	ret.Reduce();
	return ret;
}

inline Fraction Fraction::operator/(const Fraction & rfr) const
{
	Fraction ret(mem * rfr.den, den*rfr.mem);
	ret.sign = sign * rfr.sign;
	ret.Reduce();
	return ret;
}

Fraction & Fraction::operator+=(const Fraction & rfr) 
{
	(*this) = (*this) + rfr;
	return *this;
}

Fraction & Fraction::operator-=(const Fraction & rfr) 
{
	(*this) = (*this) - rfr;
	return *this;
}

Fraction & Fraction::operator*=(const Fraction & rfr) 
{
	(*this) = (*this) * rfr;
	return *this;
}

Fraction & Fraction::operator/=(const Fraction & rfr) 
{
	(*this) = (*this) / rfr;
	return *this;
}

Fraction & Fraction::operator++()
{
	if (sign > 0) {
		++mem;
	}
	else {
		--mem;
	}
	return *this;
}

Fraction & Fraction::operator--()
{
	if (sign > 0) {
		--mem;
	}
	else {
		++mem;
	}
	return *this;
}

Fraction Fraction::operator++(int)
{
	Fraction ret = *this;
	++(*this);
	return ret;
}

Fraction Fraction::operator--(int)
{
	Fraction ret = *this;
	--(*this);
	return ret;
}





