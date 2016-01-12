#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
		vector<vector<int> >ret;
        if(nums.size()<4) return ret;
		sort(nums.begin(),nums.end());
		int length=nums.size();
		int sum;
		for(int i=0;i<length-3;i++) //确定第一个数 a
		{
			if(i>0 &&nums[i]==nums[i-1])
			{
				//i++;  //注意此处不要加1，否则会导致错误，满足条件的等式无法输出
				continue;
			}
			int target2=target-nums[i]; //将4Sum转换成3Sum，target2=target-a;
			for(int j=i+1;j<length-2;++j)
			{
				if(j>i+1 && nums[j]==nums[j-1])
			    {
				   // j++; //同上
				    continue;
			    }
				int k=j+1;
				int n=length-1;
				vector<int> tmp;
				while(k<n)
				{
					sum=nums[j]+nums[k]+nums[n];

					if(sum==target2)
					{
						if(k>j+1 && nums[k]==nums[k-1])
						{
							k++;
							continue;
						}
						tmp.clear();
						tmp.push_back(nums[i]);
						tmp.push_back(nums[j]);
						tmp.push_back(nums[k]);
						tmp.push_back(nums[n]);
						ret.push_back(tmp);
						k++;//继续查找
					}
					else if(sum>target2)
					{
						n--;
					}
					else
					{
						k++;
					}
				}
			}
		}
			
		return ret;
    }
};

int main()
{
	Solution s;
	int arr[]={0,0,4,-2,-3,-2,-2,-3};
	vector<int> ivec(arr,arr+8);
	vector<vector<int> > ret;

	ret=s.fourSum(ivec,-1);
	vector<int> tmp;
	for(auto iter=ret.begin();iter!=ret.end();++iter)
	{
		tmp.clear();
		tmp=(*iter);
		cout<<"("<<tmp[0]<<","<<tmp[1]<<","<<tmp[2]<<","<<tmp[3]<<")"<<endl;
	}
	system("pause");
	return 0;
}