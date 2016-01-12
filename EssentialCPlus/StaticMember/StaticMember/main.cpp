#include<iostream>
#include"Triangular.h"
using namespace std;

int main()
{
	char ch;
	bool more=true;
	while(more)
	{
		cout<<"Enter value: ";
		int ival;
		cin>>ival;

		bool is_elem=Triangular::is_elem(ival);

		cout<<ival
			<<(is_elem?" is ":" is not ")
			<<"an elements in the Triangular series.\n"
			<<"Another value?(y/n)";

		cin>>ch;
		if(ch!='y'||ch!='Y')
			more=false;
	}
	//Triangular tri(20);


	system("pause");
	return 0;
}