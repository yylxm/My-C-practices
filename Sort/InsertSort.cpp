#include <iostream>

using namespace std;


void Swap(int &a, int &b)
{
	a = a^b;
	b = b^a;
	a = a^b;
}
/*÷±Ω”≤Â»Î≈≈–Ú*/
void InsertSort(int arr[], int length)
{
	for (int i = 1; i < length; i++)
	{
		int temp = arr[i];
		int j;
		for (j = i - 1; j >=0 && temp<arr[j] ; j--)
		{
			arr[j+1] = arr[j];
		}
		arr[j + 1] = temp;
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
	InsertSort(arr, 10);
	print(arr, 10);
	system("pause");
	return 0;
}