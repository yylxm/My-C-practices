#include <vector>
#include <iostream>
#include "Numberseq.h"
using namespace std;

const vector<int>* (*seq_array[])(int)=
{
	fibon_seq,lucas_seq,pell_seq,triang_seq,square_seq,pentagonal_seq
};

bool is_size_ok(int size)
{
	if(size<0||size>1024)
		return false;
	return true;
}

const vector<int>* fibon_seq(int size)
{
	static vector<int> elems;
	if(is_size_ok(size)==false)
	{
		cerr<<"fibon_seq():oops:invalid size!";
	}

	for(int i=elems.size();i<size;++i)
	{
		if(i==0||i==1)
			elems.push_back(1);
		else
			elems.push_back(elems[i-1]+elems[i-2]);
	}

	return &elems;
}

const vector<int>* lucas_seq(int size)
{
	static vector<int> elems;
	if(is_size_ok(size)==false)
	{
		cerr<<"fibon_seq():oops:invalid size!";
	}

	for(int i=elems.size();i<size;++i)
	{
		if(i==0)
			elems.push_back(1);
		else if(i==1)
			elems.push_back(3);
		else
			elems.push_back(elems[i-1]+elems[i-2]);
	}

	return &elems;
}

const vector<int>* pell_seq(int size)
{
	static vector<int> elems;
	if(is_size_ok(size)==false)
	{
		cerr<<"fibon_seq():oops:invalid size!";
	}

	for(int i=elems.size();i<size;++i)
	{
		if(i==0)
			elems.push_back(1);
		else if(i==1)
			elems.push_back(2);
		else
			elems.push_back(2*elems[i-1]+elems[i-2]);
	}

	return &elems;
}

const vector<int>* triang_seq(int size)
{
	static vector<int> elems;
	if(is_size_ok(size)==false)
	{
		cerr<<"fibon_seq():oops:invalid size!";
	}

	for(int i=elems.size();i<size;++i)
	{
		if(i==0)
			elems.push_back(1);
		else
			elems.push_back(elems[i-1]+i+1);
	}

	return &elems;
}

const vector<int>* square_seq(int size)
{
	static vector<int> elems;
	if(is_size_ok(size)==false)
	{
		cerr<<"fibon_seq():oops:invalid size!";
	}

	for(int i=elems.size();i<size;++i)
	{
		if(i==0)
			elems.push_back(1);
		else
			elems.push_back((i+1)*(i));
	}

	return &elems;
}

const vector<int>* pentagonal_seq(int size)
{
	static vector<int> elems;
	if(is_size_ok(size)==false)
	{
		cerr<<"fibon_seq():oops:invalid size!";
	}

	for(int i=elems.size();i<size;++i)
	{
		if(i==0)
			elems.push_back(1);
		else if(i==1)
			elems.push_back(2);
		else
			elems.push_back(2*elems[i-1]+elems[i-2]);
	}

	return &elems;
}

bool seq_elem(int pos,int &elem,const vector<int>* (*seq_ptr)(int))
{
	const vector<int > *pseq=seq_ptr(pos);
	if(!pseq)
	{
		elem=0;
		return false;
	}

	elem=(*pseq)[pos-1];
	return true;
}