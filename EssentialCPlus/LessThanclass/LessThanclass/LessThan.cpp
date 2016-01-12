#include<iostream>

#include"LessThan.h"
#include<vector>
using namespace std;

bool LessThan::operator()(int value)const
{
	return value<_val;
}



