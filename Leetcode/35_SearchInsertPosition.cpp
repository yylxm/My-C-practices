#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int length = nums.size();
		int begin = 0;
		int end = length - 1;

		while (begin <= end)
		{
			int middle = (begin + end) >> 1;

			if (nums[middle] == target)
				return middle;
			else if (nums[middle] < target)
			{
				begin = middle + 1;
			}
			else
				end = middle - 1;
		}

		if (begin>end)
		{
			return begin;
		}

	}
};

int main()
{
	int arr[] = { 1,2,3,5 };
	vector<int> ivec(arr, arr + 4);
	Solution s;
	int ret;
	ret = s.searchInsert(ivec, 1);
	cout <<ret<< endl;
	system("pause");
	return 0;
}