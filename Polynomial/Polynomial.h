#pragma once
#include <vector>
#include <algorithm>

template<typename COE_TYPE,typename EXP_TYPE>
class PolyNode
{
public:
	PolyNode(COE_TYPE coe, EXP_TYPE exp);
	COE_TYPE coe;
	EXP_TYPE exp;
};


template<typename COE_TYPE ,typename EXP_TYPE>
class Polynomial
{
public:
	Polynomial() = default;
	//Polynomial();

	void append(const PolyNode<COE_TYPE,EXP_TYPE>& node);
	void append(const COE_TYPE coe, const EXP_TYPE exp);

	template<typename Func> void visit(Func func);

	void sort();

	void display();

	void sortDisplay();
	
private:
	std::vector<PolyNode<COE_TYPE,EXP_TYPE>> data;
};

template<typename COE_TYPE, typename EXP_TYPE>
inline PolyNode<COE_TYPE, EXP_TYPE>::PolyNode(COE_TYPE coe, EXP_TYPE exp)
{
	this->coe = coe;
	this->exp = exp;
}

template<typename COE_TYPE, typename EXP_TYPE>
inline void Polynomial<COE_TYPE, EXP_TYPE>::append(const PolyNode<COE_TYPE, EXP_TYPE> & node)
{
	data.push_back(node);
}

template<typename COE_TYPE, typename EXP_TYPE>
inline void Polynomial<COE_TYPE, EXP_TYPE>::append(const COE_TYPE coe, const EXP_TYPE exp)
{
	data.push_back(PolyNode<COE_TYPE, EXP_TYPE>(coe, exp));
}

template<typename COE_TYPE, typename EXP_TYPE>
inline void Polynomial<COE_TYPE, EXP_TYPE>::sort()
{
	std::sort(data.begin(), data.end(), [](const PolyNode<COE_TYPE, EXP_TYPE> & a, const PolyNode<COE_TYPE, EXP_TYPE> & b)-> bool {return a.exp < b.exp; });
}

template<typename COE_TYPE, typename EXP_TYPE>
inline void Polynomial<COE_TYPE, EXP_TYPE>::display()
{
	for (const auto & i : data) {
		std::cout << i.coe << " " << i.exp << std::endl;
	}
}

template<typename COE_TYPE, typename EXP_TYPE>
inline void Polynomial<COE_TYPE, EXP_TYPE>::sortDisplay()
{
	sort();
	display();
}

template<typename COE_TYPE, typename EXP_TYPE>
template<typename Func>
inline void Polynomial<COE_TYPE, EXP_TYPE>::visit(Func func)
{
	for (auto & i : data) {
		func(i);
	}
}
