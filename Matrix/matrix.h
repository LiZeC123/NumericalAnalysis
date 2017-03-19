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
	//��һ����̬�����Ϲ���̶���С�ľ���ͬʱҲ����ʵ�����ߵ�֮��ת��
	//��Ȼ��Ҫ�ܹ���һ������ת��Ϊ����һ�����ͣ�Ҫôʹ����Ԫ��Ҫ����ֻ�ܱ�¶�ӿ���
	//����C++����ĸ����ԣ��Լ�����ԵĿ��ǣ�Ӧ��ʹ�ú���
	//��Ȼ��̬�Ժܺã���������Ͼ���������һ���̶���С�ľ���
	//���ڻ�ı��С�Ĳ��������»���һЩ����
	Matrix(const DynamicMatrix<T> & matrix);

	unsigned int getRowNum() { return rows; }
	unsigned int getColNum() { return cols; }


	~Matrix();
public:
	Matrix<T, rows, cols> operator+(Matrix<T, rows, cols> &rl);
	Matrix<T, rows, cols> operator-(Matrix<T, rows, cols> &rl);


	//��֮ģ����ģ�壬Ҳ��֪���ܲ��ܳɹ�ʵ����������������ԵĻ���֮�������Ͳ�����Ҫ��̬����
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
	//�����ڴ���ղ��ԣ�ȷʵ�����ͷ��ڴ�
	delete[] data;
}

template<typename T, unsigned rows, unsigned cols>
template<unsigned int brows, unsigned int bcols>
inline Matrix<T, rows, bcols> Matrix<T, rows, cols>::operator*(Matrix<T, brows, bcols>& rl)
{
	//��׼����ֵ����Ҫʵ����ص��ƶ���ֵ�͹��캯��
	Matrix<T, rows, bcols> rtn;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < bcols; j++) {

		}
	}
}
