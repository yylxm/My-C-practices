#include<iostream>
#include<queue>
#include<stdio.h>

using namespace std;

struct state
{
	int s,a,b;//表示三个瓶子中可乐的体积
	int t;//倒的次数
};

queue<state> Q;

bool mark[100][100][100];
/**/
void AtoB(int &a,int sa,int &b,int sb)//sa,sb表示杯子的最大体积
{
	if (sb-b >= a)//若a可以全部倒到b中
	{
		b+=a;
		a=0;
	}
	else
	{
		a=a-(sb-b);
		b=sb;
	}
}

int BFS(int sum,int n,int m)
{
	while (!Q.empty())
	{
		state now=Q.front();
		Q.pop();
		int s,a,b;
		s=now.s;
		a=now.a;
		b=now.b;

		/*s倒到a中*/
		AtoB(s,sum,a,n);
		if (mark[s][a][b]==false)
		{
			mark[s][a][b]=true;
			state tmp;
			tmp.s=s;
			tmp.a=a;
			tmp.b=b;
			tmp.t=now.t+1;

			if(s==sum/2&&a==sum/2||s==sum/2&&b==sum/2||a==sum/2&&b==sum/2)
				return tmp.t;
			Q.push(tmp);
		}

		s=now.s;//重置a,b,c 未倒前的体积
		a=now.a;
		b=now.b;

		AtoB(a,n,s,sum);//a倒到s中
		if (mark[s][a][b]==false)
		{
			mark[s][a][b]=true;
			state tmp;
			tmp.s=s;
			tmp.a=a;
			tmp.b=b;
			tmp.t=now.t+1;

			if(s==sum/2&&a==sum/2||s==sum/2&&b==sum/2||a==sum/2&&b==sum/2)
				return tmp.t;
			Q.push(tmp);
		}

		s=now.s;//重置a,b,c 未倒前的体积
		a=now.a;
		b=now.b;

		AtoB(s,sum,b,m);//s倒到b中
		if (mark[s][a][b]==false)
		{
			mark[s][a][b]=true;
			state tmp;
			tmp.s=s;
			tmp.a=a;
			tmp.b=b;
			tmp.t=now.t+1;

			if(s==sum/2&&a==sum/2||s==sum/2&&b==sum/2||a==sum/2&&b==sum/2)
				return tmp.t;
			Q.push(tmp);
		}

		s=now.s;//重置a,b,c 未倒前的体积
		a=now.a;
		b=now.b;

		AtoB(b,m,s,sum);//b倒到s中
		if (mark[s][a][b]==false)
		{
			mark[s][a][b]=true;
			state tmp;
			tmp.s=s;
			tmp.a=a;
			tmp.b=b;
			tmp.t=now.t+1;

			if(s==sum/2&&a==sum/2||s==sum/2&&b==sum/2||a==sum/2&&b==sum/2)
				return tmp.t;
			Q.push(tmp);
		}

		s=now.s;//重置a,b,c 未倒前的体积
		a=now.a;
		b=now.b;

		AtoB(a,n,b,m);//a倒到b中
		if (mark[s][a][b]==false)
		{
			mark[s][a][b]=true;
			state tmp;
			tmp.s=s;
			tmp.a=a;
			tmp.b=b;
			tmp.t=now.t+1;

			if(s==sum/2&&a==sum/2||s==sum/2&&b==sum/2||a==sum/2&&b==sum/2)
				return tmp.t;
			Q.push(tmp);
		}

		s=now.s;//重置a,b,c 未倒前的体积
		a=now.a;
		b=now.b;

		AtoB(b,m,a,n);//b倒到a中
		if (mark[s][a][b]==false)
		{
			mark[s][a][b]=true;
			state tmp;
			tmp.s=s;
			tmp.a=a;
			tmp.b=b;
			tmp.t=now.t+1;

			if(s==sum/2&&a==sum/2||s==sum/2&&b==sum/2||a==sum/2&&b==sum/2)
				return tmp.t;
			Q.push(tmp);
		}
	}
	return -1;
}

int main()
{
	int sum,a,b;
	scanf("%d%d%d",&sum,&a,&b);
	
	while (sum!=0 && a!=0 && b!=0)
	{
		if(sum&1==1)
	    {
		     printf("No\n");
			 scanf("%d%d%d",&sum,&a,&b);
		     continue;
	    }
		for (int i = 0; i <= sum; i++)
		{
			for (int j = 0; j <=a; j++)
			{
				for (int k = 0; k <=b; k++)
				{
					mark[i][j][k]=false;
				}
			}
		}
		
		/*初始化*/
		while (!Q.empty())
		{
			Q.pop();
		}
		state tmp;
		tmp.s=sum;
		tmp.a=0;
		tmp.b=0;
		tmp.t=0;
		Q.push(tmp);
		mark[sum][a][b]=true;

		int ret=BFS(sum,a,b);
		if(ret==-1)
			printf("No\n");
		else
		{
			printf("%d\n",ret);
		}
		
		scanf("%d%d%d",&sum,&a,&b);
	}
	system("pause");
	return 0;
}