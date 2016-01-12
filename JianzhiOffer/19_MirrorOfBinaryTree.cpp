#include <iostream>
#include <deque>

using namespace std;

typedef struct Node
{
	int m_iValue;
	struct Node* m_pLeftChild;
	struct Node* m_pRightChild;
}TreeNode,*BinaryTree;

void CreateTree(BinaryTree &Root)//递归建立二叉树
{
	int value;
	cin>>value;
	if (value==-1)
	{
		Root=NULL;
	}
	else
	{
		Root =new TreeNode;
		Root->m_iValue=value;
		CreateTree(Root->m_pLeftChild);
		CreateTree(Root->m_pRightChild);
	}
}

void PrintTree(BinaryTree &Root)//先序打印二叉树
{
	if(Root==NULL)
		cout<<"#"<<" ";
	else
	{
		cout<<Root->m_iValue<<" ";
	    PrintTree(Root->m_pLeftChild);
	    PrintTree(Root->m_pRightChild);
	}
	
}

void PrintBinaryTree(TreeNode* T)//23题的函数
{
	if (T==NULL)
	{
		return;
	}

	deque<TreeNode*> QueueData;
	QueueData.push_back(T);
	while (!QueueData.empty())
	{
		TreeNode * pNode = QueueData.front();
		QueueData.pop_front();

		cout<<pNode->m_iValue<<" ";

		if (pNode->m_pLeftChild)
		{
			QueueData.push_back(pNode->m_pLeftChild);
		}
		if (pNode->m_pRightChild)
		{
			QueueData.push_back(pNode->m_pRightChild);
		}		
	}
} 

void MirrorRecursively(TreeNode* Root)//求二叉树的镜像
{
	if (Root==NULL)
	{
		return ;
	}
	if (Root->m_pLeftChild==NULL && Root->m_pRightChild==NULL)
	{
		return ;
	}

	TreeNode* pTemp=Root->m_pLeftChild;
	Root->m_pLeftChild=Root->m_pRightChild;
	Root->m_pRightChild=pTemp;

	if(Root->m_pLeftChild)
		MirrorRecursively(Root->m_pLeftChild);
	if(Root->m_pRightChild)
		MirrorRecursively(Root->m_pRightChild);
}

int main()
{
	BinaryTree T=NULL;
	CreateTree(T);
	PrintBinaryTree(T);
	cout<<endl;
	MirrorRecursively(T);
	PrintTree(T);
	system("pause");
	return 0;
}