#include <iostream>

using namespace std;

void PrintMatrixInCircle(int arr[][4],int coloum,int rows,int start)
{
	int endx=coloum-1-start;//减1是因为数组的起始下标从0开始
	int endy=rows-1-start;

	//从左到右打印一行
	for (int i = start; i <= endx; i++)
	{
		cout<<arr[start][i]<<" ";
	}

	//从下到上打印一列
	if (start<endy)
	{
		for (int i = start+1; i <= endy; i++)
		{
			cout<<arr[i][endy]<<" ";
		}
	}

	//从左到右打印一行
	if (start<endx && start<endy)
	{
		for (int i = endx-1; i >= start; i--)
		{
			cout<<arr[endy][i]<<" ";
		}
	}


	//从下到上打印一列
	if (start<endx && start<endy -1)
	{
		for (int i = endy-1; i >= start+1 ; i--)
		{
			cout<<arr[i][start]<<" ";
		}
	}

}

void PrintMatrixClockwisely(int arr[][4],int coloums,int rows)
{
	if(arr==NULL || coloums<=0 || rows<=0)
		return ;

	int start=0;

	while (coloums>start*2 && rows>start*2)
	{
		PrintMatrixInCircle(arr,coloums,rows,start);
		start++;
	}
}

int main()
{
	int arr[4][4]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	PrintMatrixClockwisely(arr,4,4);
	system("pause");
	return 0;
}