#include<iostream>
#include<stdio.h>
#include<queue>
#include<vector>

using namespace std;

int ans[100][100]={-1};

int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	while (N!=0)
	{
		int b,e;
		int in[100]={0};
		queue<int> inzero;
		vector<int> ret;
		for(int i=0;i<M;++i)
		{
			scanf("%d%d",&b,&e);
			ans[b][e]=1;
			in[e]++;
		}

		for(int i=0;i<N;++i)//找到所有入度为0的节点
		{
			if(in[i]==0)
				inzero.push(i);
		}

		while (!inzero.empty())
		{
			int tmp=inzero.front();
			inzero.pop();
			ret.push_back(tmp);
			for(int i=0;i<N;++i)
			{
				if(ans[tmp][i]==1)//存在边，则入读减1
				{
					in[i]--;
					if(in[i]==0)
					{
						ans[tmp][i]=-1;//删除该边
						inzero.push(i);
					}
							
					else
					{
						ans[tmp][i]=-1;
					}				  
				}
			}
		}

		if(ret.size()<N)
			cout<<"NO"<<endl;
		else
			cout<<"Yes"<<endl;
		scanf("%d%d",&N,&M);
	}
	system("pause");
	return 0;
}