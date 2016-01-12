#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

struct biginteger 
{
	int digit[1000];
	int size;
	void init()
	{
		for (int i=0;i<1000;++i)
		{
			digit[i]=0;
			size=0;
		}
	}
};

biginteger Multi(biginteger A,int a);
void Factorial(int num)
{
	biginteger A;
	A.init();
	A.digit[0]=1;
	A.size=1;
	for (int i=1;i<=num; ++i)
	{
		A=Multi(A,i);
	}
	for (int i=A.size-1;i>=0;--i)
	{
		if (i==A.size-1)
		{
			printf("%d",A.digit[i]);
		}
		else
		{
			printf("%04d",A.digit[i]);
		}
	}
}

biginteger Multi(biginteger A,int a)
{
	biginteger ret;
	ret.init();
	int flag=0;
	for (int i=0;i<A.size;++i)
	{
		int temp=A.digit[i]*a+flag;
		flag=temp/10000;
		ret.digit[ret.size++]=temp%10000;
	}
	if (flag!=0)
	{
		ret.digit[ret.size++]=flag;
	}
	return ret;
}

int main()
{
	int num;
	scanf("%d",&num);
	while (num!=EOF)
	{
		Factorial(num);
		scanf("%d",&num);
	}
	system("pause");
	return 0;
}