#include<iostream>
#include<stdio.h>
#include<queue>
#include<map>
#include<string>

using namespace std;
map<string,int> M;

struct match
{
	char winner[100];
	char loser[100];
}buf[100];

int main()
{
	int n;
	cin>>n;
	int in[200];
	for (int i = 1; i <= 2*n; i++)//初始化入度，n场比赛最多2n个队伍
	{
		in[i]=0;
	}
	M.clear();
	int index=1;

	for (int i = 1; i <= n; i++)
	{
		char ac[100],bc[100];
		int ia,ib;
		scanf("%s%s",&ac,&bc);
		string a=ac;
		string b=bc;
		if(M.find(a)==M.end())
		{
			ia=index;
			M[a]=index++;
		}
		else
		{
			ia=M[a];
		}

		if(M.find(b)==M.end())
		{
			ib=index;
			M[b]=index++;
		}
		else
		{
			ib=M[b];
		}

		in[ib]++;//b的入度加1
	}

	int cnt=0;
	for (int i = 1; i <= index; i++)
	{
		if(in[i]==0)
			cnt++;
	}

	puts(cnt==1?"Yes":"No");

	system("pause");
	return 0;
}