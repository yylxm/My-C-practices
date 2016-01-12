#include <iostream>

using namespace std;

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

BinaryTreeNode* Convert(BinaryTreeNode* pRootofTree)
{
	BinaryTreeNode *pLastNodeList = NULL;
	ConvertNode(pRootofTree,&pLastNodeList);

	BinaryTreeNode *pHeadOfList = pLastNodeList;
	while (pHeadOfList!=NULL && pHeadOfList->m_pLeft!=NULL)
	{
		pHeadOfList = pHeadOfList->m_pLeft;
	}

	return pHeadOfList;
}

void ConvertNode(BinaryTreeNode* pNode,BinaryTreeNode** pLastNodeInList)
{
	if (pNode == NULL)
	{
		return;
	}

	BinaryTreeNode* pCurrent = pNode;

	if (pNode->m_pLeft!=NULL)
	{
		ConvertNode(pNode->m_pLeft,pLastNodeInList);
	}

	pCurrent->m_pLeft = *pLastNodeInList;
	if (*pLastNodeInList != NULL)
	{
		(*pLastNodeInList)->m_pRight = pCurrent;
	}
	*pLastNodeInList = pCurrent;

	if(pCurrent->m_pRight != NULL)
	{
		ConvertNode(pCurrent->m_pRight,pLastNodeInList);
	}

}

int main()
{
	system("pause");
	return 0;
}