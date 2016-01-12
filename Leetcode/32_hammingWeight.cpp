#include<iostream>
#include<stdint.h>

using namespace std;

class solution
{
public:
	int hm(uint32_t n){
		int num=0;
		while(n>0)
		{
			if(n&1!=0)
				num++;
			n=n>>1;		
		}
		return num;
	}

};

int main()
{
	solution h;
	cout<<h.hm(7)<<endl;

	system("pause");
	return 0;
	
}