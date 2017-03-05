#pragma once
#include <vector>
class IntMultNode
{
public:
	IntMultNode();
	~IntMultNode();

private:
	double coe;
	int exp;
};

IntMultNode::IntMultNode()
{
}

IntMultNode::~IntMultNode()
{
}

class IntMult
{
public:
	IntMult();
	~IntMult();

private:
	std::vector<IntMultNode> data;
};

