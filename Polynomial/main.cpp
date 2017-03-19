#include "Polynomial.h"
#include "../Fraction/Fraction.h"
#include <iostream>


int main()
{
	Polynomial<double, int> p;
	Polynomial<double, Fraction> pf;

	p.append(PolyNode<double,int>(1.33, 1));
	p.append(PolyNode<double, int>(2, 5));
	p.append(PolyNode<double, int>(32, -1));

	pf.append(1.34, Fraction(4, 3));
	pf.append(2.33, Fraction(3));

	pf.display();

	////p.display();

	//p.sort();
	//std::cout << std::endl;
	//p.display();

	//p.visit([](PolyNode<double,int> & poly)-> void {poly.coe *= poly.exp; poly.exp -= 1; });
	//p.display();


	return 0;
}