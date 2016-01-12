#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        double sum=0;
		if(x==0) return 0;
		else if(x<0)//处理负数
		{
			x=-x;
			while(x>0)
		    {
			    int temp=x%10;
			    x=x/10;
			    sum=sum*10+temp;
		    }
			sum=0-sum;
			if(sum<INT_MIN) return 0;//溢出
			else return sum;
		}
		else//处理正数
		{
			while(x>0)
		    {
			    int temp=x%10;
			    x=x/10;
			    sum=sum*10+temp;
		    }
			if(sum>INT_MAX) return 0;//溢出
			else return sum;
		}
    }
};

int main()
{
	Solution s;
	int ret,num;
	cin>>num;
	ret=s.reverse(num);
	cout<<ret<<endl;
	system("pause");
	return 0;
}