#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;

bool Prime(int n)
{
	if(n==1||n==0)
		return false;
	int s=sqrt(n)+1;
	for(int i=2;i<s;++i)
	{
		if(n%s==0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int num;
	vector<int> primenum;
	cin>>num;
	int pnum[100];
	int pnumsize[20];
	int marksize=0;
	int mark;
	if (num==1||num==0)
	{
		cout<<"0"<<endl;
		return 0;
	}
	for (int i=2;i<=num;++i)//找到0~num范围内的所有素数
	{
		if(!Prime(num))
			continue;
		else
			primenum.push_back(i);
	}

	for (int mark=0;mark<primenum.size();++mark)
	{
		if (num%primenum[mark]==0)
		{
			pnum[mark]=primenum[mark];
			pnumsize[marksize]=0;
			while (num%primenum[mark]==0)
			{
				pnumsize[marksize]++;
				num=num/primenum[mark];
			}
			marksize++;
			if (num==1)//若在完成某个素数的幂指数统计后， n 变为 1，则表明 n 的所有素因数全部被分解出来，这样就不用再去遍历后续的素数，分解活动提前终止。
			{
				break;
			}
		}	
	}

	if(num!=1)
	{
		pnum[mark]=num;
		primenum[marksize]=1;
	}

	int sum=0;
	for (int i=0;i<marksize;++i)
	{
		sum=sum+pnumsize[i];
	}

	cout<<sum<<endl;


	system("pause");
	return 0;
}