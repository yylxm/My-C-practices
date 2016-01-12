/*#include<iostream>
#include<math.h>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {//将除法转换为减法，出现超时
		int ret=0;
        if(dividend==0)
			return 0;
		if(dividend>0 &&divisor==0) return INT_MAX;
		if(dividend<0 &&divisor ==0)return INT_MIN;
		if(dividend>0 &&divisor>0)
		{
			while(dividend>=divisor)
			{
				ret++;
				dividend=dividend-divisor;
			}
		}
		else if(dividend<0 && divisor<0)
		{
			dividend=0-dividend;
			divisor=0-divisor;
			while(dividend>=divisor)
			{
				ret++;
				dividend=dividend-divisor;
			}
		}
		else if(dividend<0 && divisor>0)
		{
			dividend=0-dividend;
			while(dividend>=divisor)
			{
				ret++;
				dividend=dividend-divisor;
			}
			ret=0-ret;

		}
		else if(dividend>0 && divisor<0)
		{
			divisor=0-divisor;
			while(dividend>=divisor)
			{
				ret++;
				dividend=dividend-divisor;
			}
			ret=0-ret;
		}	
		return ret;
    }

	int divide2(int dividend, int divisor) {//将除法转换为指数运算
		if(dividend==0) return 0;
		if(divisor==0) return INT_MAX;
		long long ret=double(exp(log(fabs(double(dividend)))-log(fabs(double(divisor)))));
		if((dividend<0)^(divisor<0)) return -ret;
		if(ret>INT_MAX) return INT_MAX;
		return ret;
	}
};

int main()
{
	Solution s;
	int dividend,divisor;
	cin>>dividend;
	cin>>divisor;
	int ret=s.divide2(dividend,divisor);
	cout<<ret<<endl;
	system("pause");
	return 0;
}*/

#include <stdio.h>
#include <malloc.h>
#include <iostream>
using namespace std;
    struct Test  
    {  
        int size;  
    //  int arr[];//两种方法均可  
        int arr[0];  
    };  
      
      
    int main()  
    {  
        printf("%d\n",sizeof(Test));  
        int len = 10;  
        Test* pTest = (Test*)malloc(sizeof(Test) + len * sizeof(int));  
        pTest->size = len;  
        for(int i = 0; i < len; ++i)  
            pTest->arr[i] = i;  
      
        //for(int i = 0; i < pTest->size;++i)  
         //   printf("%d\n",pTest->arr[i]);  
        printf("%d\n",sizeof(Test));  
        printf("%d\n",sizeof(*pTest));  
        delete pTest;
		system("pause");
        return 0;  
    }  