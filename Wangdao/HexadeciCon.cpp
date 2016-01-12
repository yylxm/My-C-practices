#include <iostream>

using namespace std;
struct node{
	int n;
	int a;
	int b;
}buf[100];

int pow(int a,int b)
{
	for(int i=0;i<b;i++)
	{
		a=a*a;
	}
	return a;
}

void Conversion(node buf)
{
	int sum=buf.a+buf.b;
	int ret[20];
	int result;
	int mark=0;
	do
	{
		ret[mark]=sum%buf.n;
		sum=sum/buf.n;
		mark++;
	}while(sum!=0);
	for (int i=mark-1;i>=0;--i)
	{
		cout<<ret[i];
	}
}

int main()
{
	int n;
	int result;
	int mark=0;
	cin>>n;
	while (n!=0)
	{
		buf[mark].n=n;
		scanf("%d%d",&buf[mark].a,&buf[mark].b);
		mark++;
		cin>>n;
	}
	for(int i=0;i<mark;++i)
	{
		Conversion(buf[i]);
		cout<<endl;
	}
	system("pause");
	return 0;
}