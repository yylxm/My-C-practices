#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
	char str[100];	
	map<int,string> mymap;//完成数字到字母的映射
public:
	
    vector<string> letterCombinations(string digits) {
		vector<string > ret;//存放结果
		if(digits.empty()) {return ret;}//在输入为“”的情况下，输出为空，没有双引号

		/*数字到字母的映射*/
		mymap[0]="";
		mymap[1]="";
		mymap[2]="abc";
		mymap[3]="def";
		mymap[4]="ghi";
		mymap[5]="jkl";
		mymap[6]="mno";
		mymap[7]="pqrs";
		mymap[8]="tuv";
		mymap[9]="wxyz";
		dfs(digits,0,digits.size(),ret);
		return ret;

    }

	void dfs(string digits, int i,int len,vector<string> &ret)//深度优先搜索
	{
		if(i==len)
		{
			str[len]='\0';
			ret.push_back(str);
			return;
		}
		else
		{
			for(int j=0;j<mymap[digits[i]-'0'].size();++j)
			{
				str[i]=mymap[digits[i]-'0'][j];
				dfs(digits,i+1,len,ret);
			}
		}
	}
};

int main()
{
	Solution s;
	string nums;
	nums="";
	vector<string> ret;
	ret=s.letterCombinations(nums);
	
	if(ret.empty()) cout<<endl;
	else
	{
		auto iter=ret.begin();
		for(;iter!=ret.end()-1;++iter)
	    {
		     cout<<"\""<<*iter<<"\""<<", ";
	    }
		cout<<"\""<<*iter<<"\""<<endl;
	}	
	system("pause");
	return 0;
}