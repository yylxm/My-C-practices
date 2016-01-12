#include<iostream>
#include<vector>
#include<algorithm>
#include"LessThan.h"
using namespace std;

int count_less_than(const vector<int>&,int);
void print_less_than(const vector<int> &,int,ostream &);


int main()
{
	int ia[16]={17,12,44,9,18,45,6,14,23,67,9,0,27,55,8,16};
	vector<int> vec(ia,ia+16);
	int comp_val=20;

	cout<<"Number of elements less than "
		<<comp_val<<" are "
		<<count_less_than(vec,comp_val)<<endl;
	print_less_than(vec,comp_val,cout);

	system("pause");
	return 0;
}

int count_less_than(const vector<int>&vec,int cmp)
{
	LessThan It(cmp);
	int count=0;
	for(int ix=0;ix<vec.size();++ix)
		if(It(vec[ix]))
			++count;
	return count;
}

void print_less_than(const vector<int> &vec,int comp,ostream &os=cout)
{
	LessThan It(comp);
	vector<int>::const_iterator iter=vec.begin();
	vector<int>::const_iterator it_end=vec.end();

	os<<"elements less than "<<It.comp_val()<<endl;
	while((iter=find_if(iter,it_end,It))!=it_end)
	{
		os<<*iter<<" ";
	    ++iter;
	}		
}