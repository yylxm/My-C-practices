#include <iostream>
#include <math.h>
#include <vector>
#include <set>

using namespace std;

void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int Partition(int *number, int length, int start, int end)
{
	if (number == NULL || length<=0 || start<=0 || end>=length )
	{
		throw new exception("Invalid Parameters");
	}
	int index =start + rand()%(end - start) ;
	Swap(number[index], number[end]);

	int small = start - 1;
	for ( index = start; index < end; index++)
	{
		if (number[index]<number[end])
		{
			++small;
			if (small!=index)
			{
				Swap(number[index], number[small]);
			}
		}
	}

	++small;
	Swap(number[small], number[end]);
	return small;
}


void KLeastNumbers(int *input, int n,int k)
{
	if (input == NULL || n <= 0 || k <= 0 || k > n)
	{
		return;
	}

	int start = 0;
	int end = n - 1;
	int index = Partition(input, n, start, end);
	while (index != k-1)
	{
		if (index>k-1)
		{
			end = index - 1;
			index = Partition(input, n, start, end);
		}
		else
		{
			start = index + 1;
			index = Partition(input, n, start, end);
		}
	}
	for (int i = 0; i < k; i++)
	{
		cout<< input[i]<<" ";
	}
	cout << endl;
}

void BigDataKLeastNumbers(const vector<int>& input, multiset<int, greater<int> > leastnumbers, int k)
{
	leastnumbers.clear();
	if (k<0||k>input.size())
	{
		return;
	}

	vector<int>::const_iterator iter = input.begin();
	for (; iter!=input.end(); iter++)
	{
		if (leastnumbers.size()<k)
		{
			leastnumbers.insert(*iter);
		}
		else
		{
			auto iterGreater = leastnumbers.begin();
			if (*iter < (*iterGreater) )
			{
				leastnumbers.erase(iterGreater);
				leastnumbers.insert(*iter);
			}
		}
	}

}

int main()
{
	int number[] = { 3, 7, 5, 6, 12, 10, 14, 8, 9, 11 };
	KLeastNumbers(number, 10, 4);
	system("pause");
	return 0;
}