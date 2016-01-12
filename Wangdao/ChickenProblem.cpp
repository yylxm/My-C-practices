#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		for (int x = 0; x <=100 ; x++)
		{
			for (int y = 0; y <=100-x ; y++)
			{
				if(5*x*3+3*y*3+(100-x-y)<=3*n)
					printf("x=%d,y=%d,z=%d\n",x,y,100-x-y);
			}
		}

	}
	
	system("paus");
	return 0;
}