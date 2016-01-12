#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
	int myAtoi(string str);

};

int Solution::myAtoi(string str)
{
	double sum1=0; //注意使用double类型，防止溢出
	int tager=1;
	int j=0;
	while (str[j]==' ')
	{
		j++;
	}
	if(str[j]=='-')
	{
		tager =-1;
		j++;
	}
	else if (str[j]== '+')
	{
		j++;
	}
	if (str[j]<'0' || str[j]>'9')
	{
		return 0;
	}
	for (int i=j; i<str.size() ;++i)
	{		
		if(str[i]>='0' && str[i]<='9')
			sum1=sum1*10+str[i]-48;
		else 
			break;
		if (sum1>INT_MAX)
		{
			if (tager == -1)
			{
				return -2147483648;
			}
			else
				return 2147483647;
		}
	}
	if(tager!=0)
		sum1=sum1*tager;
	return sum1;
}

int main()
{
	Solution s;
	string str;
	cin>>str;
	cout<<s.myAtoi(str)<<endl;
	system("pause");
	return 0;
}