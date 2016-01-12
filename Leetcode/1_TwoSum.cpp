#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>


using namespace std;

class Solution
{
public:
	vector<int > twoSum(vector<int>&nums,int target);
	void Output(vector<int>&ret);
};

vector<int >Solution::twoSum(vector<int>&nums,int target)
{
	vector<int>ret;
	/*for (int i=0;i<nums.size()-1;++i)
	{
		for (int j=i+1;j<nums.size();++j)
		{
			if ((nums[i]+nums[j])== target)
			{
				ret.push_back(i+1);
				ret.push_back(j+1);
				return ret;
			}
		}
	}*/

	unordered_map <int ,int> Map;
	int Size=nums.size();
	for (int i=0;i<Size;++i)
	{
		auto findex = Map.find(target-nums[i]);
		if (findex != Map.end())
		{
			ret.push_back(findex->second);
			ret.push_back(i+1);
			break;
		}
		else
		{
			Map[nums[i]]=i+1;
		}
	}

	return ret;
}

void Solution::Output(vector<int>&ret)
{
	cout<<"index1="<<ret[0];
	cout<<", index2="<<ret[1]<<endl;
}

int main()
{
	Solution s;
	int arr[]={2, 7};	
	vector<int >numbers(arr,arr+2);
	vector<int> result;
	int target;
	cin>>target;
	result=s.twoSum(numbers,target);
	s.Output(result);
	system ("pause");
	return 0;
}