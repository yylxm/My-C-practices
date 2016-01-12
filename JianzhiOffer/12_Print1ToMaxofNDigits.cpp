#include <iostream>

using namespace std;

void PrintNumber(char* number)
{
	bool isbegin0 = true;
	int length=strlen(number);
	for (int i = 0; i < length; i++)
	{
		if(isbegin0&&number[i]!='0')
		{
			isbegin0 = false;
		}
		if(!isbegin0)
		{
			cout<<number[i];
		}
	}
	cout<<endl;
}

void Print1ToMaxOfNDigitsRecursively(char* number,int length,int index)
{
	if(index==length-1)
	{
		PrintNumber(number);
		return;
	}

	for (int i = 0; i < 10; i++)
	{
		number[index+1]=i+'0';
		Print1ToMaxOfNDigitsRecursively(number,length,index+1);
	}
}

void Print1ToMaxOfNDigits(int n)
{
	if(n<=0)
		return ;
	char* number = new char[n+1];
	number[n]='\0';

	for (int i = 0; i < 10; i++)
	{
		number[0]=i+'0';
		Print1ToMaxOfNDigitsRecursively(number,n,0);
	}

	delete []number;
}

int main()
{
	int n;
	cin>>n;
	Print1ToMaxOfNDigits(n);
	system("pause");
	return 0;
}