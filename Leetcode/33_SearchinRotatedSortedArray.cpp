#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int length = nums.size();
		int ret;
		return BinarySearch(nums, 0, length - 1, target);
	}

	int  BinarySearch(vector<int>& nums, int b, int e, int target)
	{		
		if (target == nums[b])
			return b;
		if (target == nums[e])
			return e;
		while (b<e-1)
		{
			int middle = (b + e) / 2;	
			if (target == nums[middle])
				return middle;
			if (nums[b] <= nums[middle]) //中点左边有序
			{
				if (nums[b] <= target && target <= nums[middle])
				{
					e = middle;
				}
				else
					b = middle;
			}
 			else //中点右边有序
			{
				if (nums[middle] <= target && target <= nums[e])
					b = middle;
				else
					e = middle;
			}
		}
		return -1;
	}
};

int main()
{
	int arr[] = {0, 1, 2, 4, 5, 6, 7, 8,9  };
	vector<int> ivec(arr, arr + 9);
	Solution s;
	int ret;
	ret = s.search(ivec,7);
	cout << ret << endl;
	system("pause");
	return 0;
}