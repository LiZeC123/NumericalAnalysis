#pragma once

#include <vector>
#include "MatrixException.h"



template<typename T> class DynamicMatrix
{
public:
	DynamicMatrix() = default;

public:
	//�򻺳�������һ������
	DynamicMatrix<T> & GetOne(int one);

	//��������������д��
	DynamicMatrix<T> & ReFlash();

	//����ǰ�����е����������cout
	void ShowMatrix();

	//�ж��Ƿ���һ������ľ���
	bool IsRegular();

	//�жϾ����Ƿ�Ϊ��
	bool IsEmpty();

	//�жϻ������Ƿ�Ϊ��
	bool IsBufEmpty();



	//��վ��������
	DynamicMatrix<T> & Clear();

private:
	//һ�����ݵ�����
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
