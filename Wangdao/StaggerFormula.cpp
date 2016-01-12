#include<stdio.h>

long long F[20];

int main()
{
	F[1]=0;
	F[2]=1;

	for (int i = 3; i < 19; i++)
	{
		F[i]=(i-1)*F[i-1]+(i-1)*F[i-2];
	}

	int n;
	while (scanf("%d",&n)!=EOF)
	{
		printf("%lld\n",F[n]);
	}
}