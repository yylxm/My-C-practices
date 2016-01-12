#include <iostream>
#include <math.h>

using namespace std;

bool Prime(int n)
{
	if(n==1||n==0)
		return false;
	int s=sqrt(n)+1;
	for(int i=2;i<s;++i)
	{
		if(n%i==0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int num;
	scanf("%d",&num);
	if(Prime(num))
		cout<<"yes"<<endl;
	else
	{
		cout<<"false";
	}
	int s=sqrt(num);
	system("pause");
	return 0;
}