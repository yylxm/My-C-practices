#include <iostream>

using namespace std;
struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode *m_pLeft;
	BinaryTreeNode *m_pRight;

};

bool VerifySequenceOfBST(int sequence[],int length)
{
	if (sequence==NULL || length<=0)
	{
		return false;
	}

	int root=sequence[length-1];

	int i=0;
	for (; i < length-1; i++)
	{
		if(sequence[i]>root)
			break;
	}
	int j=i;
	for (; j < length-1; j++)
	{
		if (sequence[j]<root)
		{
			return false;
		}
	}

	bool left=true;
	if(i>0)
		left=VerifySequenceOfBST(sequence,i);

	bool right=true;
	if (i<length-1)
		right=VerifySequenceOfBST(sequence+i,length-i-1);

	return(left && right);
}

int main()
{
	int arr[]={5,7,6,9,11,10,8};
	if (VerifySequenceOfBST(arr,7))
	{
		cout<<"yes!"<<endl;
	}
	else
	{
		cout<<"no!"<<endl;
	}
	system("pause");
	return 0;
}