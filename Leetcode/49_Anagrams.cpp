#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<string> anagrams(vector<string>& strs) {
		vector<string >res;
		int len = strs.size();
		map<string, int> anagramsHashtable;
		for (int  i = 0; i < len; i++)
		{
			string s = strs[i];
			sort(s.begin(), s.end());
			if (anagramsHashtable.find(s) == anagramsHashtable.end())
			{
				anagramsHashtable[s] = i;
			}
			else
			{
				if (anagramsHashtable[s] >= 0)//已经存在
				{
					res.push_back(strs[anagramsHashtable[s]]);//将先前存入的string输出，为了保证值输出一次，需将anangramsHashtable[s]置一
					anagramsHashtable[s] = - 1;
				}
				res.push_back(strs[i]);
			}
		}
		return res;
	}	
};

int main()
{
	string arr[] = { "m", "name", "is", "ana", "whw" };
	vector<string> svec(arr, arr + 5);
	Solution s;
	vector<string >ret;
	ret = s.anagrams(svec);
	for (auto iter = ret.begin(); iter != ret.end() ; iter++)
	{
		cout<< *iter <<" ";
	}
	cout << endl;
	system("pause");
	return 0;
}