#include<iostream>
#include<stdio.h>

using namespace std;

struct Herbal
{
	int time;
	int value;
}buf[100];

int dp[200][200];

int max(int a,int b)
{
	return a>b?a:b;
}

int main()
{
	int totaltime,kind;
	scanf("%d%d",&totaltime,&kind);
	for (int i = 0; i < kind; i++)
	{
		scanf("%d%d",&buf[i].time,&buf[i].value);
	}

	for (int i = 0; i <=totaltime ; i++)
	{
		dp[0][i]=0;
	}

	for (int i = 1; i <= kind; i++)
	{
		for (int j = 0; j <= totaltime; j++)
		{
			if(j>=buf[i].time)
			{
				dp[i][j]=max(dp[i-1][j-buf[i].time]+buf[i].value,dp[i-1][j]);
			}
			else
				dp[i][j]=dp[i-1][j];
		}
	}

	printf("%d\n",dp[kind][totaltime]);
	system("pause");
	return 0;
}