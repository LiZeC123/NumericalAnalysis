#pragma once
#include <iostream>

#include "Math_Function.h"
//������

class Fraction
{
public:
	Fraction() = default;
	Fraction(int m, int d) : mem(m), den(d) {};

public:
	//��ʾһ������
	Fraction & ShowFraction();

private:
	int mem = 1;		//���� 
	int den = 1;		//��ĸ 

	//�������������
	void Reduce();
};
