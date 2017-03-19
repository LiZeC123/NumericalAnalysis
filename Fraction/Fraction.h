#pragma once
#include <iostream>
#include <stdexcept>
#include <string>

//������
class Fraction
{
	friend std::ostream & operator<<(std::ostream& os, const Fraction & frac);
	friend Fraction operator-(Fraction frac);

public:
	Fraction() = default;
	Fraction(long long int m, long long int d);
	Fraction(long long int n);

public:
	bool operator==(const Fraction &rfr) const;
	bool operator!=(const Fraction &rfr) const;
	bool operator<(const Fraction &rfr) const;
	bool operator>(const Fraction &rfr) const;
	bool operator<=(const Fraction &rfr) const;
	bool operator>=(const Fraction &rfr) const;

	Fraction operator+(const Fraction &rfr) const;
	Fraction operator-(const Fraction &rfr) const;
	Fraction operator*(const Fraction &rfr) const;
	Fraction operator/(const Fraction &rfr) const;

	Fraction& operator+=(const Fraction &rfr);
	Fraction& operator-=(const Fraction &rfr);
	Fraction& operator*=(const Fraction &rfr);
	Fraction& operator/=(const Fraction &rfr);

	Fraction& operator++();
	Fraction& operator--();

	Fraction operator++(int);
	Fraction operator--(int);

public:
	double printWithDouble();

private:
	int sign = 1;				//����
	long long int mem = 1;		//���� 
	long long int den = 1;		//��ĸ 

	//�������������
	void Reduce();
};


class den_is_zero : public std::runtime_error {
public:
	den_is_zero(std::string & msg) :runtime_error(msg) {};
};