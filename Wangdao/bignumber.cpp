#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

struct  biginteger
{
	int digit[1000];//digit 数组用来保存大整数中每若干位的数字，这里我们暂且使用每 4位为 一个单位保存
	int Size;//size 为 digit 数组中第一个我们还没使用过的数组单元
	void init()
	{
		for(int i=0;i<1000;++i)
			digit[i]=0;
		Size=0;
	}
};

void str2int(biginteger &A,string a)
{
	A.init();
	for (int i=a.size()-1,c=1,t=0,j=0;i>=0;--i)
	{
		t=t+(a[i]-'0')*c;
		c=c*10;
		j++;
		if(j==4||i==0)
		{
			A.digit[A.Size]=t;
			A.Size++;
			c=1;
			t=0;
			j=0;
		}
	}
}

void add(biginteger A,biginteger B)
{
	biginteger ret;
	ret.init();
	int flag=0;
	for (int i=0;i<A.Size||i<B.Size;++i)
	{
		int temp=A.digit[i]+B.digit[i]+flag;
		flag=temp/10000;

		ret.digit[ret.Size++]=temp%10000;
	}
	if (flag!=0)
	{
		ret.digit[ret.Size++]=flag;
	}
	for (int i=ret.Size-1;i>=0;--i)
	{
		if(i==ret.Size-1)
			printf("%d",ret.digit[i]);
		else
		{
			printf("%04d",ret.digit[i]);
		}
	}
	cout<<endl;
}

int main()
{
	string a,b;
	cin>>a;
	cin>>b;
	cout<<a<<" "<<b<<endl;
	biginteger A,B;
	str2int(A,a);
	str2int(B,b);
	add(A,B);
	system("pause");
	return 0;
}