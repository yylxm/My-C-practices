#include<iostream>
#include<stdio.h>

using namespace std;

long long Hanoi(int n)
{
	if(n==1) return 2;
	else
	{
		return 3*Hanoi(n-1)+2;
	}
}

int main()
{
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		int ret;
		ret=Hanoi(n);
		printf("%lld\n",ret);
	}
	system("pause");
	return 0;
}