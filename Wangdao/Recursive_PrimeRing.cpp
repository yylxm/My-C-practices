#include<iostream>
#include<stdio.h>
#include<string>

using namespace std;

int ans[21];
int mark[21];
int n;
bool isprime(int n)
{
	int tmp=sqrt(n)+1;
	if(n==2)
		return true;
	for (int i = 2; i <=tmp; i++)
	{
		if(n%i==0)
			return false;
	}
	return true;
}

void print()
{
	if(!isprime(ans[1]+ans[n])) return;
	for (int i = 1; i <= n; i++)
	{
		if(i!=1)
			printf(" ");
		printf("%d",ans[i]);
	}
	printf("\n");
}

void DFS(int num)
{
	if(num>1)
		if(!isprime(ans[num]+ans[num-1])) return ;
	if(num==n)
	{
		print();
		return ;
	}

	for (int i = 2; i <=n ; i++)
	{
		if(mark[i]==false)
		{
			mark[i]=true;
			ans[num+1]=i;
			DFS(num+1);
			mark[i]=false;
		}
	}
}

int main()
{
	int cas=0;
	while (scanf("%d",&n)!=EOF)
	{
		/*³õÊ¼»¯*/
		cas++;
		for (int i = 0; i < 21; i++)
		{
			mark[i]=false;
		}
		ans[1]=1;
		printf("case %d:\n",cas);
		mark[1]=true;

		DFS(1);

		printf("\n");
	}
	system("pause");
	return 0;
}