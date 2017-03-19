//#ifndef MATRIX_H
//#define MATRIX_H
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdio>
//
////#include "../Fraction/Fraction.h"
////#include "Math_Function.h"
////#include "Matrix_Exception.h"
////#include "../Multionmial/Multionmial.h"
//


//
//
//
///*                            异常声明部分                          */
//
//#include <stdexcept>
//#include <string>
//
//class matrix_mismatch : public std::logic_error
//{
//public:
//	matrix_mismatch(const std::string & s) :
//		std::logic_error(s) { };
//};
//
///*                            重载运算符部分                          */
//
//DynamicMatrix operator+(DynamicMatrix & lmx, DynamicMatrix & rmx);
//
//DynamicMatrix operator-(DynamicMatrix & lmx, DynamicMatrix & rmx);
//
//DynamicMatrix operator*(DynamicMatrix & lmx, DynamicMatrix & rmx);
//
//DynamicMatrix operator*(int C, DynamicMatrix & rmx);
//
//
//#endif



template<typename T,unsigned rows,unsigned cols>
class Matrix
{
public:
	Matrix<T, rows, cols> operator+(Matrix<T, cols, rows> &rl);
	Matrix<T, rows, cols> operator-(Matrix<T, cols, rows> &rl);
	Matrix<T, rows, cols> operator*(Matrix<T, cols, rows> &rl);
public:
	Matrix();
	//从一个动态矩阵上构造固定大小的矩阵同时也可以实现两者的之间转化
	Matrix(const DynamicMatrix & matrix);
	~Matrix();
private:
	T(*data)[cols];
	
};

template<typename T, unsigned rows, unsigned cols>
inline Matrix<T, rows, cols>::Matrix()
{
	data = new T[rows][cols];
	std::cout << "finish new" << std::endl;
}

template<typename T, unsigned rows, unsigned cols>
inline Matrix<T, rows, cols>::~Matrix()
{
	std::cout << "begin delete" << std::endl;
	delete[] data;
}
