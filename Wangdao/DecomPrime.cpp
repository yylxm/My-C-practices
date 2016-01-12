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
	for (int i=2;i<=num;++i)//�ҵ�0~num��Χ�ڵ���������
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
			if (num==1)//�������ĳ����������ָ��ͳ�ƺ� n ��Ϊ 1������� n ������������ȫ�����ֽ�����������Ͳ�����ȥ�����������������ֽ���ǰ��ֹ��
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