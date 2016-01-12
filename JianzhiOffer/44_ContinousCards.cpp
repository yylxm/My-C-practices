#include <iostream>
#include <math.h>

using namespace std;

int compares(const void *arg1, const void *arg2)
{
	return *(int *)arg1 - *(int *)arg2;
}

bool IsContinous(int *numbers, int length)
{
	if (numbers == NULL || length < 1)
		return false;
	qsort(numbers, length, sizeof(int), compares);
	int NumberOfZero = 0;
	int NumberOfGap = 0;

	for (int  i = 0; i < length; i++)
	if (numbers[i] == 0)
		++NumberOfZero;

	int small = NumberOfZero;
	int big = small + 1;
	for (int i = small; i < length-1; i++)
	{
		if (numbers[i] == numbers[big])
			return false;

		else if (numbers[i] + 1 == numbers[big])
		{
			big++;
		}
		else
		{
			NumberOfGap =NumberOfGap+ numbers[big] - numbers[i] - 1;
			big++;
		}
	}

	return (NumberOfGap > NumberOfZero) ? false : true;
}

int main()
{
	int number[] = { 1, 2, 3,4, 0, 6 };
	bool ret = IsContinous(number, 6);
	if (ret)
		cout << "Yes!" << endl;
	else
		cout << "No!" << endl;
	system("pause");
	return 0;
}