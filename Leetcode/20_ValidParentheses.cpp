#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
		stack<char> mystack;
		for(int i=0;i<s.size();++i)
		{
			switch(s[i])
			{
			case '(':
				mystack.push(s[i]);
				break;
			case '[':
				mystack.push(s[i]);
				break;
			case '{':
				mystack.push(s[i]);
				break;
			case ')':
				if(!mystack.empty()&&mystack.top()=='(')
				{
					mystack.pop();
				}
				else
				{
					return false;
				}
					break;
			case ']':
				if(!mystack.empty()&&mystack.top()=='[')
				{
					mystack.pop();
				}
				else
				{
					return false;
				}
					break;
			case '}':
				if(!mystack.empty()&&mystack.top()=='{')
				{
					mystack.pop();
				}
				else
				{
					return false;
				}
			default:
				break;
			}
			
		}
        if(mystack.empty()) 
			return true;
		else 
			return false;
    }
};

int main()
{
	string str;
	cin>>str;
	Solution s;
	bool ret=s.isValid(str);
	if(ret)
		cout<<"YES!"<<endl;
	else
		cout<<"NO!"<<endl;
	system("pause");
	return 0;
}