#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int len = matrix.size();
		vector<vector<int> >res;
		vector<int >temp;
		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < len; j++)
			{
				temp.push_back(matrix[len - j-1][i]);
			}
			res.push_back(temp);
			temp.clear();
		}
	
		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < len; j++)
			{
				matrix[i][j] = res[i][j];
			}
		}
	}

	void rotate2(vector<vector<int>>& matrix) {
		int len = matrix.size();
		for (int i = 0; i < len; i++)
		{
			for (int j = i+1; j < len; j++)
			{
				swap(matrix[i][j],matrix[j][i]);
			}
		}

		for (int i = 0; i < len; i++)
		{
			reverse(matrix[i].begin(), matrix[i].end());
		}
	}
};

int main()
{
	int arr[][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 } };
	vector<vector<int> >ret;
	vector<int>ivec;
	int k = 1;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			ivec.push_back(k);
			k++;
		}
		ret.push_back(ivec);
		ivec.clear();
	}
	Solution s;
	s.rotate2(ret);
	for (auto iter = ret.begin(); iter != ret.end(); iter++)
	{
		for (auto iter2 = (*iter).begin(); iter2 != (*iter).end(); iter2++)
		{
			cout << *iter2 << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}