#include <iostream>

using namespace std;

int Add(int num1, int num2)
{
	int sum, carry;
	do{
		sum = num1^num2;
		carry = (num1&num2) << 1;
		num1 = sum;
		num2 = carry;
	} while (num2 != 0);

	return num1;
}

int main()
{
	int num1, num2;
	cin >> num1 >> num2;
	int ret = Add(num1, num2);
	cout << ret << endl;
	system("pause");
	return 0;
}