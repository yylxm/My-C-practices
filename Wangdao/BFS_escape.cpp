#include<iostream>
#include<queue>
#include<stdio.h>

using namespace std;

struct state//状态
{
	int x,y,z;//坐标
	int t;//代价
};

int mark[50][50][50];//标记立方体是否被访问过
int cube[50][50][50];//标记立方体的信息

queue<state> Q;

int go[][3]={//坐标变化数组
1,0,0,
-1,0,0,
0,1,0,
0,-1,0,
0,0,1,
0,0,-1
};

int BFS(int a,int b,int c)
{
	while (Q.empty()==false)
	{
		state now=Q.front();//得到堆头状态
		Q.pop();
		for (int i = 0; i < 6; i++)//依次扩展六个相邻节点
		{
			int nx=now.x+go[i][0];//获得新的坐标
			int ny=now.y+go[i][1];
			int nz=now.z+go[i][2];

			if (nx<0||nx>=a||ny<0||ny>=b||nz<0||nz>=c)
			{
				continue;//不在正方体内，丢弃该坐标
			}

			if(cube[nx][ny][nz]==1||mark[nx][ny][nz]==true)continue;//该位置为墙或是该状态已经被访问过，则丢弃
		    state tmp;
			tmp.x=nx;
			tmp.y=ny;
			tmp.z=nz;
			tmp.t=now.t+1;
			Q.push(tmp);
			mark[nx][ny][nz]=true;

			if(nx==a-1 && ny==b-1 && nz==c-1)return tmp.t;
		}

	}
	return -1;
}

int main()
{
    int k;
	scanf("%d",&k);
	while (k--)
	{
		int a,b,c,time;
		scanf("%d%d%d%d",&a,&b,&c,&time);
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < b; j++)
			{
				for (int k = 0; k < c; k++)
				{
					scanf("%d",&cube[i][j][k]);
					mark[i][j][k]=false;
				}
			}
		}
		/*初始化操作*/
		while (Q.empty()==false) //清空队列
		{
			Q.pop();
		}
		mark[0][0][0]=true;
		state tmp;
		tmp.x=0;
		tmp.y=0;
		tmp.z=0;
		tmp.t=0;
		Q.push(tmp);

		int ret=BFS(a,b,c);

		if(ret<=time) printf("%d\n",ret);
		else
		{
			printf("-1\n");
		}
	}

	system("pause");
	return 0;
}