#include<iostream>
#include"Triangular.h"
#include"Triangular_iterator.h"
using namespace std;

bool Triangular_iterator::operator==(const Triangular_iterator &rhs)const
{
	return _index==rhs._index;
}

bool Triangular_iterator::operator!=(const Triangular_iterator &rhs)const
{
	return !(_index==rhs._index);
}

int Triangular_iterator::operator*()const
{
	check_integrity();
	return Triangular::_elems[_index];
}

Triangular_iterator& Triangular_iterator::operator++()
{
	++_index;
	check_integrity();
	return *this;
}

Triangular_iterator Triangular_iterator::operator++(int)
{
	Triangular_iterator tmp=*this;
	++_index;
	check_integrity();
	return *this;
}

void Triangular_iterator::check_integrity()const
{
	if(_index>=Triangular::_max_elems)
		cerr<<"iterator_overflow!";
	if(_index>=Triangular::_elems.size())
		Triangular::gen_elements(_index+1);
}