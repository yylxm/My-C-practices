#include <iostream>

using namespace std; 

int GetFirstK(int *data, int length, int k, int start, int end)
{
	if (start > end)
		return -1;

	int middleindex = (start + end)/2;
	int middledata = data[middleindex];

	if (middledata == k)
	{
		if ((middleindex > 0 && data[middleindex - 1] != k) || middleindex == 0)
		{
			return middleindex;
		}
		else
			end = middleindex - 1; 
	}
	else if (middledata > k)
		end = middleindex - 1;
	else
		start = middleindex + 1;

	return GetFirstK(data, length, k, start, end);
}

int GetLastK(int *data, int length, int k, int start, int end)
{
	if (start > end)
		return - 1;

	int middleindex = (start + end) / 2;
	int middledata = data[middleindex];

	if (middledata == k)
	{
		if ((middleindex < length - 1 && data[middleindex + 1] != k) || middleindex == length - 1)
			return middleindex;
		else
			start = middleindex + 1;
	}
	else if (middledata > k)
		end = middleindex - 1;
	else
		start = middleindex + 1;

	return GetLastK(data, length, k, start, end);
}

int GetNumberOfK(int *data, int length,int k)
{
	int number = 0;
	if (data != NULL &&length > 0)
	{
		int first = GetFirstK(data, length, k, 0, length);
		int last = GetLastK(data, length, k,  0, length);

		if (first > -1 && last > -1)
			number = last - first + 1;
	}
	return number;
}

int main()
{
	int data[] = { 1, 2, 3, 3, 3, 3, 3, 3, 4, 5 };
	int ret = GetNumberOfK(data, 10, 3);
	cout << ret << endl;
	system("pause");
	return 0;
}