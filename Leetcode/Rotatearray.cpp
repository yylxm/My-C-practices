#include<iostream>
using namespace std;

class Solution{
public:
	void rotate1(int nums[],int n,int k)
	{	
		if(k>n)
			k=k%n;//if k > n then the final result is the same as k%n
		if(k==0) return;
		int temp;
		int k1=k;
		int n1=n,n2=n;
		for(int i=0;i<=(n-k)/2-1;++i)
		{
			temp=nums[i];
			nums[i]=nums[n1-k1-1];
			nums[n1-k1-1]=temp;
			k1++;
		}
		for(int i=n-k;i<n-k+k/2;++i)
		{
			temp=nums[i];
			nums[i]=nums[n1-1];
			nums[n1-1]=temp;
			n1--;
		}
		for(int i=0;i<n/2;++i)
		{
			temp=nums[i];
			nums[i]=nums[n2-1];
			nums[n2-1]=temp;
			n2--;
		}
	}

    void rotate(int nums[], int n, int k) {
		if(n == 0)return;
			k = k % n;

			//initialize
		int i = 0;
		int nowIndex = 0;
		int tmp = nums[0],stmp;

		//exactly n steps, n times loop
		for(int j = 0; j < n; j++)
		{
			//next index to exchange
			nowIndex = (nowIndex + k) % n;

			//exchange
			stmp = nums[nowIndex];
			nums[nowIndex] = tmp;
			tmp = stmp;

			//finish a circle,move to another circle
			if(nowIndex == i)
			{
				nowIndex = ++i;
				tmp = nums[nowIndex];
			}
		}
	}
};

int main()
{
	int arr[]={1,2};
	Solution h;
	h.rotate(arr,2,3);

	for(int i=0;i<2;++i)
		cout<<arr[i]<<" ";
	cout<<endl;

	system("pause");
	return 0;
}