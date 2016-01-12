#include <iostream>

using namespace std;

void Swap(int &a, int &b)//用“^”完成交换操作
{
	a = a^b;
	b = b^a;
	a = a^b;
}

int Left(int i){ return ((i << 1) + 1); } //leftchild=2*i+1;
int Right(int i){ return ((i << 1) + 2); }//rightchild=2*i+2
int heapSize = 0;

void maxHeapify(int arr[], int index)//堆的调整
{
	int max = index;
	int left = Left(index);
	int right = Right(index);

	if (left <= heapSize && arr[left] > arr[index])
		max = left;

	if (right <= heapSize && arr[right] > arr[max])
		max = right;

	if (max != index)
	{
		Swap(arr[index], arr[max]);
		maxHeapify(arr, max);
	}
}

void Built_Maxheap(int arr[], int length)//建立堆
{
	heapSize = length-1;
	for (int  i = (length >> 1-1); i >= 0 ; i--) //n/2-1之前都是父节点，之后的节点都是子节点，只需要对父节点进行maxHeapify
	{
		maxHeapify(arr, i);
	}
}

void MaxHeapSort(int arr[], int length)//堆排序
{
	Built_Maxheap(arr, length);

	for (int i = length - 1; i >= 1; i--)
	{
		swap(arr[0], arr[i]);
		heapSize--;
		maxHeapify(arr, 0);
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
	MaxHeapSort(arr, 10);
	print(arr, 10);
	system("pause");
	return 0;
}