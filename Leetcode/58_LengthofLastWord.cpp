#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int lengthOfLastWord(string s) {
		int len = s.size();
		int result = 0;
		for (int i = len-1; i >=0 ; i--)
		{
			if (s[i] != ' ')
			{
				while (i>=0 && s[i]!=' ' )
				{
					result++;
					i--;
				}
				return result;
			}		
		}
		return result;
	}
};

int main()
{
	string str = "   a  ";
	Solution s;
	int ret = s.lengthOfLastWord(str);
	cout << ret << endl;
	system("pause");
	return 0;
}