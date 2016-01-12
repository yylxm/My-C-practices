#include <iostream>
#include <vector>

using namespace std;

int Minorder(vector<int> rotateArray,int low,int high)//À≥–Ú≤È’“
{
	int ret = rotateArray[low];
	for (int i = low; i <= high; i++)
	{
		if (ret > rotateArray[i])
			ret = rotateArray[i];
	}
	return ret;
}

int minNumberInRotateArray(vector<int> rotateArray) {

	int min = rotateArray[0];
	int low = 0;
	int high = rotateArray.size()-1;
	int middle;

	while (rotateArray[low]>=rotateArray[high])
	{
		if (high - low == 1)
		{
			middle = high;
			break;
		}

		middle = (low + high) / 2;

		if (rotateArray[low]==rotateArray[high] && rotateArray[middle] == rotateArray[low])
		{
			return Minorder(rotateArray, low, high);
		}

		if (rotateArray[middle] <= rotateArray[high])
		{
			high = middle;
		}
		else if (rotateArray[middle] >= rotateArray[low])
		{
			low = middle ;
		}
	}
	return rotateArray[middle];
}

int main()
{
	int arr[] = { 5,1,2,3,4 };
	vector<int> iv(arr, arr + 5);
	cout << minNumberInRotateArray(iv) << endl;
	system("pause");
	return 0;
}