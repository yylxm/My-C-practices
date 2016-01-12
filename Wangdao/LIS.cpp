#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int max(int a,int b)
{
	return a>b? a:b;
}

int main()
{
	int n;
	int a[100];
	int F[100];
	scanf("%d",&n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d",&a[i]);
	}

	F[1]=1;
	for (int i = 1; i <= n; i++)
	{
		int Max=1;
		for (int j = 1; j < i; j++)
		{
			if (a[j] >= a[i])
			{
				Max=max(Max, F[j]+1);
			}
		}
		F[i]=Max;
	}

	printf("%d\n",F[n]);

	system("pause");
	return 0;
}