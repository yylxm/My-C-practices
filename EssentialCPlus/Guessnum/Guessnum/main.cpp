#include<iostream>
#include<string>
#include<vector>
#include "Numberseq.h"

using namespace std;

int main()
{
	const vector<int>* fibon_elems=fibon_seq(10);

	for(auto iter=(*fibon_elems).begin();iter!=(*fibon_elems).end();++iter)
		cout<<*iter<<" ";
	cout<<endl;
	for(int i=0;i<10;++i)
	{
		cout<<(*fibon_elems)[i]<<" ";
	}
	cout<<endl;
	system("pause");
	return 0;
}

