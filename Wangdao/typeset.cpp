#include <iostream>

using namespace std;

int main()
{
	int h;
	cin>>h;
	int maxline=h+(h-1)*2;
	for(int i=1;i<=h;++i)
	{
		for (int j=1;j<=maxline;++j)
		{
			if(j<maxline-h-(i-1)*2+1)
				cout<<" ";
			else
				cout<<"*";
		}
		cout<<endl;
	}
	cout<<endl;
	system("pause");
	return 0;
}