#include <iostream>

using namespace std;

int InversePairsCore(int *data, int *copy, int start, int end)
{
	if (start == end)
	{
		copy[start] = data[start];
		return 0;
	}

	int length = (start + end) / 2;
	int left = InversePairsCore(data, copy, start, start + length-1);
	int right = InversePairsCore(data, copy, start + length , end);

	int i = start + length-1;//i��ʼ��Ϊǰ������һ�����ֵ��±�
	int j = end;//j��ʼ��Ϊǰ������һ�����ֵ��±�

	int indexCopy = end;
	int count = 0;
	while (i >= start && j >= start + length )//�鲢��������������ĸ���
	{
		if (data[i]>data[j])
		{
			copy[indexCopy--] = data[i--];
			count = count + j - start - length + 1;
		}
		else
		{
			copy[indexCopy--] = data[j--];
		}
	}

	for (; i >= start; i--)
	{
		copy[indexCopy--] = data[i];
	}

	for (; j >= start + length; j--)
		copy[indexCopy--] = data[j];

	return left + right + count;

}

int InversePairs(int *data, int length)
{
	if (data == NULL || length <= 0)
		return 0;

	int *copy = new int[length];
	for (int i = 0; i < length; i++)
		copy[i] = data[i];

	int count = InversePairsCore(data, copy, 0, length - 1);
	delete[]copy;

	return count;
}


int main()
{
	int data[] = {7 ,5, 6, 4 };
	int ret = InversePairs(data, 4);
	cout << ret << endl;
	system("pause");
	return 0;
}