#include<iostream>
#include<stdio.h>

using namespace std;

#define N 100

int findRoot(int *tree,int x)
{
	int ret;
	while(tree[x]!=-1)
	{
		x=tree[x];
	}
    ret=x;
	return ret;
}

int main()
{
	int town,road;
	scanf("%d%d",&town,&road);
	int Tree[N]={0};
	int ans=0;
	if(road==0)
	{
		ans=town-1;
		printf("%d",ans);
		system("pause");
		return 0;
	}
	for(int i=0;i<town;++i)
		Tree[i]=-1;
	while(road>0)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		a=findRoot(Tree,a);
		b=findRoot(Tree,b);
		if(a!=b)Tree[a]=b;
		road--;
	}
	for(int i=0;i<town;++i)
	{
		if(Tree[i]==-1)
			ans++;
	}
	printf("%d\n",--ans);
	system("pause");
	return 0;
}