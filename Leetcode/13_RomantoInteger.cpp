#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
		map<char,int> mymap;
		mymap['M']=1000;  mymap['m']=1000;// mymap["CM"]=900;
		mymap['D']=500;   mymap['d']=500;// mymap["CD"]=400;
		mymap['C']=100;   mymap['c']=100; // mymap["XC"]=90;
        mymap['L']=50;    mymap['l']=50;//  mymap["XL"]=400;
        mymap['X']=10;    mymap['x']=10;// mymap["IX"]=9;
		mymap['V']=5;     mymap['v']=5;// mymap["IV"]=4;
		mymap['I']=1;     mymap['i']=1;
		int sum=0;
		for(int i=0;i<s.size();++i)
		{
			int num=0;
			int j=i+1;
			if(j<s.size()&&mymap[s[i]]<mymap[s[j]] )//注意先判断是否越界，再判断是否小于，否则会出现溢出中断
			{
				sum=sum+mymap[s[j]]-mymap[s[i]];   //罗马字母的规律
				i=j;
			}
			else
				sum=sum+mymap[s[i]];
			
		}
		return sum;
    }
};

int main()
{
	Solution s;
	string str;
	cin>>str;
	int ret=s.romanToInt(str);
	cout<<ret<<endl;
	system("pause");
	return 0;
}