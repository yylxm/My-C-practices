#include<iostream>
#include<stdint.h>

using namespace std;

class Solution{
public:
	uint32_t reverseBits(uint32_t n){
		uint32_t sum=0;
		for(int i=0;i<32;++i)
		{
		    sum=sum*2+(n&1);
			n>>=1;
		}	
		return sum;
	}
};

int main()
{
   Solution s;
   cout<<s.reverseBits(43261596);

   system("pause");
   return 0;
}