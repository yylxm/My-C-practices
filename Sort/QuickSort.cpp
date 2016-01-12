#include <iostream>

using namespace std;

void Swap(int &a, int &b)
{
	a = a^b;
	b = b^a;
	a = a^b;
}
/*快速排序*/
void QuickSort(int arr[],int first,int last)
{
	int low = first;
	int high = last;
	int pivot = arr[low];
	if (low < high)
	{
		while (low < high)
		{
			while (low < high && arr[high] >= pivot)//注意先从高位开始比较
			{
				high--;
			}
			if (low < high)
				arr[low++] = arr[high];
			
			while (low < high && arr[low] <= pivot)
			{
				low++;
			}
			if (low < high)
				arr[high--] = arr[low];		
		}
		arr[low] = pivot;
		QuickSort(arr, first, low - 1);
		QuickSort(arr, low + 1, last);
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
	QuickSort(arr, 0, 9);
	print(arr, 10);
	system("pause");
	return 0;
}