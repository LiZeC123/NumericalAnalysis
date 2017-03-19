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

	//判断是否是一个规则的矩阵
	bool IsRegular();

	//判断矩阵是否为空
	bool IsEmpty();

	//判断缓冲区是否为空
	bool IsBufEmpty();

	//清空矩阵的内容
	DynamicMatrix<T> & Clear();

	//直接暴露存储容器，便于后续类对其中数据进行操作
	std::vector<std::vector<T> > content;

private:
	//一般数据的容器
	std::vector<T> buf;
	

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
inline bool DynamicMatrix<T>::IsRegular()
{
	if (content.empty()) {
		return true;
	}
	auto colNum = content[0].size();
	for (const auto & arow : content) {
		if (arow.size() != colNum) {
			return false;
		}
	}
	return true;
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
	return *this;
}
