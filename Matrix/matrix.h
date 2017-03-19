#pragma once

#include <vector>
#include <iostream>
#include <fstream>
#include <cstdio>
#include "DynamicMatrix.h"

template<typename T,unsigned rows,unsigned cols>
class Matrix
{
public:
	Matrix();
	//从一个动态矩阵上构造固定大小的矩阵同时也可以实现两者的之间转化
	//既然需要能够从一个类型转化为另外一个类型，要么使用友元，要不就只能暴露接口了
	//鉴于C++本身的复杂性，以及耦合性的考虑，应该使用后者
	//虽然动态性很好，但是这里毕竟本质上是一个固定大小的矩阵
	//对于会改变大小的操作，恐怕还有一些问题
	Matrix(const DynamicMatrix<T> & matrix);

	unsigned int getRowNum() { return rows; }
	unsigned int getColNum() { return cols; }


	~Matrix();
public:
	Matrix<T, rows, cols> operator+(Matrix<T, rows, cols> &rl);
	Matrix<T, rows, cols> operator-(Matrix<T, rows, cols> &rl);


	//迷之模板套模板，也不知道能不能成功实例化，但是如果可以的话，之后的运算就不在需要动态类了
	template<unsigned int brows,unsigned int bcols>
	Matrix<T, rows, bcols> operator*(Matrix<T, brows, bcols> &rl);

private:
	T(*data)[cols];
	
};

template<typename T, unsigned rows, unsigned cols>
inline Matrix<T, rows, cols>::Matrix()
{
	data = new T[rows][cols];
}

template<typename T, unsigned rows, unsigned cols>
inline Matrix<T, rows, cols>::Matrix(const DynamicMatrix<T> & matrix): Matrix()
{
	if (matrix.content.size() < rows) {
		//return 
	}
	else if (matrix.content[0].size() < cols) {
		//return;
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			data[i][j] = matrix.content[i][j];
		}
	}
}

template<typename T, unsigned rows, unsigned cols>
inline Matrix<T, rows, cols>::~Matrix()
{
	//经过内存快照测试，确实可以释放内存
	delete[] data;
}

template<typename T, unsigned rows, unsigned cols>
template<unsigned int brows, unsigned int bcols>
inline Matrix<T, rows, bcols> Matrix<T, rows, cols>::operator*(Matrix<T, brows, bcols>& rl)
{
	//标准的右值，需要实现相关的移动赋值和构造函数
	Matrix<T, rows, bcols> rtn;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < bcols; j++) {

		}
	}
}
