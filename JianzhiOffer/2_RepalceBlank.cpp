/*��ʵ��һ����������һ���ַ����еĿո��滻�ɡ�%20����
���磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��*/

#include <iostream>
#include <string>

using namespace std;


void replaceSpace(char *str, int length) {
	if (str==NULL || length<=0)
	{
		return ;
	}

	int len = 0;//ԭ�ȵĳ���
	int space = 0;
	int i = 0;
	while (str[i]!='\0')//����ո��������ԭʼ����
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
		return;//���Ȳ���
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