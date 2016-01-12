#include<iostream>

using namespace std;

int Min(int arr[],int length)
{
	if(length==0||arr==NULL) 
		throw new exception("Invalid parameters.");

	int start=0;
	int end=length-1;
	int mid=start;//起始位置设为开始点，为了能够处理依序排列的数组
	while (arr[start]>=arr[end])
	{
		if(end-start==1)
		{
			mid=end;
			break;
		}
		mid=(start+end)/2;

		if(arr[start]==arr[end]&&arr[start]==arr[mid])//如果三个数据相同，只能采用顺序查找法
			return MinInorder(arr,start,end);

		if (arr[mid]>=arr[start])
		{
			start=mid;
		}
		else if(arr[mid]<=arr[end])
		{
			end=mid;
		}
	}
	return arr[mid];
}

int MinInorder(int arr[],int start,int end)
{
	int min=arr[start];
	for(int i=start+1;i<=end;++i)
	{
		if(arr[i]<min)
			min=arr[i];
	}
	return min;
}

int main()
{
	int arr[]={1,2};
	int ret=Min(arr,2);
	cout<<ret<<endl;
	system("pause");
	return 0;
}