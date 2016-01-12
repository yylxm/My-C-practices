#include <iostream>

using namespace std;


unsigned int FindFirstBitIs1(int num)
{
	int indexBit = 0;
	while (((num&1)==0)&&(indexBit<8*sizeof(int)))
	{
		num = num >> 1;
		indexBit++;
	}
	return indexBit;
}

bool IsBit1(int num, unsigned int indexBit)
{
	num = num >> indexBit;
	return(num & 1);
}

void FindNumsAppearsOnce(int data[], int length, int *num1, int *num2)
{
	if (data == NULL || length < 2)
		return;
	int resultOfOR = 0;
	for (int i = 0; i < length; i++)
	{
		resultOfOR = resultOfOR^data[i];
	}

	unsigned int indexOf1 = FindFirstBitIs1(resultOfOR);

	*num1 = *num2 = 0;
	for (int i = 0; i < length; i++)
	{
		if (IsBit1(data[i], indexOf1))
			*num1 = (*num1^data[i]);
		else
			*num2 = (*num2^data[i]);
	}
}

int main()
{
	int data[] = { 2, 4, 3, 6, 3, 2, 5, 5 };
	int num1, num2;
	FindNumsAppearsOnce(data, 8, &num1, &num2);
	cout << num1 << " " << num2 << endl;
	system("pause");
	return 0;
}