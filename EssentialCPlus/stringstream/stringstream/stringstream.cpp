#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main()
{
	string s;
	stringstream ss;
	int a,num;
	cout<<"ÇëÊäÈë×éÊı£º";
	cin>>a;
	getline(cin,s);
	for(int i=0;i<a;++i)
	{
		getline(cin,s);
		ss.clear();
		ss.str(s);
		int sum=0;
		while(1)
		{
			ss>>num;
			if(ss.fail())
				break;
			sum=sum+num;
			
		}
		cout<<sum<<endl;
	}

	system("pause");
	return 0;
}