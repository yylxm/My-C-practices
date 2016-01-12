#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

struct goods 
{
	double weigt;
	double value;
	double rate;
	bool operator <(const goods &a)const 
	{
		return rate>a.rate;
	}

}buf[100];


int main()
{
	cout<<"Please enter M and N:";
	double M;
	int N;
	double sum=0;
	scanf("%lf%d",&M,&N);
	for(int i=0;i<N;++i)
	{
		scanf("%lf%lf",&buf[i].value,&buf[i].weigt);
		buf[i].rate=buf[i].value/buf[i].weigt;
	}

	sort(buf,buf+N);

	while (M>0)
	{
		for(int i=0;i<N;++i)
		{
			if(M>buf[i].weigt)
			{
				sum=sum+buf[i].value;
				M=M-buf[i].weigt;
			}
			else
			{
				sum=sum+(M/buf[i].weigt*buf[i].value);
				M=0;
			}
		}
	}

	printf("%lf",sum);

	system("pause");
	return 0;
}