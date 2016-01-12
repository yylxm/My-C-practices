#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

/* 解题思路：采用两个指针，一个指向开头，一个指向末尾，然后两个指针向中间移动。对于水桶蓄水，我们知道水量的多少往往取决于较短的夹板，所以
我们找出较短的那一个，即lower，然后扫描每一行，减去其高度即可。*/

class Solution {
public:
	int trap(vector<int>& height) {
		int l = 0, r = height.size() - 1, level = 0, water = 0;
		while (l < r) {
			int lower = height[height[l] < height[r] ? l++ : r--];
			level = max(level, lower);
			water += level - lower;
		}
		return water;
	}
};

int main()
{
	int arr[] = { 5,2,1,2,1,5 };
	vector<int> ivec(arr, arr + 6);
	Solution s;
	int ret = s.trap(ivec);
	cout << ret << endl;
	system("pause");
	return 0;
}