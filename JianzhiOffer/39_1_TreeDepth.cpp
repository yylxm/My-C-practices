#include <iostream>

using namespace std;

struct TreeNode
{
	int m_Value;
	TreeNode* m_pLeft;
	TreeNode* m_pRight;
};

int TreeDepth(TreeNode *pHead)
{
	if (pHead == NULL)
		return 0;
	int nLeft = TreeDepth(pHead->m_pLeft);
	int nRigth = TreeDepth(pHead->m_pRight);

	return (nLeft > nRigth) ? (nLeft + 1) : (nRigth + 1);
}

int main()
{
	system("pause");
	return 0;
}