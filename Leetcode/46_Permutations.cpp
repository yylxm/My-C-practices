#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	void permuteBacking(vector<int >nums,vector<vector<int> >&result, int i, int n)
	{//×¢Òâ´Ë´¦
		if (i==n)
		{
			result.push_back(nums);
			return;
		}
		for (int j = i; j <=n ; j++)
		{
			if (i != j && nums[j] == nums[j - 1]) continue;
			swap(nums[j], nums[i]);								
			permuteBacking(nums, result, i + 1, n);
		}
	}
	vector<vector<int> > permuteUnique(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector< vector <int> >ret;
		permuteBacking(nums, ret, 0, nums.size() - 1);
		return ret;
	}
};

int main()
{
	int arr[] = { 1,2,3 };
	vector<int> ivec(arr, arr + 3);
	Solution s;
	vector<vector<int> >ret;
	ret = s.permuteUnique(ivec);
	for (auto iter = ret.begin(); iter != ret.end(); iter++)
	{
		for (auto iter2 = (*iter).begin(); iter2 != (*iter).end(); iter2++)
		{
			cout << *iter2 << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
