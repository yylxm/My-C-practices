#include <iostream>
#include <stdio.h>
#include <stack>
#include <vector>
#include <string>

using namespace std;

#define is_digit(a)   (a>='0'&&a=<'9')

int PRI(char a)
{
	if((a=='+')||(a=='-'))
		return 1;
	else
	{
		 return 2;
	}
}

double ChaToDou(char a)
{
	return a-48;
}

double calculate(string str)
{
	stack<char> op;
	vector<char> num;
	char c;
	int i=0;
	/*转换成后缀表达式*/
	for(int i=0;i<str.size();++i)
	{
		c=str[i];
		if (c>='0'&&c<='9')
		{
			num.push_back(c);
		}
		else
		{
			if(op.size()==0)
				op.push(c);
			else
			{
				if (PRI(c)>PRI(op.top()))
				{
					op.push(c);
				}
				else
				{
					while (!op.empty())
					{
						num.push_back(op.top());
						op.pop();
					}
					op.push(c);
				}
			}
			
		}
	}
	while (!op.empty())
	{
		num.push_back(op.top());
		op.pop();
	}


	/*输出后缀表达式*/
	for(auto iter=num.begin();iter!=num.end();++iter)
	{
		cout<<*iter;
	}
	cout<<endl;


   /*后缀表达式计算*/
	stack<double> dst;
	for(auto iter=num.begin();iter!=num.end();++iter)
	{
		if((*iter)>='0'&&(*iter)<='9')
		{
			dst.push(ChaToDou(*iter));
		}
		else if((*iter)=='+')
		{
			double a=dst.top();
			dst.pop();
			double b=dst.top();
			dst.pop();
			dst.push(a+b);
		}
		else if((*iter)=='-')
		{
			double a=dst.top();
			dst.pop();
			double b=dst.top();
			dst.pop();
			dst.push(a-b);
		}
		else if((*iter)=='*')
		{
			double a=dst.top();
			dst.pop();
			double b=dst.top();
			dst.pop();
			dst.push(a*b);
		}
		else
		{
			double a=dst.top();
			dst.pop();
			double b=dst.top();
			dst.pop();
			dst.push(a/b);
		}
	}
	return dst.top();
}

int main()
{
	
	vector<string> svec;
	int r=0;
	double ret[100];
	string in;
	cin>>in;
	while ((strcmp(in.c_str(),"0"))!=0)
	{
		svec.push_back(in);
		cin>>in;
	}

	for(auto iter=svec.begin();iter!=svec.end();++iter,++r)
	{
		ret[r]=calculate(*iter);
		printf("%0.2lf\n",ret[r]);
	}

	system("pause");
	return 0;
}