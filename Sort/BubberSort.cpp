#include <iostream>

using namespace std;


void Swap(int &a, int &b)//“或”实现两个数的交换
{
	a = a^b;
	b = b^a;
	a = a^b;
}
/*直接插入排序*/
void BubberSort(int arr[], int length)
{
	for (int i = 0; i < length-1; i++)
	{
		int exchange = 0;
		for (int j = i + 1; j < length; j++)
		{
			if (arr[i]>arr[j])
			{
				swap(arr[j], arr[i]);
				exchange = 1;
			}
		}
		if (exchange != 1)
			return;
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
	int arr[] = { 7, 3, 9, 5, 8, 1, 2, 4, 6, 10 };
	BubberSort(arr, 10);
	print(arr, 10);
	system("pause");
	return 0;
}