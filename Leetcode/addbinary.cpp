#include<iostream>
#include<string>

using namespace std;

class Solution{
public:
	string addBinary(string a,string b){
		int flag=0;
		int lena=a.size();
		int lenb=b.size();
		if(lena>lenb)
		{
			Swap(a,b);
			int temp=lena;
			lena=lenb;
			lenb=temp;		
		}
		int diff=lenb-lena;
		//string temp="1";
		int j=1;
		for(int i=lena-1;i>=0;--i)
		{
			if(b[i+diff]=='1'&&a[i]=='1'&&flag==0||b[i+diff]=='0'&&a[i]=='1'&&flag==1||b[i+diff]=='1'&&a[i]=='0'&&flag==1)
			{
				b[i+diff]='0';
				flag=1;
			}
			else if(b[i+diff]=='1'&&a[i]=='0'&&flag==0||b[i+diff]=='0'&&a[i]=='1'&&flag==0||b[i+diff]=='0'&&a[i]=='0'&&flag==1)
			{
				b[i+diff]='1';
				flag=0;
			}
			else if(b[i+diff]=='0'&&a[i]=='0'&&flag==0)
			{
				b[i+diff]='0';
				flag=0;
			}
			else
			{
				b[i+diff]='1';
				flag=1;
			}				
		}
		if(flag==1)
		{
			if(diff==0)//两者长度相等且flag=1，只需要增加一位即可
				b='1'+b;
			else{//
				while(b[diff-j]!='0'&&j<=diff)//b字符串相应位为1，则置0
			    {
				     b[diff-j]='0';
				     if (j==diff)//如果b字符串的最后一位仍为1，则需要加一位
				     {
					     b='1'+b;
					     break;
				      }
				     j++;				
			    }
			    if(j<diff)
				    b[diff-j]='1';//如果b中有一位不为1，则将其置1
			}

		}
		return b;			
	}
	void Swap(string &a,string &b)
	{
		string c;
		c=a;
		a=b;
		b=c;	
	}

	string addBinary2(string a, string b)
	{
		string s = "";

		int c = 0, i = a.size() - 1, j = b.size() - 1;
		while(i >= 0 || j >= 0 || c == 1)
		{
			c += i >= 0 ? a[i --] - '0' : 0;
			c += j >= 0 ? b[j --] - '0' : 0;
			s = char(c % 2 + '0') + s;
			c /= 2;
		}

		return s;
	}
};

int main()
{
	string a="11";
	string b="1";
	Solution h;
	string c;
	
	c=h.addBinary2(a,b);
	//printf("%s",c);
	cout<<c<<endl;
//cout<<a<<endl;
	cout<<'1'-'1'<<endl;

system("pause");
return 0;
	
}