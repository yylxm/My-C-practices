#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int length = nums.size();
		if (nums.size() == 0)
			return 1;
		if (nums.size() == 1)
		{
			if (nums[0] > 1)
				return nums[0] - 1;
			else if (nums[0] == 1)
				return 2;
			else
				return 1;
		}
		sort(nums.begin(), nums.end());
		if (nums[length - 1] <= 0)
			return 1;
		int k = -1;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] <= 0)
				continue;
			if (i!=0 && nums[i-1]<=0&& nums[i]>1)
				return nums[i] - 1;
			else
			{
				if (k == -1)
				{
					k = nums[i];
				}
				else
				{
					if (i == length - 1)
						return nums[i] + 1;
					if (nums[i] == k + 1 || nums[i]== k)
						continue;
					else
						return k + 1;
				}
			}
		
		}
	}
};*/


/*如果nums[i]=5,将其置换到nums[4]处存放*/
class Solution
{
public:
	int firstMissingPositive(vector<int>& nums) {
		int len = nums.size();
		for (int i = 0; i < len; i++) 
		{
			while (nums[i]>0 && nums[i] <= len && nums[nums[i] - 1] != nums[i])
				swap(nums[i], nums[nums[i] - 1]);
		}
		for (int  i = 0; i < len; i++)
		{
			if (nums[i] != i + 1)
				return i + 1;
		}
		return len + 1;
	}

};

int main()
{
	int arr[] = {-1,-3,1,2};
	vector<int> ivec(arr,arr+4);
	Solution s;
	int ret = s.firstMissingPositive(ivec);
	cout << ret << endl;
	system("pause");
	return 0;
}