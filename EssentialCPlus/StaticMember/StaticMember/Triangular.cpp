#include<iostream>
#include<algorithm>
#include"Triangular.h"
using namespace std;

const int Triangular::_max_elems=1024;
vector<int> Triangular::_elems;//����Ҫ��.cpp�ļ����ٴ����������������̬���ݳ�Աֻ��Ψһ��һ��ʵ�壬������Ǳ����ڳ�������ļ����ṩ������Ķ��塣��

void Triangular::gen_elems_to_value(int value)
{
	int ix=_elems.size();
	if(!ix)
	{
		_elems.push_back(1);
		ix=1;
	}
 	while(_elems[ix-1]<value&&ix<_max_elems)
	{
		//cout<<"elems to value: "<<ix*(ix+1)/2<<endl;
		++ix;
		_elems.push_back(ix*(ix+1)/2);
	}
	if(ix==_max_elems)
	{
		cerr<<"Triangular Sequence: oops:value too large"
			<<value<<"-- exceeds max size of "
			<<_max_elems<<endl;
	}
}

void Triangular::gen_elements(int length)
{
	if(length<0||length>_max_elems)
	{
		cerr<<"Out of range!";
		return ;
	}
	if(_elems.size()<length)
	{
		int ix=_elems.size()?_elems.size()+1:1;
		for(; ix<=length;++ix)
			_elems.push_back(ix*(ix+1)/2);
	}
}

bool Triangular::is_elem(int value)
{
	if(!_elems.size()||_elems[_elems.size()-1]<value)
		gen_elems_to_value(value);

	vector<int>::iterator found_it;
	vector<int>::iterator end_it=_elems.end();

	found_it=find(_elems.begin(),end_it,value);
	return found_it!=end_it;
}
