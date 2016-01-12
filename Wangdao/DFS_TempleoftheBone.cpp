#include<iostream>
#include<stdio.h>

using namespace std;

int n,m,T;
char maze[8][8];
bool success;
int go[][2]={-1,0,1,0,0,1,0,-1};

void DFS(int x,int y,int time)
{
	for (int i = 0; i < 4; i++)
	{
		int nx=x+go[i][0];
		int ny=y+go[i][1];

		if(nx<1||nx>n||ny<1||ny>m)continue;
		if(maze[nx][ny]=='X') continue;
		if (maze[nx][ny]=='D')
		{
			if(time+1==T)
			{
				success=true;
				return ;
			}
			else
				continue;
		}

		maze[nx][ny]='X';
		DFS(nx,ny,time+1);
		maze[nx][ny]='.';
		if(success) return;
	}
}

int main()
{
	scanf("%d%d%d",&n,&m,&T);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s",maze[i]+1);
	}

	/*for (int i = 1; i <=n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			scanf("%c",&maze[i][j]);
		}
	}*/

	success=false;
	DFS(1,1,0);
	if(success)
		printf("Yes!\n");
	else
		printf("No!\n");

	system("pause");
	return 0;
}