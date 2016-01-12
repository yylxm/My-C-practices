#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

//#define letter(a) ((a>='a'&&a<='z')||(a>='A'&&a<='Z'))

int main()
{
	char in[100];
	char out[100];
	int i;
	cout<<"Enter the string:"<<endl;
	cin>>in;
	stack<int> bst;
	for(i=0;i<strlen(in);++i)
	{
		if(in[i]=='(')
		{
			bst.push(i);
			out[i]=' ';
		}
		else if(in[i]==')')
		{
			if(!bst.empty())
			{
				bst.pop();
				out[i]=' ';
			}
			else
			{
				out[i]='?';
			}
		}
		else
		{
			out[i]=' ';
		}
	}
	out[++i]=0;
	while (!bst.empty())
	{
		int j=bst.top();
		bst.pop();
		out[j]='$';
	}

	
	cout<<out<<endl;
	system("pause");
	return 0;
}