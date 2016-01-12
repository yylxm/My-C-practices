#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

/* ����˼·����������ָ�룬һ��ָ��ͷ��һ��ָ��ĩβ��Ȼ������ָ�����м��ƶ�������ˮͰ��ˮ������֪��ˮ���Ķ�������ȡ���ڽ϶̵ļа壬����
�����ҳ��϶̵���һ������lower��Ȼ��ɨ��ÿһ�У���ȥ��߶ȼ��ɡ�*/

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