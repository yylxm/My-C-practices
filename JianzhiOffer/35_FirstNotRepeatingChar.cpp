#include <iostream>

using namespace std;

char FirstNotRepeatingChar(char* pString)
{
	if (pString == NULL)
		return '\0';

	const int tablesize = 256;
	unsigned int hashtable[tablesize];
	for (int i = 0; i < tablesize; i++)
	{
		hashtable[i] = 0;
	}
	int length = strlen(pString);
	for (int i = 0; i < length; i++)
	{
		hashtable[pString[i]]++;
	}

	for (int i = 0; i < length; i++)
	{
		if (hashtable[pString[i]] == 1)
		{
			return pString[i];
			break;
		}
	}
	return '\0';
}

int main()
{
	char * arr = "ABCDABCD";
	char ret = FirstNotRepeatingChar(arr);
	cout << ret << endl;
	system("pause");
	return 0;
}