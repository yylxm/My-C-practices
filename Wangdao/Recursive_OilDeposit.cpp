#include<iostream>
#include<stdio.h>

using namespace std;

char ans[101][101];
bool mark[101][101];

int go[][2]={1,0,-1,0,0,1,0,-1,1,1,1,-1,-1,-1,-1,1};
int n,m;

void DFS(int x,int y)
{
	for (int i = 0; i < 8; i++)
	{
		int nx=x+go[i][0];
		int ny=y+go[i][1];

		if(nx<1||nx>n||ny<1||ny>m) continue;

		if(ans[nx][ny]=='*'||mark[nx][ny]==true)continue;
		mark[nx][ny]=true;
		DFS(nx,ny);
	}
	return ;
}

int main()
{
	while (scanf("%d%d",&m,&n))
	{
		if(m==0)break;
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				scanf("%c",&ans[i][j]);
				mark[i][j]=false;
			}
		}

		int ret=0;
	    for (int i = 1; i <= n; i++)
	   {
		    for (int j = 1; j <= m; j++)
		    {
			     if(mark[i][j]==true||ans[i][j]=='*') continue;
			     DFS(i,j);
			     ret++;
		    }
	    }

		printf("%d",ret);
	}
	
	
	system("pause");
	return 0;
}