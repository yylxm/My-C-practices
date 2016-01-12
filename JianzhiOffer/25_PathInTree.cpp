#include <iostream>
#include <vector>

using namespace std;

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

void FindPath(BinaryTreeNode* pRoot,int exceptedSum,vector<int>&path,int currentSum)
{
	currentSum += pRoot->m_nValue;
	path.push_back(pRoot->m_nValue);

	bool isLeaf = pRoot->m_pLeft ==NULL && pRoot->m_pRight==NULL;

	if (currentSum == exceptedSum && isLeaf)
	{
		cout<<"A path is found:";

		for (auto iter=path.begin();iter!=path.end();++iter)
		{
			cout<<*iter<<" ";
		}
		cout<<endl;
	}

	if(pRoot->m_pLeft!=NULL)
		FindPath(pRoot->m_pLeft,exceptedSum,path,currentSum);
	if(pRoot->m_pRight!=NULL)
		FindPath(pRoot->m_pRight,exceptedSum,path,currentSum);

	path.pop_back();
}

void FindPath(BinaryTreeNode* pRoot,int expectedSum)
{
	if (pRoot==NULL)
	{
		return;
	}

	vector<int> path;//用vector实现堆栈的功能，
	int currentSum=0;
	FindPath(pRoot,expectedSum,path,currentSum);
}

int main()
{
	system("pause");
	return 0;
}