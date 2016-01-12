#include <iostream>

using namespace std;

bool IsUgly(int number)
{
	while (number % 2 == 0)
		number = number / 2;
	while (number % 3 == 0)
		number = number/3;
	while (number % 5 == 0)
		number = number / 5;
	return (number == 1) ? true : false;
}

int GetUglyNumber(int index)
{
	if (index <= 0)
		return 0;
	int number = 0;
	int uglyFound = 0;
	while (uglyFound<index)
	{
		++number;
		if (IsUgly(number))
			uglyFound++;
	}
	return number;
}

int main()
{
	int n;
	cin >> n;
	int ret = GetUglyNumber(n);
	cout << ret << endl;
	system("pause");
	return 0;
}