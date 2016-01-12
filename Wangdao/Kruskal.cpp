#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

#define N 1000
int Tree[N];

struct edge
{
	int head;
	int tail;
	int cost;
	bool operator<(const edge A) const
	{
		return cost<A.cost;
	}
}buf[100];

int findRoot(int x)
{
	int ret;
	while (Tree[x]!=-1)
	{
		x=Tree[x];
	}
	ret=x;
	return ret;
}

int main()
{
	int Vectex;
	while (scanf("%d",&Vectex)!=EOF)
	{
		for(int i=1;i<=Vectex;++i)
		{
			Tree[i]=-1;
		}
		int edg=Vectex*(Vectex-1)/2;
		for(int i=1;i<=edg;++i)
		{
			scanf("%d%d%d",&buf[i].head,&buf[i].tail,&buf[i].cost);
		}
		sort(buf+1,buf+1+edg);
		int ans=0;
		for(int i=1;i<=edg;++i)
		{
			int a=findRoot(buf[i].head);
			int b=findRoot(buf[i].tail);
			if(a!=b)
			{
				Tree[a]=b;
				ans+=buf[i].cost;
			}
		}

		printf("%d\n",ans);
	}

	system("pause");
	return 0;
}