#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {//KMP算法，但在LeetCode上测试超时
		if(needle.size()==0) return -1;
        int hlen=haystack.size();
		int nlen=needle.size();
		int next[100];
		getnext(needle,next);
		int i=0;
		int j=0;
		while(i<hlen&&j<nlen)
		{
			if(j==-1 || haystack[i]==needle[j])
			{
				i++;
				j++;
			}
			else
			{
				j=next[j];
			}
		}

		if(j==nlen)
			return i-j;
		else
			return -1;
    }

	void getnext(string p,int next[])
	{
		int len=p.size();
		next[0]=-1;
		int k=-1;
		int j=0;
		while(j<len-1)
		{
			if(k==-1 || p[j]==p[k])
			{
				++j;
				++k;
				if(p[j]!=p[k])
				{
					next[j]=k;
				}
				else
					next[j]=next[k];
			}

			else
			{
				k=next[k];
			}
		}
	}
	 int strStr2(string haystack, string needle) {//暴力匹配算法
		 int hlen=haystack.size();
		 int nlen=needle.size();
		 int i=0;
		 int j=0;
		 while(i<hlen &&j<nlen)
		 {
			 if(haystack[i]==needle[j])
			{
				 i++;
				 j++;
			 }
			 else
			 {
				 i=i-j+1;
				 j=0;
			 }
		 }
		 if(j==nlen)
		 {
			 return i-j;
		 }
		 else
			 return -1;
	 }
};

int main()
{
	string haystack;
	cin>>haystack;
	string needle;
	cin>>needle;
	Solution s;
	int ret=s.strStr2(haystack,needle);
	cout<<ret<<endl;
	system("pause");
	return 0;
}