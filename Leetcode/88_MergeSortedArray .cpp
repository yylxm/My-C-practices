#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int k = m + n - 1;
		int i = m - 1;
		int j = n - 1;
		while (i >= 0 && j >= 0)
		{
			if (nums1[i]>=nums2[j])
			{
				nums1[k] = nums1[i];
				i--;
			}
			else
			{
				nums1[k] = nums2[j];
				j--;
			}
			k--;
		}

		while (j>=0)
		{
			nums1[k] = nums2[j];
			k--;
			j--;
		}
	}
};

int main()
{
	Solution s;
	int arr[] = { 2, 3, 4, 7, 9 };
	int arr2[] = { 3, 5, 6, 7, 8, 10 };
	vector<int> ivec1(arr, arr + 20);
	vector<int> ivec2(arr2, arr2 + 6);
	s.merge(ivec1,5,ivec2,6);

	for (int i = 0; i < ivec1.size(); i++)
	{
		cout << ivec1[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}