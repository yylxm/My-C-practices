#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int len = digits.size();
		for (int i = len-1; i >= 0 ; i--)
		{
			if (digits[i]<9)//��������������һλ������9����ôǰ�����������9
			{
				digits[i]++;
				return digits;
			}
			else
			{
				digits[i] = 0;
			}
		}
		digits[0] = 1; //���ڳ��˵�һλ���������ȫΪ0���������ǿ��Խ���һλ����Ϊһ��Ȼ����ѹ��һ��0.
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