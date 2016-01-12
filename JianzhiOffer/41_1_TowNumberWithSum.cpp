#include <iostream>

using namespace std;

bool FindNumbersWithSum(int data[], int length, int sum, int *num1, int *num2)
{
	if (data == NULL || length < 2)
		return false;

	int end = length - 1;
	int start = 0;

	while (start<end)
	{
		if ((data[end] + data[start]) == sum)
		{
			*num1 = data[start];
			*num2 = data[end];
			return true;
		}
		else if ((data[start] + data[end]) < sum)
			start++;
		else
			end--;
	}

	return false;
}

int main()
{
	int data[] = { 1, 2, 4, 7, 11, 15 };
	int num1, num2;
	if (FindNumbersWithSum(data, 6, 15, &num1, &num2))
		cout <<"15="<< num1 << "+" << num2 << endl;
	else
		cout << "Not Found!" << endl;
	system("pause");
	return 0;
}