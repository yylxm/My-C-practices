#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int jump(vector<int>& nums) {
		int len = nums.size();
		int start = 0;//每一跳的起始位置
		int end = 0;//每一跳的终止位置
		int jumps = 0;//跳数		
		for (int i = 0; i < len; i++)
		{
			if (i > end)
			{
				end = start;
				jumps++;
			}
			start = max(start, i + nums[i]);
		}
		return jumps;
	}
};

int main()
{
	//int arr[] = { 7, 0, 9, 6, 9, 6, 1, 7, 9, 0, 1, 2, 9, 0, 3 };
	int arr[] = { 2, 3, 1, 1, 4 };
	vector<int>ivec(arr, arr + 5 );
	Solution s;
	int ret = s.jump(ivec);
	cout << ret << endl;
	system("pause");
	return 0;
}
