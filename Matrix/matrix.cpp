//#include "Matrix.h"
//#include <fstream>
//#include <sstream>
//
//DynamicMatrix<T> & DynamicMatrix<T>::GetOne(int one)
//{
//	buf.push_back(one);
//	return *this;
//}
//
//DynamicMatrix<T> & DynamicMatrix<T>::ReFlash()
//{

//}
//
//void DynamicMatrix<T>::ShowMatrix()
//{
//	//TODO���滻��io��
//	for (auto &r : content ) {
//		putchar('|');
//		for (auto &c: r) {
//			printf("%7d", c);
//		}
//		printf("      |\n");
//	}
//}
//
//bool DynamicMatrix<T>::IsEmpty()
//{
//	return content.size() == 0;
//}
//
//bool DynamicMatrix<T>::IsBufEmpty()
//{
//	return buf.size() == 0;
//}
//
//DynamicMatrix<T> & DynamicMatrix<T>::RowReduce()
//{
//	_RowReduce_Tri();
//	_RegressReduce();
//	return *this;
//}
//
//Fraction DynamicMatrix<T>::det()
//{
//	auto copied = *this;
//	int expend = copied._RowReduce_Tri(true);
//	int det = 1;
//	for (unsigned int i = 0; i < content.size(); ++i) {
//		det *= copied.content[i][i];
//	}
//
//	return Fraction(det,expend);
//}
//
//DynamicMatrix<T> & DynamicMatrix<T>::Transpose()
//{
//	DynamicMatrix<T> temp;
//	for (unsigned int i = 0; i < content[0].size(); ++i) {
//		temp.buf = GetCol(i);
//		temp.ReFlash();
//	}
//	content.swap(temp.content);
//	return *this;
//}
//
//DynamicMatrix<T> & DynamicMatrix<T>::Clear()
//{
;
//}
//
//void DynamicMatrix<T>::EigenValue()
//{
//	//TODO:����һ�����϶���Ķ���ʽ�ľ���
//	//     Ȼ�����Щ������дһ�飿	   
//
//}
//
//DynamicMatrix<T> & DynamicMatrix<T>::RowEx(int row1, int row2)
//{
//	auto &r1 = content[row1];
//	auto &r2 = content[row2];
//	r1.swap(r2);
//
//	return *this;
//}
//
//DynamicMatrix<T> & DynamicMatrix<T>::RowExC(int C, int row)
//{
//	if (C != 0) {
//		auto &r = content[row];
//		for (auto & i : r) {
//			i = C * i;
//		}
//	}
//	return *this;
//}
//
//DynamicMatrix<T> & DynamicMatrix<T>::RowExCP(int C1, int row, int C2, int crow)
//{	
//	//���ӵ�һ����Ҫ�޸�ԭʼ���ݣ���һ�в�Ҫ�޸�
//	auto &r = content[row];
//	auto cr = content[crow];
//
//	for (auto & i : r) {
//		i *= C1;
//	}
//
//	for (auto & i : cr) {
//		i *= C2;
//	}
//
//	for (unsigned int i = 0; i < r.size(); ++i) {
//		r[i] += cr[i];
//	}
//
//	return *this;
//}
//
//int DynamicMatrix<T>::GetPivot(int row)
//{
//	auto &r = content[row];
//	for (unsigned int i = 0; i < r.size(); ++i) {
//		if (r[i] != 0) {
//			return i;
//		}
//	}
//
//	return r.size();
//}
//
//int DynamicMatrix<T>::CheckPivot(unsigned int doRow, unsigned int col)
//{
//	const int NotFound = content.size();
//	const int IsGood = -1;
//	unsigned int i = doRow;
//
//	//���ھ��󷵻أ�ֱ�ӷ���
//	if (col >= content.size() || i >= content[0].size()) {
//		return IsGood;
//	}
//	
//	if (content[i][col] == 0) {
//		for ( ; i < content.size(); ++i) {
//			if (content[i][col] != 0) {
//				break;
//			}
//		}
//		return i;
//	}
//	else {
//		return IsGood;
//	}
//
//}
//
//void DynamicMatrix<T>::Reduceone(int row)
//{
//	auto &r = content[row];
//	int gcdnum = 0;
//	//���һ�е�ȫ��Ԫ�صĹ�����
//	for (const auto &i : r) {
//		gcdnum = gcd(i, gcdnum);
//	}
//	
//	if (gcdnum != 0) {
//		for (auto &i : r) {
//			i /= gcdnum;
//		}
//	}
//}
//
//int DynamicMatrix<T>::_RowReduce_Tri(bool IsDeterminant)
//{
//	const unsigned int Rnum = content.size();
//	const unsigned int Cnum = content[0].size();
//
//	int expand = 1;
//	unsigned int eli_col = 0;
//
//	//����ÿһ�У�ͬʱ������ȥ�е�λ��
//	for (unsigned int i = 0; i < Rnum && eli_col < Cnum; ++i,++eli_col) {
//		
//		//�ж�pivot�Ƿ���Ҫ������λ��
//		int ReturnRow = CheckPivot(i, eli_col);
//		while (ReturnRow > 0)
//		{
//			if (ReturnRow < Rnum) {
//				//��������ʽλ�ã�������
//				expand = -expand;
//				RowEx(i, ReturnRow);
//			}
//			else if (ReturnRow == Rnum) {
//				//ȫ��Ϊ�㣬ֱ�ӿ�ʼ�ж����е����
//				++eli_col;
//			}
//			ReturnRow = CheckPivot(i, eli_col);
//		}
//	
//		//������i����ʣ�����
//		for (int j = i + 1; j < Rnum && eli_col < Cnum; ++j) {
//			
//			
//			int pi = content[i][eli_col];
//			int pj = content[j][eli_col];
//
//			//�ж���ȥ���Ƿ�Ϊ0��������������ʼ��ȥ��һ��
//			if (pj == 0) {
//				continue;
//			}
//
//			//��ȥ����ǰ����ﵽ��С������������
//			int ps = lcm(pi, pj);
//			pi = ps / pi;
//			pj = ps / pj;
//
//			//����ѧ֪ʶ���������Ӻ�ԭ������������Ժ����еķ���������ͬ��
//			//ʹ�����һ��ǰ����ϸ��ż��ɱ�֤����
//			RowExCP(pj, j, -pi, i);
//
//			//��¼�仯���е�������
//			expand *= pj;
//
//			//���Դ��룬ע���Ƴ�
//			//std::cerr << std::endl;
//			//ShowMatrix();
//		}
//	}
//
//	if (IsDeterminant) {
//		return expand;
//	}
//	else {
//		return 1;
//	}
//}
//
//void DynamicMatrix<T>::_RegressReduce()
//{
//	const int Rnum = _Rank();
//	unsigned int elicol = content[0].size() - 1;
//
//	//����������߽������б仯
//	for (int i = Rnum - 1; i >= 0; --i) {
//		Reduceone(i);
//		for (int j = i - 1; j >= 0; --j) {
//			unsigned int eli_col = GetPivot(i);
//			//�Ѿ������rank�����Բ���Խ��
//			int pi = content[i][eli_col];
//			int pj = content[j][eli_col];
//
//			//�ж���ȥ���Ƿ�Ϊ0������ֱ����һ��
//			if (pj == 0) {
//				continue;
//			}
//
//			int ps = lcm(pi, pj);
//			pi = ps / pi;
//			pj = ps / pj;
//
//			RowExCP(pj, j, -pi, i);
//		}
//	}
//
//}
//
//int DynamicMatrix<T>::_Rank()
//{
//	int rank = 0;
//	//���ж��Ƿ�Խ�磬�����ж���һ�е�ֵ
//	for (unsigned int i = 0;i < content.size() && GetPivot(i) != content[0].size(); ++i) {
//		if (content[i][GetPivot(i)] != 0 ) {
//			++rank;
//		}
//	}
//	return rank;
//}
//
//std::vector<int> DynamicMatrix<T>::GetCol(int col)
//{
//	std::vector<int> ret;
//	for (unsigned int i = 0; i < content.size(); ++i) {
//		for (unsigned int j = 0; j < content[0].size(); ++j) {
//			if (j == col) {
//				ret.push_back(content[i][j]);
//			}
//		}
//	}
//
//	return ret;
//
//}
//
//
//bool DynamicMatrix<T>::IsRegular()
//{	
//	//����վ����ǹ����
//	if (this->IsEmpty())
//	{
//		return true;
//	}
//
//	//��������������ݣ���ˢ�»�����
//	if (!this->IsBufEmpty())
//	{
//		this->ReFlash();
//	}
//
//	auto reg = content[0].size();
//	for (auto &r : content)
//	{
//		if (r.size() != reg)
//		{
//			return false;
//		}
//	}
//	return true;
//}
//
//DynamicMatrix<T> operator+(DynamicMatrix<T> & lmx, DynamicMatrix<T> & rmx)
//{
//	if (!(lmx.content.size() == rmx.content.size() &&
//		lmx.content[0].size() == lmx.content[0].size())) {
//		throw matrix_mismatch("����ͬ��");
//	}
//
//	DynamicMatrix<T> mx;
//	for (unsigned int i = 0; i < lmx.content.size(); ++i) {
//		for (unsigned int j = 0; j < lmx.content[0].size(); ++j) {
//			mx.GetOne(lmx.content[i][j] + rmx.content[i][j]);
//		}
//		mx.ReFlash();
//	}	
//	return mx;
//}
//
//DynamicMatrix<T> operator*(int C, DynamicMatrix<T> & rmx)
//{	
//	DynamicMatrix<T> mx;
//	for (auto &r : rmx.content) {
//		for (auto &i : r) {
//			mx.GetOne(C*i);
//		}
//		mx.ReFlash();
//	}
//
//	return mx;
//}
//
//DynamicMatrix<T> operator-(DynamicMatrix<T> & lmx, DynamicMatrix<T> & rmx)
//{
//	return lmx + (-1 * rmx);
//}
//
//
//DynamicMatrix<T> operator*(DynamicMatrix<T> & lmx, DynamicMatrix<T> & rmx)
//{
//	if (lmx.content[0].size() != rmx.content.size()) {
//		throw matrix_mismatch("������ʽ��ƥ��");
//	}
//
//	DynamicMatrix<T> mx;
//	for (unsigned int i = 0; i < lmx.content.size(); ++i) {
//		for (unsigned int j = 0; j < rmx.content[0].size(); ++j) {
//			mx.GetOne(dot(lmx.content[i], rmx.GetCol(j)));
//		}
//		mx.ReFlash();
//	}
//	return mx;
//}