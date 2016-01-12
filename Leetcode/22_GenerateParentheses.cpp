#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> svec;
		if(n==0) return svec;
		string str="";
		generate(svec,n,n,str);
		return svec;

    }
	void generate(vector<string >& ret,int left,int right,string str)
	{
		if(left==0&&right==0)
			ret.push_back(str);
		if(left>0)//可直接打印左括号，不影响规则
		{
			generate(ret,left-1,right,str+'(');
		}
		if(right>0&&left<right)//
		{
			generate(ret,left,right-1,str+')');
		}
	}
};

int main()
{
	int num;;
	cin>>num;
	Solution s;
	vector<string> ret;
	ret=s.generateParenthesis(num);
	for(auto iter=ret.begin();iter!=ret.end();++iter)
	{
		cout<<"\""<<*iter<<"\""<<" ";
	}
	cout<<endl;
	system("pause");
	return 0;
}