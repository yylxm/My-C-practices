#include <iostream>

using namespace std;

void Permutation(char *pStr, char *BeginStr)
{
	if (*BeginStr == '\0')
	{
		cout<<pStr;
	}
	else
	{
		for (char *i = BeginStr; *i != '\0' ; ++i)
		{
			char temp = *i;
			*i = (*BeginStr);
			*BeginStr=temp;

			Permutation(pStr,BeginStr+1);

			temp= *i;
			*i = (*BeginStr);
			*BeginStr = temp;

		}
	}
}

void Permutation(char *pStr)
{
	if(pStr==NULL)
		return;
	Permutation(pStr,pStr);
}



int main()
{
	char *a="abc";
	Permutation(a);
	system("pause");
	return 0;
}