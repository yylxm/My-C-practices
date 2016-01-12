#include <iostream>

using namespace std;
 /*负数会出现死循环
int Binary(int num)
{
	int count=0;
	while(num>0)
	{
		if(num&1==1)
			count++;
		num=num>>1;
	}
	return count;
}*/

int Binary(int num)
{
	int count=0;
	unsigned int flag=1;
	while (flag)
	{
		if(num&flag)
			count++;
		flag=flag<<1;
	}
	return count;
}

/*int main()
{
	int num;
	cin>>num;
	int ret=Binary(num);
	cout<<ret<<endl;
	system("pause");
	return 0;
}*/