#pragma once

#include <vector>
#include "MatrixException.h"



template<typename T> class DynamicMatrix
{
public:
	DynamicMatrix() = default;

public:
	//向缓冲区读入一个数据
	DynamicMatrix<T> & GetOne(int one);

	//将缓冲区的数据写入
	DynamicMatrix<T> & ReFlash();

	//将当前矩阵中的内容输出到cout
	void ShowMatrix();

	//判断是否是一个规则的矩阵
	bool IsRegular();

	//判断矩阵是否为空
	bool IsEmpty();

	//判断缓冲区是否为空
	bool IsBufEmpty();



	//清空矩阵的内容
	DynamicMatrix<T> & Clear();

private:
	//一般数据的容器
	std::vector<T> buf;
	std::vector<std::vector<T> > content;

};

template<typename T>
inline DynamicMatrix<T>& DynamicMatrix<T>::GetOne(int one)
{
	buf.push_back(one);
	return *this;
}

template<typename T>
inline DynamicMatrix<T>& DynamicMatrix<T>::ReFlash()
{
	content.push_back(buf);
	buf.clear();
	return *this;
}

template<typename T>
inline void DynamicMatrix<T>::ShowMatrix()
{
}

template<typename T>
inline bool DynamicMatrix<T>::IsRegular()
{
	return false;
}

template<typename T>
inline bool DynamicMatrix<T>::IsEmpty()
{
	return content.empty();
}

template<typename T>
inline bool DynamicMatrix<T>::IsBufEmpty()
{
	return buf.empty();
}

template<typename T>
inline DynamicMatrix<T>& DynamicMatrix<T>::Clear()
{
	content.clear();
	return *this
}
