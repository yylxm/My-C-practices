#include <iostream>

using namespace std;


void Reverse(char *pBegin, char *pEnd)
{
	if (pBegin == NULL || pEnd == NULL)
		return;

	while (pBegin < pEnd)
	{
		char temp = *pBegin;
		*pBegin = *pEnd;
		*pEnd = temp;

		pBegin++;
		pEnd--;
	}
}

char *LeftRotateString(char *pStr, int n)
{
	if (pStr == NULL || n > strlen(pStr)|| n < 0)
		return NULL;
	int length = static_cast<int>(strlen(pStr));
	char *FirstStart = pStr;
	char *FirstEnd = pStr + n - 1;
	char *SecondStart = pStr + n;
	char *SecondEnd = pStr + length - 1;

	Reverse(FirstStart, FirstEnd);
	Reverse(SecondStart, SecondEnd);
	Reverse(pStr, pStr + length - 1);

	return pStr;
}

int main()
{
	char data[] = "abcdef";
	char *ret = LeftRotateString(data, 2);
	while (*ret!='\0')
	{
		cout << *ret;
		ret++;
	}

	cout << endl;
	system("pause");
	return 0;
}