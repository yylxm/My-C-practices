#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
		int value[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
		string Char[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
		string ret="";
		for(int i=0; i<13; ++i)
		{
			while(num>=value[i])
			{	
				num=num-value[i];
				ret=ret+Char[i];
			}

		}
		return ret;

    }
};

int main()
{
	Solution s;
	int num;
	cin>>num;
	string ret=s.intToRoman(num);
	cout<<ret<<endl;
	
	system("pause");
	return 0;
}