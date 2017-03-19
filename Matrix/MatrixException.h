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
异常和异常处理的一些问题
实际上，如果按照当前的设计模式，有一些异常，应该直接抛出，导致程序结束
因为实际上这样的异常，准确来说，是代码编写有问题
但是，这样的错误真的应该被称为异常吗?
是否应该使用诊断宏来处理这些问题？
或者还是使用异常，但是并不catch任何相关的异常
分成Exception和Error

在性能和程序稳定上需要如何取得平衡？
*/