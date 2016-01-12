#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string countAndSay(int n) {
		string src = "1";
		if (n == 1)//注意初始情况要单独处理
			return src;
		string dest;
		for (int  i = 1; i < n; i++)
		{
			int count = 0;
			dest = "";
			char sub;
			for (int  j = 0; j < src.size(); j++)
			{
				if (count == 0)
				{
					sub = src[j];
					count++;
				}
				else if (sub == src[j])
				{
					count++;
				}
				else
				{
					char c = count + '0';
					dest = dest + c + sub;
					count = 1;
					sub = src[j];
				}
			}
			if (count!=0)
			{
				char c = count + '0';
				dest = dest + c + sub;
			}
			src = dest;				
		}
		return dest;
	}
};

int main()
{
	Solution s;
	string ret;
	ret = s.countAndSay(1);
	cout << ret << endl;
	system("pause");
	return 0;
}
