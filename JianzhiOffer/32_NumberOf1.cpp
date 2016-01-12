#include <iostream>
#include <stdio.h>

using namespace std;
/*o(n*logn)���ӶȵĽⷨ
int NumberOf1(unsigned int i)
{
	int number = 0;
	while (i)
	{
		if (i % 10 == 1)
			number++;
		i = i / 10;
	}
	return number;
}

int NumberOf1Between1AndN(unsigned int n)
{
	int number = 0;
	for (unsigned int i = 1; i <= n; i++)
	{
		number = number + NumberOf1(i);
	}
	return number;
}*/

/*o(logn)���ӶȵĽⷨ*/

int PowerBase10(int n)
{
	int sum = 1;
	for (int i = 0; i < n; i++)
	{
		sum = sum * 10;
	}
	return sum;
}

int NumberOf1(const char *str)
{
	if (!str || *str<'0' || *str>'9' || *str=='\0')
	{
		return 0;
	}

	int first = *str - '0';
	unsigned int length = static_cast<unsigned int>(strlen(str));

	if (first == 0 && length == 1)
		return 0;
	if (first == 1 && length == 1)
		return 1;

	int numFirstDigit = 0;
	if (first > 1)
		numFirstDigit = PowerBase10(length - 1);
	else if (first == 1)
		numFirstDigit = atoi(str + 1) + 1;

	int numOtherDigits = first*(length - 1)*PowerBase10(length - 2);

	int numRecursive = NumberOf1(str + 1);

	return numFirstDigit + numOtherDigits + numRecursive;
}

int NumberOf1Between1AndN(int n)
{
	if (n<0)
	{
		return 0;
	}
	char strN[50];
	sprintf_s(strN, "%d", n);//������װ�����ַ���
	return NumberOf1(strN);
}

int main()
{
	unsigned int number;
	cin >> number;
	int ret = NumberOf1Between1AndN(number);
	cout << ret << endl;
	system("pause");
	return 0;
}