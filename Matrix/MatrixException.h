#pragma once
#include <stdexcept>

class MatrixException : public std::logic_error
{
public:
	MatrixException(const std::string & s) :
		std::logic_error(s) { };
};

class BufIsNotEmpty : MatrixException
{
public:
	BufIsNotEmpty(const std::string & s) :MatrixException(s) {};
};


/*
�쳣���쳣�����һЩ����
ʵ���ϣ�������յ�ǰ�����ģʽ����һЩ�쳣��Ӧ��ֱ���׳������³������
��Ϊʵ�����������쳣��׼ȷ��˵���Ǵ����д������
���ǣ������Ĵ������Ӧ�ñ���Ϊ�쳣��?
�Ƿ�Ӧ��ʹ����Ϻ���������Щ���⣿
���߻���ʹ���쳣�����ǲ���catch�κ���ص��쳣
�ֳ�Exception��Error

�����ܺͳ����ȶ�����Ҫ���ȡ��ƽ�⣿
*/