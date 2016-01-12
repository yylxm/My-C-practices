#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
		int count=1;
		for(int i=1;i<nums.size();++i)
		{
			int j=i-1;
			if(nums[i]==nums[j])
			{
				continue;
			}
			else
			{
				nums[count]=nums[i];
				count++;
			}
		}
		return count;
    }
};

int main()
{
	int arr[]={1,2,2,3,4,4,5,6};
	vector<int> ivec(arr,arr+8);
	Solution s;
	int ret=s.removeDuplicates(ivec);
	cout<<ret<<endl;
	system("pause");
	return 0;
}