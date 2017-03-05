#include "Polynomial.h"
#include <iostream>


int main()
{
	Polynomial<double, int> p;
	p.append(PolyNode<double,int>(1.33, 1));
	p.append(PolyNode<double, int>(2, 5));
	p.append(PolyNode<double, int>(32, -1));
	p.display();
	p.sort();
	std::cout << std::endl;
	p.display();

	p.visit([](PolyNode<double,int> & poly)-> void {poly.coe *= poly.exp; poly.exp -= 1; });
	p.display();


	return 0;
}