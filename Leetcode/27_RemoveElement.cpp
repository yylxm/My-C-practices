#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
    //    if(nums.empty()) return 0;
		int count=0;		
		for(int i=0;i<nums.size();++i)
		{
			if(nums[i]==val)
			{
				continue;
			}
			else
			{
				nums[count++]=nums[i];
			}
		}
		return  count;
    }
};

int main()
{
	int arr[]={2,3,4,5,2,4};
	vector<int> ivec(arr,arr+6);
	Solution s;
	int ret=s.removeElement(ivec,2);
	cout<<ret<<endl;
	system("pause");
	return 0;
}