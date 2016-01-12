/*在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。 */

#include <iostream>
#include <vector>
using namespace std;

bool Find(vector<vector<int> > array, int target) {
	if (array.size() == 0)
	{
		return false;
	}

	int row = array.size();//行数
	int cloum = array[0].size();//列数

	if (row>0 && cloum>0)
	{
		int r = 0;
		int cl = cloum - 1;
		while (r<row && cl>=0)
		{
			if ((array[r][cl] == target))
			{
				return true;
			}
			else if (array[r][cl]>=target)
			{
				cl--;
			}
			else
			{
				++r;
			}
		}
	}

	return false;
}

int main()
{
	int arr[][5] = { 3, 7, 8, 9, 13, 5, 9, 11, 14, 15, 8, 12, 13, 16, 19, 11, 15, 17, 18, 20 };
	vector<vector<int>> iv;
	for (int i = 0; i < 4; i++)
	{
		vector<int> tmp(arr[i], arr[i] + 4);
		iv.push_back(tmp);
	}
	if (Find(iv, 14))
		cout << "Yes!" << endl;
	else
		cout << "No!" << endl;
	system("pause");
	return 0;
}
