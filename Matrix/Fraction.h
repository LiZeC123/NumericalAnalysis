#pragma once
#include <iostream>

#include "Math_Function.h"
//分数类

class Fraction
{
public:
	Fraction() = default;
	Fraction(int m, int d) : mem(m), den(d) {};

public:
	//显示一个分数
	Fraction & ShowFraction();

private:
	int mem = 1;		//分子 
	int den = 1;		//分母 

	//将分数化简到最简
	void Reduce();
};
