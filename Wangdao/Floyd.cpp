#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	int N,M;
	int ans[100][100];
	int b,e,cost;
	scanf("%d%d",&N,&M);
	while (N!=0 && M!=0)
	{
		for(int i=1;i<=N;++i)
		{
			for(int j=1;j<=N;++j)
			{
				if(i==j)
					ans[i][j]=0;
				else
					ans[i][j]=-1;//初始化数组,-1代表负无穷
			}
		}
		for(int i=1;i<=M;++i)//输入边及权重
		{
			scanf("%d%d%d",&b,&e,&cost);
			ans[b][e]=cost;
			ans[e][b]=cost;//注意是无向图，对称
		}

		for(int k=1;k<=N;++k)
		{
			for(int i=1;i<=N;++i)
			{
				for(int j=1;j<=N;++j)
				{
					if(ans[i][k]==-1||ans[k][j]==-1)continue;
					if(ans[i][j]==-1||((ans[i][k]+ans[k][j])<ans[i][j]))
						ans[i][j]=ans[i][k]+ans[k][j];
				}
			}
		}

		printf("%d\n",ans[1][N]);//输出1-N的最短路径
		scanf("%d%d",&N,&M);
	}
	system("pause");
	return 0;
}