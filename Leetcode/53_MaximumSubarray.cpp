#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int sum = nums[0];
		int max = nums[0];
		for (int  i = 1; i < nums.size(); i++)
		{
			if ((sum + nums[i]) > nums[i])
			{
				sum = sum + nums[i];
			}
			else
				sum = nums[i];
			if (sum>max)
				max = sum;
		}
		return max;
	}
};

int main()
{
	Solution s;
	int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	vector<int>ivec(arr, arr + 9);
	int ret = s.maxSubArray(ivec);
	cout << ret << endl;
	system("pause");
	return 0;
}