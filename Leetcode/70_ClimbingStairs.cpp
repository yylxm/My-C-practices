#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class Solution {
public:
	int climbStairs(int n) {//≤…”√µ›πÈ
		long ret;
		if (n <= 0)
			return 0;
		if (n == 1 )
			return 1;
		else
			return climbStairs(n - 1) + climbStairs(n - 2);		
	}

	int climbStairs2(int n)//∑«µ›πÈ
	{
		vector<long> ret;
		if (n <= 0)
			return 0;
		if (n == 1)
			return 1;

		ret.push_back(1);
		ret.push_back(1);
		for (int i = 2; i <=n ; i++)
		{
			
			ret.push_back(ret[i - 1] + ret[i - 2]);
		}

		return ret[n];
	}
};

int main()
{
	int n;
	cin >> n;
	Solution s;
	int ret = s.climbStairs2(n);
	cout << ret << endl;
	system("pause");
	return 0;
}