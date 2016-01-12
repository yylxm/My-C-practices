#include <iostream>

using namespace std;


void Swap(int &a, int &b)
{
	a = a^b;
	b = b^a;
	a = a^b;
}

//将两个子序列按照大小顺序填入临时数组temp中
void Merge(int arr[], int temp[], int start1, int end1, int end2)
{
	int start2 = end1 + 1;
	int tempindex = start1;
	int number = end2 - start1 + 1;
	while (start1<=end1 && start2<=end2)
	{
		if (arr[start1] <= arr[start2])
		{
			temp[tempindex++] = arr[start1];
			start1++;
		}
		else{
			temp[tempindex++] = arr[start2];
			start2++;
		}
	}

	while (start1 <= end1)
	{
		temp[tempindex++] = arr[start1];
		start1++;
	}

	while (start2<=end2)
	{
		temp[tempindex++] = arr[start2];
		start2++;
	}

	for (int i = 0; i < number; i++, end2--)
		arr[end2] = temp[end2];
}


void merge_sort(int arr[], int temp[], int start, int end)
{
	if (start >= end)
		return;

	int middle = (start + end) / 2;//分裂节点
	merge_sort(arr, temp, start, middle);//分别递归排序
	merge_sort(arr, temp, middle + 1, end);
	Merge(arr, temp, start, middle, end);//合并
}

/*归并排序*/
void MergeSort(int arr[], int length)
{
	int *temp = NULL;
	temp = new int[length];
	if (temp != NULL)
	{
		merge_sort(arr, temp, 0, length - 1);
		delete[] temp;
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
	MergeSort(arr, 10);
	print(arr, 10);
	system("pause");
	return 0;
}