#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
		vector<vector<int> > result;

        if(nums.size()<3) return result;

		sort(nums.begin(),nums.end());

		int a,b,c;
		int j,k;
		int n=nums.size();
		for(int i=0;i<=n-3;i++)
		{
			a=nums[i];
			if(a>0) break;//如果a大于0，则b,c,必大于0
			if(i>0 && nums[i]==nums[i-1])//防止重复
			{
				continue;
			}
			j=i+1;
			k=n-1;
			while(j<k)
			{
				b=nums[j];
				c=nums[k];
				if(a+b+c==0)
				{	
					if(nums[j]==nums[j-1] && j>i+1)//防止重复
					{
						j++;
						continue;
					}
					vector<int > tmp;
					tmp.push_back(a);
					tmp.push_back(b);
					tmp.push_back(c);
					result.push_back(tmp);
					j++;//找到一个满足条件的等式，继续寻找
				}
				else if(a+b+c>0)
				{
					k--;				
				}
				else
				{
					j++;
					
				}
			}
		}
		return result;
    }
};

int main()
{
	Solution s;
	int arr[]={-1,0,1,2,-1,-4};
	vector<int> ivec(arr,arr+6);

	vector<vector<int> > ret;
	ret=s.threeSum(ivec);

	for(auto iter=ret.begin();iter!=ret.end();++iter)
	{
		cout<<"("<<(*iter)[0]<<","<<(*iter)[1]<<","<<(*iter)[2]<<")"<<endl;
	}
	system("pause");
	return 0;
}