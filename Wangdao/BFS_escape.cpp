#include<iostream>
#include<queue>
#include<stdio.h>

using namespace std;

struct state//״̬
{
	int x,y,z;//����
	int t;//����
};

int mark[50][50][50];//����������Ƿ񱻷��ʹ�
int cube[50][50][50];//������������Ϣ

queue<state> Q;

int go[][3]={//����仯����
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
		state now=Q.front();//�õ���ͷ״̬
		Q.pop();
		for (int i = 0; i < 6; i++)//������չ�������ڽڵ�
		{
			int nx=now.x+go[i][0];//����µ�����
			int ny=now.y+go[i][1];
			int nz=now.z+go[i][2];

			if (nx<0||nx>=a||ny<0||ny>=b||nz<0||nz>=c)
			{
				continue;//�����������ڣ�����������
			}

			if(cube[nx][ny][nz]==1||mark[nx][ny][nz]==true)continue;//��λ��Ϊǽ���Ǹ�״̬�Ѿ������ʹ�������
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
		/*��ʼ������*/
		while (Q.empty()==false) //��ն���
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