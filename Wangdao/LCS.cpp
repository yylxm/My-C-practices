#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>

using namespace std;

int max(int a,int b)
{
	return a>b ? a:b;
}

int main()
{
	string a,b;
	cin>>a;
	cin>>b;

	int dp[100][100];
	int lena=a.size();
	int lenb=b.size();
	for (int i = 0; i < lena; i++)
	{
		dp[i][0]=0;
	}

	for (int j = 0; j < lenb; j++)
	{
		dp[0][j]=0;
	}

	for (int i = 1; i < lena; i++)
	{
		for (int j = 1; j < lenb; j++)
		{
			if(a[i]==b[j])
				dp[i][j]=dp[i-1][j-1]+1;
			else
			{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}

	cout<<dp[lena-1][lenb-1]<<endl;;

	system("pause");
	return 0;

}