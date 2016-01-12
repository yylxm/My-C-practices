/*请实现一个函数，将一个字符串中的空格替换成“%20”。
例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。*/

#include <iostream>
#include <string>

using namespace std;


void replaceSpace(char *str, int length) {
	if (str==NULL || length<=0)
	{
		return ;
	}

	int len = 0;//原先的长度
	int space = 0;
	int i = 0;
	while (str[i]!='\0')//计算空格的数量和原始长度
	{
		++len;
		if (str[i] == ' ')
		{
			space++;
		}
		i++;
	}

	int end = len + 2 * space;
	if (end>length)
	{
		return;//长度不够
	}
	str[end--] = '\0';
	i = len - 1;
	while (i!=end)
	{
		if (str[i]==' ')
		{
			str[end--] = '0';
			str[end--] = '2';
			str[end--] = '%';
		}
		else
		{
			str[end--] = str[i];
		}
		i--;
	}
	
}


int main()
{
	char str[] = "We are friends.";
	cout << strlen(str) << endl;
	replaceSpace(str, 21);
	cout << str << endl;
	system("pause");
	return 0;
}