#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int length = nums.size();
		int begin = 0;
		int end = length - 1;
		vector<int> ret;
		ret.push_back(-1);
		ret.push_back(-1);

		while (begin<=end)
		{
			int middle = (begin + end) >> 1;
			if (nums[middle]<target)
			{
				begin = middle+1;
			}
			else if (nums[middle]>target)
			{
				end = middle-1;
			}
			else
			{
				int b=middle;
				int e=middle;
				while (b > begin)
				{
					if (nums[--b] == target)
						continue;
					else
					{
						b++;
						break;
					}
						
				}
				while (e < end)
				{
					if (nums[++e] == target )
						continue;
					else
					{
						e--;
						break;
					}
						
				}
				
				ret.pop_back();
				ret.pop_back();
				if (e == b)
				{
					ret.push_back(e);
					ret.push_back(e);
				}
				else
				{
					ret.push_back(b);
					ret.push_back(e);
				}
				
				break;

			}
		}
		return ret;
	}
};

int main()
{
	int arr[] = { 5,5,5, 7, 7, 8, 8, 8, 10,10,11 };
	vector<int> ivec(arr, arr + 11);
	Solution s;
	vector<int> ret;
	ret = s.searchRange(ivec, 8);

	for (int i = 0; i < 2; ++i)
	{
		cout << ret[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}