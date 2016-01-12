#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char> >& board) {
		int row[9][9] = {0};
		int col[9][9] = {0};
		int box[9][9] = {0};

		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; ++j)
			{
				char c = board[i][j];
				if (c == '.')
					continue;
				if (c<'1' || c>'9')
					return false;
				int number = c - '1';
				if (row[i][number] || col[number][j] || box[i / 3 * 3 + j / 3][number])//如果把九宫格按照行从0开始标号，那么数字board[i][j] 位于第 i/3*3+j/3 个九宫格内
					return false;
				row[i][number] = 1;
				col[number][j] = 1;
				box[i / 3 * 3 + j / 3][number] = 1;
			}
		}
		return true;
	}
};

int main()
{		
	system("pause");
	return 0;
}