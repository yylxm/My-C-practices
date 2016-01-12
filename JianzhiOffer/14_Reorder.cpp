#include <iostream>

using namespace std;

int arr[]={1,2,3,4,5};

bool isodd(int a)
{
	if(a%2)
		return true;
	else
		return false;
}

void ReorderOddEven(int arr[],unsigned int length)
{
	if(arr==NULL|| length==0) return ;

	int index1=0;
	int index2=length-1;

	while (index1<index2)
	{
		while (index1<index2&&isodd(arr[index1]))
		{
			index1++;
		}

		while (index1<index2&&!isodd(arr[index2]))
		{
			index2--;
		}
		
		if(index1<index2)
		{
			swap(arr[index1],arr[index2]);
			index1++;
			index2--;
		}
	}
}

int main()
{
	
	ReorderOddEven(arr,5);
	for (int i = 0; i < 5; i++)
	{
		cout<<arr[i]<<" ";
	}
	system("pause");
	return  0;
}