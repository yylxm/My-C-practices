#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
	int rob(vector<int> &num){
		int len=num.size();
		if(len==0)//注意要先对长度进行判断，因为如果长度等于0，则无法生成sum
			return 0;
		else if(len==1)
			return num[0];
		vector<int> sum(len,0);
		sum[0]=num[0];
		for(int i=1;i<len;++i)
			sum[i]=max(sum[i-1],i-2>=0?sum[i-2]+num[i]:num[i]);
		return sum[len-1];
	}
};


int main()
{
	int arr[3]={1,1,1};
	vector<int> iv(arr,arr+3);
	Solution h;
	int value=h.rob(iv);
	cout<<value<<endl;
	system("pause");
	return 0;
}