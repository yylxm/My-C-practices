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
				if (anagramsHashtable[s] >= 0)//�Ѿ�����
				{
					res.push_back(strs[anagramsHashtable[s]]);//����ǰ�����string�����Ϊ�˱�ֵ֤���һ�Σ��轫anangramsHashtable[s]��һ
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