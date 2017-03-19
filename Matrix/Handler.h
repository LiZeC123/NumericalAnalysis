#pragma once
#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include "Matrix.h"

//参数类型
using  Arg = std::vector<std::string>;

//命令的基类，之后添加的命令继承该类
class Handler
{
public:
	virtual void doCmd(Arg args);
};

class HandlerNew : public Handler
{
public:
	void doCmd(Arg args) override;
};

class HandlerLook : public Handler
{
public:
	void doCmd(Arg args) override;
};

class HandlerReduce : public Handler
{
public:
	void doCmd(Arg args) override;
};

class HandlerDet : public Handler
{
public:
	void doCmd(Arg args) override;
};

class HandlerClean : public Handler
{
public:
	void doCmd(Arg args) override;
};

class HandlerAppend : public Handler
{
public:
	void doCmd(Arg args) override;
	void _Append(std::istream & in, DynamicMatrix & Mc);
};

class HandlerAdd : public Handler
{
public:
	void doCmd(Arg args) override;
};

class HandlerSub : public Handler
{
public:
	void doCmd(Arg args) override;
};

class HandlerMult : public Handler
{
public:
	void doCmd(Arg args) override;
};


/*                   与用户相关的全局变量的声明              */
extern std::string UserName;
extern std::string ComputerName;
extern std::map<std::string, DynamicMatrix> UserValueSpace;
extern std::map<std::string, Handler*> handlers;