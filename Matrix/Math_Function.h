#pragma once
//数学函数库，与数学相关的通用函数在此文件中声明

#include <vector>
//最大公约数
int gcd(int a, int b);

//最小公倍数
int lcm(int a, int b);

//计算向量的点乘
int dot(std::vector<int> v1, std::vector<int> v2);