/*输入：Fibonacci数列的位置
  输出：该位置的数，以及该位置之前的所有数列*/
#include<iostream>

using namespace std;

bool fibon_elem(int pos,int &elem)
{
	if(pos<0||pos>1024)
	{
		elem=0;
		return false;
	}

	elem=1;
	int n1=1,n2=1;
	for(int x=3;x<=pos;++x)
	{
		elem=n1+n2;
		n1=n2;
		n2=elem;
	}
	return true;
}

bool print_sequence(int pos)
{
	if(pos<0||pos>1024)
	{
		cerr<<"invalid position: "<<pos
			<<"--cannot handle request!\n";
		return false;
	}
	cout<<"The Fibonacci Sequence for "
		<<pos<<" is:\n\t";
	switch(pos)
	{
	    default:
		case 2:
			cout<<"1 ";
		case 1:
			cout<<"1 ";
			break;
	}
	int elem;
	int n1=1,n2=1;
	for(int x=3;x<=pos;++x)
	{
		elem=n1+n2;
		n1=n2;
		n2=elem;
		cout<<elem<<(!(x%10)?"\n\t":" ");
	}
	cout<<endl;
	return true;
}

int main()
{
	int pos;
	bool more=true;
	char ch;
	while(more)
	{
		cout<<"please enter a position:";
	    cin>>pos;

	    int elem;
	    if(fibon_elem(pos,elem))
		    cout<<"element #"<<pos
		        <<" is "<<elem<<endl;
	    else cout<<"Sorry ,could not calculate element #"
		        <<pos<<endl;
	    print_sequence(pos);
		cout<<"Would you like to try again?(y/n)";
		cin>>ch;
		if(ch!='Y'&&ch!='y')
			more=false;
	}
	

	system("pause");
	return 0;
}
