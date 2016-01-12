#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int> >& grid) {
		int lenm = grid.size();
		int lenn = grid[0].size();
		if (lenm==0)
		{
			return 0;
		}
		vector<vector<int> > minSum(lenm,vector<int>(lenn,0));//初始化minSum
		
		minSum[0][0] = grid[0][0];

		for (int j = 1; j < lenn; j++)//初始化第一行
		{
			minSum[0][j] = minSum[0][j-1] + grid[0][j];
		}

		for (int i = 1; i < lenm; i++)//初始化第一列
		{
			minSum[i][0] = minSum[i - 1][0] + grid[i][0];
		}

		for (int  i = 1; i < lenm; i++)
		{
			for (int j = 1; j < lenn; j++)
			{
				minSum[i][j] = min(minSum[i - 1][j], minSum[i][j - 1]) + grid[i][j];//状态转移方式
			}
		}
		return minSum[lenm - 1][lenn - 1];
	}

	int minPathSum2(vector<vector<int> >& grid) {
		int lenm = grid.size();
		int lenn = grid[0].size();
		if (lenm == 0)
		{
			return 0;
		}
		
		vector<int > minSumx;
		vector<int >minSumcur;
		minSumcur[0] = minSumx[0]= grid[0][0];

		for (int j = 1; j < lenn; j++)//初始化第一行
		{
			minSumx[j] = minSumx[j - 1] + grid[0][j];
		}

		for (int i = 1; i < lenm; i++)//初始化第一列
		{
			minSumcur[i] = minSumcur[i - 1] + grid[i][0];
		}

		for (int i = 1; i < lenm; i++)
		{
			for (int j = 1; j < lenn; j++)
			{
				minSum[i][j] = min(minSumcur[i - 1][j], minSumx[i][j - 1]) + grid[i][j];//状态转移方式
			}
			swap(minSum)
		}
		return minSum[lenm - 1][lenn - 1];
	}
};

int main()
{
	int arr[][3] = { { 1, 2, 5 }, { 3, 2, 1 } };
	vector<vector<int> >ret;
	vector<int>ivec;
	int k = 1;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			ivec.push_back(arr[i][j]);
		}
		ret.push_back(ivec);
		ivec.clear();
	}
	
	Solution s;
	int result = s.minPathSum(ret);
	cout << result << endl;
	system("pause");
	return 0;
}