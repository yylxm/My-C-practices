#include <iostream>

using namespace std;


void Swap(int &a, int &b)
{
	a = a^b;
	b = b^a;
	a = a^b;
}
/*Ï£¶ûÅÅÐò*/
void ShellSort(int arr[], int length)
{
	
	for (int h = length / 2; h > 0; h = h / 2)
	{
		for (int i = 1; i < length; i++)
		{
			int temp = arr[i];
			int j;
			for (j = i - h; j >= 0 && arr[j]>temp; j-=h)
			{
				arr[j + h] = arr[j];
			}
			arr[j + h] = temp;
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
	int arr[] = { 7, 3, 9, 5, 8, 1, 2, 4, 6, 10 };
	ShellSort(arr, 10);
	print(arr, 10);
	system("pause");
	return 0;
}