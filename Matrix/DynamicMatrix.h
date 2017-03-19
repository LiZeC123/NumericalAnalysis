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

	//�ж��Ƿ���һ������ľ���
	bool IsRegular();

	//�жϾ����Ƿ�Ϊ��
	bool IsEmpty();

	//�жϻ������Ƿ�Ϊ��
	bool IsBufEmpty();

	//��վ��������
	DynamicMatrix<T> & Clear();

	//ֱ�ӱ�¶�洢���������ں�������������ݽ��в���
	std::vector<std::vector<T> > content;

private:
	//һ�����ݵ�����
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
