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

	//�������캯��
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


	//��֮ģ����ģ�壬Ҳ��֪���ܲ��ܳɹ�ʵ����������������ԵĻ���֮�������Ͳ�����Ҫ��̬����
	//���������⣺��ͬ�Ĳ���ʵ�����������಻һ���������ڴ�ģ�����ϵ�ģ�庯������ƥ������
	//���⣬��Ϊ�ǲ�ͬ���࣬�ı��С�Ķ�Ԫ������������ܷ�������һ�����е�private��Ա
	//����ʹ�øı��С���ཫ�������صĴ�����������

	template<unsigned int brows,unsigned int bcols>
	Matrix<T, rows, bcols> operator*(Matrix<T, brows, bcols> &rl);

	//�������õ�ָ�룬�Ӷ�ʵ�־���ķ��ʹ���
	T * operator[](unsigned int i);
	const T * operator[](unsigned int i) const;

private:
	//����[]���������ӷ����ݣ��Ӷ�����ֱ�ӱ�¶ָ��
	T(*data)[cols];
	
};

//template<typename T1, typename T2, unsigned r1, unsigned c1, unsigned r2, unsigned c2 >
//inline void swap(Matrix<T1, r1, c1>& lhm, Matrix<T2, r2, c2>& rhm)
//{
//	//ͨ����Ҫ����������ģ������ݶ���Ϊģ�壬�Ӷ�ʹ��swap���������������Matrix��
//	//�����׼���swap���Ӷ���֤����������û�ж���swapʱ��Ҳ�ܽ���
//	//��Ϊָ������ʱ��һ���ģ�����Ҳ���ܽ����ڴ档��
//	//�������������ʧ�ܰ� :(
//	//��С��ͬ�ľ��󣬱�������˵����С�����Ͳ���һ���ģ���Ȼ�ǲ��ܽ�����
//	//����ʹ�úڿƼ�ǿ�ƽ�����Ҳ�ᵼ��ά�������ݲ�ƥ��
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
	//�����ڴ���ղ��ԣ�ȷʵ�����ͷ��ڴ�
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
	//��׼����ֵ����Ҫʵ����ص��ƶ���ֵ�͹��캯��
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
