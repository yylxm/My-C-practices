#include<iostream>
#include<string>
#include<ctype.h>
using namespace std;

int main()
{
	string n;
	char m[100];
	cin>>n;
	while (gets(m))
	{
		string str=m;//±£´æ³¤×Ö·û´®
		int startpos=0;
		int pos=str.find(n,startpos);
		while (pos!=string::npos)//É¾³ý¶Ì×Ö·û´®
		{
			str.erase(pos,n.size());
			pos=str.find(n,pos);
		}

		pos=str.find(' ',0);
		while (pos!=string::npos)//É¾³ý¿Õ¸ñ
		{
			str.erase(pos,1);
			pos=str.find(' ',pos);
		}
		cout<<str<<endl;
	}
	system("pause");
	return 0;
}