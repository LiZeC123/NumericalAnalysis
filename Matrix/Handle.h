#pragma once
#include <vector>
#include <string>

using Arg = std::vector<std::string>;

struct Handle
{
	virtual void doCmd(Arg args) = 0;
};

struct HandleNew : public Handle
{
	void doCmd(Arg args) override;
};

struct HandleAppend : Handle
{
	void doCmd(Arg args) override;
};

struct HandleLs : public Handle
{
	void doCmd(Arg args) override;
};

struct HandleReduce : public Handle
{
	void doCmd(Arg args) override;
};

struct HandleDet : public Handle
{
	void doCmd(Arg args) override;
};

struct HandleClear : public Handle
{
	void doCmd(Arg args) override;
};

struct HandleAdd : public Handle
{
	void doCmd(Arg args) override;
};

struct HandleSub : public Handle
{
	void doCmd(Arg args) override;
};

struct HandleMult : public Handle
{
	void doCmd(Arg args) override;
};

struct HandleLoadData : public Handle
{
	void doCmd(Arg args) override;
};

struct HandleTranspose : public Handle
{
	void doCmd(Arg args) override;
};

struct HandlePrint : public Handle
{
	void doCmd(Arg args) override;
};

struct HandlePause : public Handle
{
	void doCmd(Arg args) override;
};

struct HandleDefine : public Handle
{
	void doCmd(Arg args) override;
};
