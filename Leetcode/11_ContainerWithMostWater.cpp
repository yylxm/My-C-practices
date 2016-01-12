#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        
		int maxwater=0;
		int i=0;
		int j=height.size()-1;

		while(i<j)
		{
			int water= min(height[i],height[j])*(j-i);
			maxwater=max(water,maxwater);

			if(height[i]<=height[j])
				i++;
			else
				j--;
		}


		return maxwater;
    }
};


int main()
{
	int arr[]={4,6,3,7,9,10};
	vector<int> ivec(arr,arr+6);
	Solution s;

	int ret=s.maxArea(ivec);
	cout<<ret<<endl;
	system("pause");
	return 0;
}