#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
		vector<vector<int> > ret;
		vector<int > combination;
		combinationSum(candidates, target, ret, combination, 0);
		return ret;
	}

private:
	void combinationSum(vector<int> &candidates, int target, vector<vector<int> > &ret, vector<int> &combination, int begin)
	{
		if (!target)//�Ѿ�������һ����
		{
			ret.push_back(combination);
			return;
		}

		for (int  i = begin; i < candidates.size()&& target>=candidates[i]; i++)
		{
			combination.push_back(candidates[i]);
			combinationSum(candidates, target - candidates[i], ret, combination, i);//�ݹ�����
			combination.pop_back();//���ü��ϲ������������򵯳�
		}
	}
};

int main()
{
	int arr[] = { 2, 3, 6, 7 };
	vector<int> ivec(arr, arr + 4);
	Solution s;
	vector<vector<int> >ret;
	ret = s.combinationSum(ivec, 7);
	for (auto iter = ret.begin(); iter !=ret.end(); iter++)
	{
		cout << "[";
		for (auto iter2 = (*iter).begin(); iter2 !=(*iter).end(); iter2++)
		{
			cout << *iter2 << ",";
		}
		cout << "]";
	}
	system("pause");
	return 0;
}