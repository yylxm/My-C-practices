#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
	bool isAnagram(string s, string t) {
		int hashtable[26] = { 0 };
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] >= 'A' && s[i] <= 'Z')
			{
				hashtable[s[i] - 65]++;
			}
			else
			{
				hashtable[s[i] - 97]++;
			}			
		}
		for (int i = 0; i < t.size(); i++)
		{
			if (t[i] >= 'A' && t[i] <= 'Z')
			{
				hashtable[t[i] - 65]--;
			}
			else
			{
				hashtable[t[i] - 97]--;
			}
		}
		for (int i = 0; i < 26; ++i)
		{
			if (hashtable[i] != 0)
				return false;
		}
		return true;
	}
};

int main()
{
	Solution s;
	string str = "anagram";
	string str2 = "nagaram";
	bool ret = s.isAnagram(str, str2);
	if (ret)
		cout << "Yes!" << endl;
	else
		cout << "No!" << endl;
	system("pause");
	return 0;
}