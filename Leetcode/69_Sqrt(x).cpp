/*#include <iostream>

using namespace std;

class Solution {
public:
	int mySqrt(int x) {
		if (x <= 1)
			return x;
		int start = 0;
		int end = x;
		while (start<end-1)
		{
			int middle = (start + end) / 2;
			if (x / middle == middle)
				return middle;
			else if ((x / middle) > middle)
			{
				start = middle;
			}
			else
				end = middle;
		}
		return end - 1;
	}
};

int main()
{
	int n;
	cin >> n;
	Solution s;
	int ret = s.mySqrt(n);
	cout << ret << endl;
	system("pause");
	return 0;
}*/
#include<stdio.h>
#include<iostream>
using namespace std;
char buffer[6] = { 0 };
char *mystring(){
	char *s = "Hello world";
	for (int i = 0; i<(sizeof(buffer)-1); i++){
		buffer[i] = *(s + i);
	}
	return buffer;
}
void test1()
{
	unsigned char array[CHAR_MAX + 1], i;
	for (i = 0; i <= CHAR_MAX; i++){
		array[i] = i;
	}
}

void test3(){
	char str[10];
	str++;
	*str = '0';
}
int main(int args, char**argv){
	printf("%s\n", mystring());
	system("pause");
	return 0;
}