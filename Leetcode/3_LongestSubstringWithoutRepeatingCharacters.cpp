#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		if(s.size()==0) return 0;
		if(s.size()==1) return 1;
		
		int max=0;
		string p=s;

		for(int i=0;i<s.size()-1;++i)
		{
			int num=0;
			bool arr[100]={false};//hash表对每个字符做映射
			for(int j=i;j<s.size();++j)
			{
				if(arr[s[j]-32]==true)//空格符（32），最小的可显示字符
				{
					if(num>max)
						max=num;
					break;
				}
				else 
				{
					arr[s[j]-32]=true;
					num++;
				}				
			}
			if(num>max)
				max=num;
			if(max>=(s.size()-i))//如果最大不连续子串的个数，剩余个数肯定小于现有的最大个数
				break;
		}
		return max;

    }
};

int main()
{
	string str;
	cin>>str;
	Solution s;
	int ret;
	ret=s.lengthOfLongestSubstring(str);
	cout<<ret<<endl;
	system("pause");
	return 0;
}