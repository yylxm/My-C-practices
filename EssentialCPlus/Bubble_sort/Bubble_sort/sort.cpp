#include<iostream>
#include<vector>

using namespace std;

void display(const vector<int> &vec)
{
	for(int ix=0;ix<vec.size();++ix)
		cout<<vec[ix]<<" ";
	cout<<endl;
}

void swap(int &a,int &b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}

void bubble_sort(vector<int> &vec)
{
	for(int ix=0;ix<vec.size();++ix)
		for(int jx=ix+1;jx<vec.size();++jx)
			if(vec[ix]>vec[jx])
				swap(vec[ix],vec[jx]);
}

int main()
{
	int a[]={8,34,3,13,1,21,5,2};
	vector<int> vec(a,a+8);

	cout<<"vector before sort:";
	display(vec);

	bubble_sort(vec);

	cout<<"vector affter sort:";
	display(vec);

	system("pause");
	return 0;
}