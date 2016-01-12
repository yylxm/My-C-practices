#include <iostream>

using namespace std;

int find_max(int arr[], int length)//�ҵ�����һ����
{
	int max = arr[0];
	for (int i = 1; i < length; ++i)
	{
		if (arr[i]>max)
			max = arr[i];
	}
	return max;
}

int digitnumber(int number)//�����ֵ�λ��
{
	int num = 0;
	while (number > 0)
	{
		number = number / 10;
		num++;
	}
	return num;
}

int kdigitnumber(int number,int k)//���kλ��Ԫ�أ��Ӹ�λ����ʼ����
{
	number = number / pow(10, k);
	return number % 10;
}

/*��������*/
void RadixSort(int arr[], int length)
{
	int *temp[10];//ָ�����飬ָ��10��Ͱ
	int max = find_max(arr,length);
	int maxDigit = digitnumber(max);
	int count[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };//ÿ��ͰԪ�صĸ���

	for (int i = 0; i < 10; ++i)//��Ͱ����ռ䣬����ʼ��
	{
		temp[i] = new int[length];
		memset(temp[i], 0, sizeof(int)*length);
	}

	for (int i = 0; i < maxDigit; i++)
	{
		memset(count, 0, sizeof(int)* 10);
		for (int j = 0; j < length; j++)
		{
			int x = kdigitnumber(arr[j], i);
			temp[x][count[x]] = arr[j];
			count[x]++;
		}

		int index = 0;//��Ͱ�е�Ԫ�ؽ����ռ�����
		for (int k = 0; k < 10; k++)
		{
			for (int m = 0; m < count[k]; m++)
			{
				arr[index++] = temp[k][m];
			}
		}
	}
}

void print(int arr[], int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	int arr[] = { 73, 673, 900, 545, 84, 10, 232, 489, 645, 100};
	RadixSort(arr, 10);
	print(arr, 10);
	system("pause");
	return 0;
}