#include <iostream>

using namespace std;


void Swap(int &a, int &b)
{
	a = a^b;
	b = b^a;
	a = a^b;
}
/*—°‘Ò≈≈–Ú*/
void SelectSort(int arr[], int length)
{
	for (int i = 0; i < length-1; i++)
	{
		int min = arr[i];
		int index = i;

		for (int j = i+1; j < length; j++)
		{
			if (arr[j] < min)
			{
				min = arr[j];
				index = j;
			}
		}
		arr[index] = arr[i];
        arr[i] = min;		
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
	SelectSort(arr, 10);
	print(arr, 10);
	system("pause");
	return 0;
}