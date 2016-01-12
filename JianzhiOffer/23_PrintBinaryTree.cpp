#include <iostream>
#include <deque>

using namespace std;

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_Right;
};

void PrintBinarytree(BinaryTreeNode* T)
{
	if (T==NULL)
	{
		return;
	}

	deque<BinaryTreeNode*> QueueData;
	QueueData.push_back(T);
	while (!QueueData.empty())
	{
		BinaryTreeNode * pNode = QueueData.front();
		QueueData.pop_front();

		cout<<pNode->m_nValue<<" ";

		if (pNode->m_pLeft)
		{
			QueueData.push_back(pNode->m_pLeft);
		}
		if (pNode->m_Right)
		{
            QueueData.push_back(pNode->m_Right);
		}		
	}
}

int main()
{
	//≤‚ ‘‘⁄19Ã‚¥¶
	system("pause");
	return 0;
}