#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

long pow(int a,int b)
{
	long result=1;
	for(int i=1;i<=b;++i)
	{
		result=result*a;
	}
	return result;
}

long long Sorc2Dec(char *str,int s)
{
	long long result=0;
	int t;
	for (int i=strlen(str)-1,j=0;i>=0;--i,++j)
	{
		if(str[i]>='0'&&str[i]<='9')
			t=str[i]-'0';
		else if (str[i]>='a'&&str[i]<='z')
		{
			t=str[i]-'a'+10;
		}else
		{
			t=str[i]-'A'+10;
		}
		result=result+t*pow(s,j);
	}
	return result;
}

void  Dec2Dest(long long number,int d)
{
	char ret[20];
	int mark=0;
	do 
	{
		int tmp=number%d;
		ret[mark]=tmp<10? tmp+'0':tmp-10+'A';//全部转换为ABCDF的形式
		number=number/d;
		mark++;

	} while (number!=0);
	for(int i=mark-1;i>=0;--i)
	{
		cout<<ret[i];
	}
	cout<<endl;
}
int main()
{
	int sorce;
	int dest;
	char number[20];
	scanf("%d%s%d",&sorce,&number,&dest);
	long long tmp=Sorc2Dec(number,sorce);
	Dec2Dest(tmp,dest);
	//printf("%s",number);
	system("pause");
	return 0;
}