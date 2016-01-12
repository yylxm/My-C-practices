#include <iostream>

using namespace std;

class Solution {
public:
	bool isPalindrome(int x);

	int powTen(int x);
};


bool Solution::isPalindrome(int x)
{
	int tmp=x;
	int a=1;

	if(x<0) return false;

	while (tmp/a>=10)
	{
		a=a*10;
	}

	while (tmp>0)
	{
		if(tmp/a!=tmp%10) return false;
		tmp=tmp%a;//去掉x的最高位
		tmp=tmp/10;//去掉x的最低位
		a=a/100;
	}
	return true;
}


int main()
{
	Solution s;

	int num;
	cin>>num;

	if(s.isPalindrome(num))
		cout<<"Yes!"<<endl;
	else
		cout<<"No!"<<endl;
	
	system("pause");
	return 0;
}