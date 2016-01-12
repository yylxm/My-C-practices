#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

#define Maxval 0x7FFFFFFF;
int ans[100][100];
int dist[100];

vector<int> S,VMS;

void Dijkstra(int n)//����ӿ�ʼ�ڵ㵽���һ���ڵ�����·��
{
	/*��ʼ���ڵ㼯��*/
	S.push_back(1);
	for(int i=2;i<=n;++i)
		VMS.push_back(i);

	/*��ʼ������ֵ*/
	for(auto iter=VMS.begin();iter!=VMS.end();++iter)
	{
		dist[*iter]=ans[1][*iter];
	}

	while (!VMS.empty())
	{
		int mindist=Maxval;
		int mark;
		for(auto iter=VMS.begin();iter!=VMS.end();++iter)//�ҳ�������С�ĵ�
		{
			if(dist[*iter]<mindist)
			{
				mindist=dist[*iter];
				mark=(*iter);
			}
		}

		for(auto iter=VMS.begin();iter!=VMS.end();++iter)//��VMS������ɾ���ýڵ�
		{
			if((*iter)==mark)
			{
				VMS.erase(iter);
				break;
			}
		}

		S.push_back(mark);//S�����м���ýڵ�

		if(!VMS.empty())//����dist��ֵ
		{
			for (auto iter=VMS.begin();iter!=VMS.end();++iter)
			{
				if(ans[mark][*iter]!=-1)
				{
					if(dist[*iter]>dist[mark]+ans[mark][*iter])
					{
						dist[*iter]=dist[mark]+ans[mark][*iter];
					}
				}
			}
		}
	}

	printf("%d",dist[n]);

}

void print(int n)
{

}

int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	
	while (N!=0 && M!=0)
	{
		int b,e,cost;

	    for(int i=1;i<=N;++i)//��ʼ��·��
	    {
		     for(int j=1;j<=N;++j)
		     {
			      ans[i][j]=-1;//��-1��������
		     }
		     ans[i][i]=0;
	    }

	    for(int i=1;i<=M;++i)
	    {
		     scanf("%d%d%d",&b,&e,&cost);
		     ans[b][e]=cost;
			ans[e][b]=cost;
	     }
	     Dijkstra(N);
	  //   print(N);
	     scanf("%d%d",&N,&M);
	}
	system("pause");
	return 0;
}