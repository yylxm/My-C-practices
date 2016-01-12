#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {//中心扩展法
        string result="";
		int Size=s.size();
		if(Size==0||Size==1) return result;
		
		for(int i=0;i<Size-1;++i)
		{
			string p1=expandAroundCenter(s,i,i);//奇数
			if(p1.size()>result.size())
				result=p1;
			string p2=expandAroundCenter(s,i,i+1);//偶数
			if(p2.size()>result.size())
				result=p2;
		}
		return result;
    }

	string expandAroundCenter(string s,int l,int r)
	{
		int n=s.size();
		while(l>=0&&r<=n-1&&s[l]==s[r])
		{
			l--;
			r++;

		}
		return s.substr(l+1,r-l-1);
	}
};

int main()
{
	string str,ret;
	cin>>str;
	Solution s;
	ret=s.longestPalindrome(str);
	cout<<ret<<endl;
	system("pause");
	return 0;
}