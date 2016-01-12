#include<iostream>
#include<stdio.h>

using namespace std;

#define INF 0x7fffffff

struct back
{
	int W;
	int P;
}buf[500];

int min(int a,int b)
{
	return a>b? b:a;
}

int dp[100];

int main()
{
	int t;
	scanf("%d",&t);
	for (int i = 0; i < t; i++)
	{
		int empty,full;
		scanf("%d%d",&empty,&full);

		for (int i = 1; i <= full-empty; i++)//初始化
		{
			dp[i]=INF;
		}
		dp[0]=0;
		int  kind;//钱币的种类
		scanf("%d",&kind);
		for (int i = 1; i <= kind; i++)
		{
			scanf("%d%d",&buf[i].P,&buf[i].W);//p价值，W重量
		}

		for (int i = 1;  i<=kind; i++)
		{
			for (int j=buf[i].W; j<=full-empty; j++)
			{
				if(dp[j-buf[i].W]!=INF)
					dp[j]=min(dp[j],dp[j-buf[i].W]+buf[i].P);
			}
		}

		if(dp[full-empty]!=INF)
			printf("The minimum amount of money in the piggy-bank is %d\n",dp[full-empty]);
		else
			printf("Thia is impossible.\n");
	}
	system("pause");
	return 0;
}