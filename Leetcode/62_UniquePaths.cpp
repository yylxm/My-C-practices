#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;




/*动态规划*/
class Solution{
public:
	int uniquePaths(int m, int n)
	{
		vector<vector<int> > path(m, vector<int>(n, 1));

		for (int  i = 1; i < m; i++)
		{
			for (int j = 1; j < n; j++)
			{
				path[i][j] = path[i - 1][j] + path[i][j - 1];
			}
		}
		return path[m - 1][n - 1];
	}

	int uniquePaths2(int m, int n)
	{
		if (m > n)
			swap(m, n);
		vector<int > path(m, 1); //为了节省空间采用较小的数
		vector<int > left(m, 1);

		for (int i = 1; i < n; i++)
		{
			int j;
			for (j = 1; j < m; j++)
			{
				path[j] = path[j - 1] + left[j];
			}
			swap(path, left);
		}
		return left[m - 1];
	}

	int uniquePaths3(int m, int n)
	{
		if (m > n)
			swap(m, n);
		vector<int > path(m, 1); //为了节省空间采用较小的数
		for (int i = 1; i < n; i++)
		{
			int j;
			for (j = 1; j < m; j++)
			{
				path[j] = path[j]+ path[j - 1] ;
			}

		}
		return path[m - 1];
	}

	/*数学方法：m,n可以表示分别需要向下的次数和向右的次数，总共需要移动的步数为m+n-2*/
	int uniquePathsMath(int m, int n) {
		if (m <= 0 || n <= 0)
			return 0;
		long res=1;
		for (int  i = n; i < m+n-1; i++)
		{
			res = res * i / (i - n + 1);
		}
		return (int)res;
	}
};

int main()
{
	Solution s;
	int ret = s.uniquePathsMath(3, 4);
	cout << ret << endl;
	system("pause");
	return 0;
}