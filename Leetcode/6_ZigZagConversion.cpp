#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string result="";
		if(numRows==1)return s;
		int num=numRows*2-2;//第一排的距离差
		int num2=num;
		int k=0;
			for(int j=0; j<numRows; ++j)
		    {
				bool flag=0;//用于判断除第一和最后一排的差距，”Z“字形
				for(int i=j; i<s.size();)
			     {	
				     k++ ;				
					 result=result+s[i];
					 if(k==s.size()) return result;
					 if(!flag&&num!=num2)
					 {
						 i=i+num;
						 flag=1;
					 }
					 else if(num!=num2)
					 {
						 i=i+num2-num;
						 flag=0;
					 }
					 else
						 i=i+num;
			     }
			     if(num>2)
			     {
				      num=num-2;
			     }
				 else if(num==2)
			     {
				     num=num2;
			     }
		    }
    }
};

int main()
{
	Solution s;
	string str,ret;
	int number;
	cin>>str;
	cin>>number;
	ret=s.convert(str,number);
	cout<<ret<<endl;
	system("pause");
	return 0;
}