#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string> > ret;
		vector<string > nQueue(n, string(n, '.'));
		solveNQueue(ret, nQueue, 0, n);
		return ret;
	}
	void print(vector<vector<string> >&ret)
	{
		for (auto iter = ret.begin(); iter != ret.end(); iter++)
		{
			cout << "{";
			for (auto iter2 = (*iter).begin(); iter2 != (*iter).end(); ++iter2)
			{
				
				cout << *iter2 << endl;;

			}
			cout << "}" << endl;
		}
	}
private:
	
	void solveNQueue(vector<vector <string> > &ret, vector<string> nQueue, int row, int &n)
	{
		if (row == n)
		{
			ret.push_back(nQueue);
			return;
		}
		for (int col = 0; col != n; col++)
		{
			if (isvalid(nQueue, row, col, n))
			{
				nQueue[row][col] = 'Q';
				solveNQueue(ret, nQueue, row + 1, n);
				nQueue[row][col] = '.';//搜索完一个答案后记得恢复
			}
		}
	}
	bool isvalid(vector<string > nQueue,int row,int col,int &n)
	{
		int i, j;
		for (  i = 0; i < row; i++)
			if (nQueue[i][col] == 'Q')
				return false;

		for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
			if (nQueue[i][j] == 'Q')
				return false;

		for ( i = row-1, j = col + 1; i >= 0 &&j < n; --i, j++)
		    if (nQueue[i][j] == 'Q')
			    return false;

		return true;	
	}
};

int main()
{
	Solution s;
	vector<vector<string> >ret;
	int n;
	cin >> n;
	ret=s.solveNQueens(n);
	s.print(ret);
	system("pause");
	return 0;
}

