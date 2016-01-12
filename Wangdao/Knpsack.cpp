#include<iostream>
#include<stdio.h>

using namespace std;
struct rice
{
	int price;
	int weight;
}buf[100];

int max(int a,int b)
{
	return a>b? a:b;
}

int main()
{
	int C;
	scanf("%d",&C);
	int dp[100];

	for (int i = 0; i < C; i++)
	{
		int money,kind;
		scanf("%d%d",&money,&kind);
		int cnt=0;//拆分后物体总数
		for (int i = 1; i <= kind; i++)//对物体进行拆分
		{
			int number,p,w;
			scanf("%d%d%d",&p,&w,&number);
			int c=1;
			while ((number-c)>0)
			{
				number=number-c;
				buf[++cnt].weight=c*w;
				buf[cnt].price=c*p;
				c=c*2;
			}
			buf[++cnt].weight=w*number;
			buf[cnt].price=p*number;
		}

		for (int i = 0; i <=money; i++)//初始化
		{
			dp[i]=0;
		}

		for (int i = 1; i <=cnt; i++)
		{
			for (int j = money; j >=buf[i].price; j--)
			{
				dp[j]=max(dp[j],dp[j-buf[i].price]+buf[i].weight);
			}
		}

		printf("%d\n",dp[money]);
	}
	system("pause");
	return 0;
}