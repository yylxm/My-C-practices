#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool canJump(vector<int>& nums) {
		int len = nums.size();
		int start = 0;
		for (int  i = 0; i < len; i++)
		{
			start = max(start, nums[i]);
			if (start+i>=len-1)
			{
				return true;
			}
			if (start == 0)
				return false;
			start--;
		}
		return false;
	}
};


int main()
{
	int arr[] = { 3, 2, 1, 0, 4 };
	vector<int> ivec(arr, arr + 5);
	Solution s;
	bool ret = s.canJump(ivec);
	if (ret)
		cout << "Yes!" << endl;
	else
		cout << "No!" << endl;
	system("pause");
	return 0;
}