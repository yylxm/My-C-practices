#include <iostream>
#include <stdio.h>

using namespace std;

int gcd(int a,int b)
{
	if(b==0)return a;
	else return gcd(b,a%b);
}

int lcm(int a,int b,int g)
{
	return a*b/g;
}

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	
	cout<<gcd(a,b)<<endl;
	int Gcd=gcd(a,b);
	cout<<lcm(a,b,Gcd)<<endl;//��С������
	system("pause");
	return 0;
}