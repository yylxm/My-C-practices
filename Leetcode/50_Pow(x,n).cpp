#include <iostream>

using namespace std;

class Solution {
public:
	double myPow(double x, int n) {
		double ret;
		if (n==0)
		{
			return 1;
		}
		if (n==1)
		{
			return x;
		}

		if (n<0)
		{
			x = 1.0 / x;
			n = -n;
		}

		
		if (n%2==0)
		{
			ret = myPow(x*x, n >> 1);
		}
		else
		{
			ret = myPow(x*x, n >> 1);
			ret = ret*x;
		}

		return ret;
	}
};

int main()
{
	Solution s;
	double x, ret;
	int n;
	cin >> x;
	cin >> n;
	ret = s.myPow(x, n);
	cout << ret << endl;
	system("pause");
	return 0;
}