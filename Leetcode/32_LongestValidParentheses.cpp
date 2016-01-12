#include <iostream>
#include <string>
#include <stack>
#include <math.h>

using namespace std;

class Solution {
public:

	int max(int a, int b)
	{
		return a > b ? a : b;
	}
	int longestValidParentheses(string s) {
		stack<char> sPareantTheses;//����һ����ջ
		int number=0;//ͳ����Ч���ŵĳ���

		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(')
				sPareantTheses.push(i);
			else
			{
				if (!sPareantTheses.empty())
				{
					sPareantTheses.pop();
					number = max(i - sPareantTheses.top(), number);
				}
				else
				{
					sPareantTheses.pop();
					sPareantTheses.push(i);
				}
			}
		}
		return number;
	}
};

int main()
{
	string s;
	Solution S;
	cin >> s;
	int ret = S.longestValidParentheses(s);
	cout << ret << endl;
	system("pause");
	return 0;
}