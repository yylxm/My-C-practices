#include <iostream>

using namespace std;

int FindGreatestSumofSubArray(int *data, int length)
{
	if (data == NULL || length<=0)
	{
		return 0;
	}
	int maxSum = 0x80000000;
	int sum = 0;
	for (int i = 0; i < length; i++)
	{
		if (sum <= 0)
		{
			sum = data[i];
		}
		else
			sum = sum + data[i];
		if (sum>maxSum)
		{
			maxSum = sum;
		}
	}
	return maxSum;
}

int main()
{
	int data[] = { 1, -2, 3, 10, -4, 7, 2, -5 };
	int ret = FindGreatestSumofSubArray(data, 8);
	cout << ret << endl;
	system("pause");
	return 0;
}