#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
#define INF 0x7fffffff

int main()
{
	int n,k;
	int arr[100];
	int a;
	int dp[100][200];
	scanf("%d%d",&n,&k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d",&arr[i]);
	}

	sort(arr+1,arr+n+1);
	
	for (int j = 1; j <=n; j++)
	{
		dp[0][j]=0;
	}

	for (int i = 1; i <=k ; ++i)
	{
		for (int j = 2*i; j <= n; ++j)
		{			
			if (j>2*i)
			{
				dp[i][j]=dp[i][j-1];
			}
			else
			{
				dp[i][j]=INF;
			}
			if(dp[i][j]>(dp[i-1][j-2]+(arr[j]-arr[j-1])*(arr[j]-arr[j-1])))
			   dp[i][j]=dp[i-1][j-2]+(arr[j]-arr[j-1])*(arr[j]-arr[j-1]);
		}
	}

	cout<<dp[k][n]<<endl;
	system("pause");
	return 0;
}