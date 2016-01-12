#include <iostream>
#include <stdio.h>
#include <stack>

using namespace std;

int  Dismantling(int *ist,long int a)
{
	int i=0;
	while (a>0)
	{
		ist[i]=(a%10);
		a=a/10;
		i++;
	}
	ist[i]=0;
	return i;//返回数组的大小
}

int main()
{
	long int a,b;	
	int sum=0;
	scanf("%ld,%ld",&a,&b);
	int aist[10];
	int bist[10];
	int sa=Dismantling(aist,a);
	int sb=Dismantling(bist,b);
	for (int i=0;i<sa;++i)
	{
		for (int j=0;j<sb;++j)
		{
			sum=sum+aist[i]*bist[j];
		}
	}
	cout<<sum<<endl;
	system("pause");
	return 0;
}