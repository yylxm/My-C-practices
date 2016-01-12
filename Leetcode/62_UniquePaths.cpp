#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;




/*��̬�滮*/
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
		vector<int > path(m, 1); //Ϊ�˽�ʡ�ռ���ý�С����
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
		vector<int > path(m, 1); //Ϊ�˽�ʡ�ռ���ý�С����
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

	/*��ѧ������m,n���Ա�ʾ�ֱ���Ҫ���µĴ��������ҵĴ������ܹ���Ҫ�ƶ��Ĳ���Ϊm+n-2*/
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