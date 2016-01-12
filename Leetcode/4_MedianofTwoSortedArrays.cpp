#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		double ret;
        int len1=nums1.size();
		int len2=nums2.size();
		int sum=len1+len2;
		for(int i=0;i<len2;++i)
			nums1.push_back(nums2[i]);
		sort(nums1.begin(),nums1.end());
		if(sum%2==1)
			ret=nums1[sum/2];
		else
			ret=double(nums1[sum/2]+nums1[sum/2-1])/2.0;

		return ret;
    }
};

int main()
{
	int arr1[]={3,7,9,12,34,45};
	int arr2[]={2,3,4,6,18,22,36,40};

	vector<int> vec1(arr1,arr1+6);
	vector<int> vec2(arr2,arr2+8);

	Solution s;
	double ret;
	ret=s.findMedianSortedArrays(vec1,vec2);
	cout<<ret<<endl;
	
	system("pause");
	return 0;
}