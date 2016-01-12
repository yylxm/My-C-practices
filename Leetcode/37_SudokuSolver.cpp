#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool row[9][10] ;
	bool col[9][10] ;
	bool box[9][10] ;
	bool solve(vector<vector<char> >&board, int i, int j)
	{
		if (i >= 9) return true;
		if (board[i][j] != '.')
			return solve(board, i + (j + 1) / 9, (j + 1) % 9);//深度优先搜索
		for (int k = 1; k < 10; ++k)
		{
			if (!row[i][k] && !col[j][k] && !box[i / 3 * 3 + j / 3][k])
			{
				board[i][j] = k + '0';
				row[i][k] = true;
				col[j][k] = true;
				box[i / 3 * 3 + j / 3][k] = true;
				if (solve(board, i + (j + 1) / 9, (j + 1) % 9))
					return true;
				board[i][j] = '.';//不满足，则返回上一步
				row[i][k] = false;
				col[j][k] = false;
				box[i / 3 * 3 + j / 3][k] = false;
			}
		}
		return false;
	}
	void solveSudoku(vector<vector<char> >& board) {
		memset(row, 0, sizeof(row));
		memset(col, 0, sizeof(col));
		memset(box, 0, sizeof(box));
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; ++j)
			{
				char c = board[i][j];
				if (c != '.')
				{
					row[i][c - '0'] = true;
					col[j][c - '0'] = true;
					box[i / 3 * 3 + j / 3][c - '0'] = true;
				}
			}
		}
		solve(board, 0, 0);
	}
};

int main()
{
	system("pause");
	return 0;
}
