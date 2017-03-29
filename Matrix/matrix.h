#pragma once

#include <iostream>
#include <algorithm>
#include <cstdio>
#include "DynamicMatrix.h"

template<typename T,unsigned rows,unsigned cols>
class Matrix
{
public:
	Matrix();

	Matrix(const DynamicMatrix<T> & matrix);

	unsigned int getRowNum() { return rows; }
	unsigned int getColNum() { return cols; }

	//拷贝构造函数
	Matrix(const Matrix<T, rows, cols> & rhm);

	void temp_display()
	{
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				std::cout << (*this)[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}


	~Matrix();
public:
	Matrix<T, rows, cols> operator+(Matrix<T, rows, cols> &rl);
	Matrix<T, rows, cols> operator-(Matrix<T, rows, cols> &rl);


	//迷之模板套模板，也不知道能不能成功实例化，但是如果可以的话，之后的运算就不在需要动态类了
	//致命性问题：不同的参数实例化出来的类不一样，导致在此模板类上的模板函数存在匹配问题
	//此外，因为是不同的类，改变大小的二元运算符，均不能访问另外一个类中的private成员
	//大量使用改变大小的类将导致严重的代码膨胀问题

	template<unsigned int brows,unsigned int bcols>
	Matrix<T, rows, bcols> operator*(Matrix<T, brows, bcols> &rl);

	//返回内置的指针，从而实现具体的访问功能
	T * operator[](unsigned int i);
	const T * operator[](unsigned int i) const;

private:
	//定义[]运算符，间接访数据，从而避免直接暴露指针
	T(*data)[cols];
	
};

//template<typename T1, typename T2, unsigned r1, unsigned c1, unsigned r2, unsigned c2 >
//inline void swap(Matrix<T1, r1, c1>& lhm, Matrix<T2, r2, c2>& rhm)
//{
//	//通过将要交换的两个模板的数据都作为模板，从而使得swap可以运行在任意的Matrix上
//	//引入标准库的swap，从而保证待交换的类没有定义swap时，也能交换
//	//因为指针类型时不一样的，所以也不能交换内存。。
//	//这个类的设计真是失败啊 :(
//	//大小不同的矩阵，本质上来说，大小本来就不是一样的，自然是不能交换的
//	//就是使用黑科技强制交换，也会导致维数和内容不匹配
//	using std::swap;
//	swap(lhm.data, rhm.data);
//	
//}

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
			(*this)[i][j] = matrix.content[i][j];
		}
	}
}

template<typename T, unsigned rows, unsigned cols>
inline Matrix<T, rows, cols>::Matrix(const Matrix<T, rows, cols>& rhm)
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			(*this)[i][j] = rhm[i][j];
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
inline T * Matrix<T, rows, cols>::operator[](unsigned int i)
{
	return data[i];
}

template<typename T, unsigned rows, unsigned cols>
inline const T * Matrix<T, rows, cols>::operator[](unsigned int i) const
{
	return data[i];
}

template<typename T, unsigned rows, unsigned cols>
template<unsigned int brows, unsigned int bcols>
inline Matrix<T, rows, bcols> Matrix<T, rows, cols>::operator*(Matrix<T, brows, bcols>& rhm)
{
	//标准的右值，需要实现相关的移动赋值和构造函数
	Matrix<T, rows, bcols> rtn;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < bcols; j++) {
			T tmp = 0;
			for (int k = 0; k < cols; k++) {
				tmp += (*this)[i][k] * rhm[k][j];
			}
			rtn[i][j] = tmp;
		}
	}

	return rtn;
}
