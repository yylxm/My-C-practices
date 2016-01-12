#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
		vector<vector<int> > ret;
		vector<int > combination;
		sort(candidates.begin(), candidates.end());
		combinationSum(candidates, target, ret, combination, 0);
		return ret;
	}

private:
	void combinationSum(vector<int> &candidates, int target, vector<vector<int> > &ret, vector<int> &combination, int begin)
	{
		if (!target)//已经搜索到一个答案
		{
			ret.push_back(combination);
			return;
		}

		for (int i = begin; i < candidates.size() && target >= candidates[i]; i++)
		{
			if (i == begin || candidates[i] != candidates[i - 1]){//巧妙的避免了，当i=0时，i-1会出现溢出的现象
				combination.push_back(candidates[i]);
				combinationSum(candidates, target - candidates[i], ret, combination, i+1);//递归搜索
				combination.pop_back();//若该集合不满足条件，则弹出
			}
			
		}
	}
};

int main()
{

	system("pause");
	return 0;
}