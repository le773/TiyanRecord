#pragma once


/*
pass by reference to const replace pass by value
1. avoid slicing problem
2. 内置类型 STL迭代器 函数对象 适合 pass by value
*/

#include <cstdlib>
#include <iostream>

using namespace std;

class EffectCpp20
{
public:
    EffectCpp20();
    ~EffectCpp20();
};

