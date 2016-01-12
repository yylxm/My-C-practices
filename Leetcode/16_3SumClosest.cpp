#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {       
		if(nums.size()<3)return 0;
		sort(nums.begin(),nums.end());
		int sum;
		int result=nums[0]+nums[1]+nums[nums.size()-1];//求出第一个和
		for(int i=0;i<nums.size()-2;++i)
		{
			int j=i+1;
			int n=nums.size()-1;
			while(j<n)
			{
				sum=nums[i]+nums[j]+nums[n];
				if(abs(sum-target)<abs(result-target))
					result=sum;
				else
				{
					if(sum>target)
					{
						n--;
					}
					else if(sum==target)
						return target;
					else
					{
						j++;
					}
				}
				
			}
		}
		return result;
    }
};

int main()
{
	Solution s;
	int arr[]={0,2,1,-3};
	vector<int> ivec(arr,arr+4);
	int  ret=s.threeSumClosest(ivec,1);
	cout<<ret<<endl;
	system("pause");
	return 0;
}