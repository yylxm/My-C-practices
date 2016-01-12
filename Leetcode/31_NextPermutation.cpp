#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int length = nums.size();
		
		int k = -1;		
		for ( int i = length-2; i >= 0; i--)
		{
			if (nums[i]>=nums[i + 1])
				continue;
			else
				k = i;
				break;
		}
		if (k == -1)//处理已是最大数的情况
		{
			 sort(nums.begin(),nums.end());
		}
		else
		{
			int index = -1;
			for (int  i = length-1; i > k; i--)
			{
				if (nums[i] > nums[k])
				{
					index = i;
					break;
				}
			}
			swap(nums[k], nums[index]);

			sort(nums.begin()+k + 1, nums.end());
		}
	}
};

int main()
{
	int arr[] = { 1,1 };
	vector<int> ivec{ arr, arr + 2 };
	Solution s;
	s.nextPermutation(ivec);
	for (int i = 0; i < 2; i++)
	{
		cout << ivec[i] << ",";
	}
	cout << endl;
	system("pause");
	return 0;
}