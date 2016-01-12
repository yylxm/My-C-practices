#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

const int g_MaxNumberLength = 10;
char* g_StrCombine1 = new char[g_MaxNumberLength * 2 + 1];
char* g_StrCombine2 = new char[g_MaxNumberLength * 2 + 1];

int compare(const void* strNumber1, const void* strNumber2)
{
	strcpy(g_StrCombine1, *(const char**)strNumber1);
	strcat(g_StrCombine1, *(const char**)strNumber2);

	strcpy(g_StrCombine2, *(const char**)strNumber2);
	strcat(g_StrCombine2, *(const char**)strNumber1);

	return strcmp(g_StrCombine1, g_StrCombine2);
}

void PrintMinNumber(int *numbers, int length)
{
	if (numbers == NULL || length <= 0)
		return;
	char** strNumbers = (char**)(new int[length]);
	for (int i = 0; i < length; i++)
	{
		strNumbers[i] = new char[g_MaxNumberLength + 1];
		sprintf(strNumbers[i], "%d", numbers[i]);
	}

	qsort(strNumbers, length, sizeof(char*), compare);

	for (int i = 0; i < length; i++)
		cout << strNumbers[i];
	cout << endl;

	for (int i = 0; i < length; i++)
	{
		delete[] strNumbers[i];
	}
	delete[] strNumbers;
}

int main()
{
	int arr[] = { 3, 32,32 };
	PrintMinNumber(arr, 3);
	system("pause");
	return 0;
}