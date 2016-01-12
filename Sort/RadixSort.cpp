#include <iostream>

using namespace std;

int find_max(int arr[], int length)//找到最大的一个数
{
	int max = arr[0];
	for (int i = 1; i < length; ++i)
	{
		if (arr[i]>max)
			max = arr[i];
	}
	return max;
}

int digitnumber(int number)//求数字的位数
{
	int num = 0;
	while (number > 0)
	{
		number = number / 10;
		num++;
	}
	return num;
}

int kdigitnumber(int number,int k)//求第k位的元素，从个位数开始计数
{
	number = number / pow(10, k);
	return number % 10;
}

/*基数排序*/
void RadixSort(int arr[], int length)
{
	int *temp[10];//指针数组，指向10个桶
	int max = find_max(arr,length);
	int maxDigit = digitnumber(max);
	int count[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };//每个桶元素的个数

	for (int i = 0; i < 10; ++i)//给桶分配空间，并初始化
	{
		temp[i] = new int[length];
		memset(temp[i], 0, sizeof(int)*length);
	}

	for (int i = 0; i < maxDigit; i++)
	{
		memset(count, 0, sizeof(int)* 10);
		for (int j = 0; j < length; j++)
		{
			int x = kdigitnumber(arr[j], i);
			temp[x][count[x]] = arr[j];
			count[x]++;
		}

		int index = 0;//对桶中的元素进行收集操作
		for (int k = 0; k < 10; k++)
		{
			for (int m = 0; m < count[k]; m++)
			{
				arr[index++] = temp[k][m];
			}
		}
	}
}

void print(int arr[], int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	int arr[] = { 73, 673, 900, 545, 84, 10, 232, 489, 645, 100};
	RadixSort(arr, 10);
	print(arr, 10);
	system("pause");
	return 0;
}