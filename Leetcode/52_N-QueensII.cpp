#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	int totalNQueens(int n) {
		vector<string> svec(n, string(n, '.'));
		int ret=0;
		SolveQueue(svec, ret, 0, n);
		return ret;
	}

private:
	void SolveQueue(vector<string> &Queue, int &ret, int row, int &n)
	{
		if (row == n)
		{
			ret++;
			return;
		}
		for (int col = 0; col < n; col++)
		{
			if (isvalid(Queue, row, col, n))
			{
				Queue[row][col] = 'Q';
				SolveQueue(Queue, ret, row + 1, n);
				Queue[row][col] = '.';
			}
		}
	}
	bool isvalid(vector<string> &Queue, int row,int col, int &n)
	{
		int i, j;
		for (  i = 0; i < row; i++)
		{
			if (Queue[i][col] == 'Q')
				return false;
		}

	
		for ( i = row-1,j=col-1; i >=0 &&j>=0 ; i--,j--)
		{
			if (Queue[i][j] == 'Q')
				return false;
		}

		for (i = row - 1, j = col + 1; i >= 0&&j<n; i--,j++)
		{
			if (Queue[i][j]=='Q')
			{
				return false;
			}

		}
		return true;
	}

	
};

int main()
{
	int n;
	Solution s;
	cin >> n;
	int ret = s.totalNQueens(n);
	cout << ret << endl;

	system("pause");
	return 0;
}