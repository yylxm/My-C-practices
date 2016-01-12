#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{
    int a,b;
	int sum=1;
	string bin;
	scanf("%d%d",&a,&b);
	a=a%1000;
	if (b==0)
	{
		cout<<a<<endl;
		return 0;
	}
	while (b!=0)
	{
		if(b%2==1)
		{
			sum=sum*a;
			sum=sum%1000;
		}
		b=b/2;
		a=a*a;
		a=a%1000;
	}
	cout<<sum<<endl;
	system("pause");
	return 0;
}