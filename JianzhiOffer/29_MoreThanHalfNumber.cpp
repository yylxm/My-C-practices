#include <iostream>

using namespace std;

bool g_bInputInvalid = false;

bool CheckMoreThanHalf(int *number, int  length, int num)
{
	int times = 0;
	for (int i = 0; i < length; i++)
	{
		if (number[i] == num)
		{
			times++;
		}
	}

	bool isMoreThanHalf = true;
	if ((times>>1) >length)
	{
		g_bInputInvalid = true;
		isMoreThanHalf = true;
	}
	return isMoreThanHalf;
}


int MoreThanHalfNum(int *number, int length)
{
	if (number == NULL || length<0)
	{
		return 0;
	}
	int num = number[0];
	int times = 1;
	for (int  i = 1; i < length; i++)
	{
		if (times == 0)
		{
			num = number[i];
			times = 1;
		}
		else if (number[i] == num)
		{
			times++;
		}
		else
		{
			times--;
		}
		
	}

	if (!CheckMoreThanHalf(number,length,num))
	{
		return 0;
	}

	return num;
}

int main()
{
	int arr[] = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
	int ret = MoreThanHalfNum(arr, 10);
	cout << ret << endl;
	system("pause");
	return 0;
}