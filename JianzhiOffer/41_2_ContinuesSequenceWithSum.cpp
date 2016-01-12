#include <iostream>

using namespace std;

void FindCountinuousSequence(int sum)
{
	if (sum < 3)
		return;
	int small = 1;
	int big = 2;
	int middle = (1 + sum) / 2;
	int currSum = small + big;

	while (small < middle)
	{
		if (currSum == sum)
		{
			cout << sum << "=";
			for (int i = small; i < big; ++i)
			{
				cout << i << "+";
			}
			cout << big << endl;
			big++;
			currSum += big;
		}
		else if (currSum < sum)
		{
			big++;
			currSum += big;
		}
		else
		{
			currSum -= small;
			small++;
		}

	}
}

int main()
{
	FindCountinuousSequence(100);
	system("pause");
	return 0;
}