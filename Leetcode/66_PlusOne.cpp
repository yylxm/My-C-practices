#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int len = digits.size();
		for (int i = len-1; i >= 0 ; i--)
		{
			if (digits[i]<9)//数据有序，如果最后一位数等于9，那么前面的数都等于9
			{
				digits[i]++;
				return digits;
			}
			else
			{
				digits[i] = 0;
			}
		}
		digits[0] = 1; //由于除了第一位，后面的数全为0，所以我们可以将第一位数置为一，然后再压入一个0.
		digits.push_back(0);
		return digits;
	}
};

int main()
{
	int arr[] = { 9, 9 };
	vector<int> ivec(arr, arr + 2);
	Solution s;
	vector<int> ret;
	ret = s.plusOne(ivec);
	for (int i = 0; i < ret.size(); i++)
	{
		cout << ret[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}