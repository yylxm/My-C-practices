#include<iostream>
#include<queue>
#include<stdio.h>

using namespace std;

struct state
{
	int s,a,b;//��ʾ����ƿ���п��ֵ����
	int t;//���Ĵ���
};

queue<state> Q;

bool mark[100][100][100];
/**/
void AtoB(int &a,int sa,int &b,int sb)//sa,sb��ʾ���ӵ�������
{
	if (sb-b >= a)//��a����ȫ������b��
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

		/*s����a��*/
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

		s=now.s;//����a,b,c δ��ǰ�����
		a=now.a;
		b=now.b;

		AtoB(a,n,s,sum);//a����s��
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

		s=now.s;//����a,b,c δ��ǰ�����
		a=now.a;
		b=now.b;

		AtoB(s,sum,b,m);//s����b��
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

		s=now.s;//����a,b,c δ��ǰ�����
		a=now.a;
		b=now.b;

		AtoB(b,m,s,sum);//b����s��
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

		s=now.s;//����a,b,c δ��ǰ�����
		a=now.a;
		b=now.b;

		AtoB(a,n,b,m);//a����b��
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

		s=now.s;//����a,b,c δ��ǰ�����
		a=now.a;
		b=now.b;

		AtoB(b,m,a,n);//b����a��
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
		
		/*��ʼ��*/
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