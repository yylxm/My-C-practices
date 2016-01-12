#include <iostream>

using namespace std;

void Swap(char &a, char &b)
{
	char temp;
	temp = a;
	a = b;
	b=a;
}

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

char* ReverseSentence(char *data)
{
	if (data == NULL)
		return NULL;
	char *pBegin = data;
	char *pEnd = data;
	while (*pEnd!='\0')
		pEnd++;
	--pEnd;

	Reverse(pBegin, pEnd);//翻转整个句子

	pEnd = pBegin;
	while (*pBegin != '\0')//翻转单个单词
	{
		if (*pBegin == ' ')
		{
			pBegin++;
			pEnd++;
		}
		else if (*pEnd == ' ' || *pEnd == '\0')
		{
			Reverse(pBegin, --pEnd);
			pBegin = ++pEnd;
		}
		else
			pEnd++;
	}

	return data;
}

int main()
{
	char data[] = "I am a Student.";//注意此处不能写成char *data=“I am a student.”如此定义，则使得data成为一个常量，无法对其进行修改
	char *ret;
	ret=ReverseSentence(data);
	while (*ret!='\0')
	{
		cout << *ret;
		ret++;
	}
	cout << endl;
	system("pause");
	return 0;
}

