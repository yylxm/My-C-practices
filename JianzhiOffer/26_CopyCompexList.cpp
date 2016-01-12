#include <iostream>

using namespace std;

struct ComplexListNode
{
	int m_nValue;
	ComplexListNode* m_pNext;
	ComplexListNode* m_pSbling;
};

void CloneNode(ComplexListNode*Head)//复制节点A,A',B,B'C,C'这样的形式
{
	if (Head == NULL)
		return;
	ComplexListNode *p = Head;
	while (p!=NULL)
	{
		ComplexListNode* pClone = new ComplexListNode();
		pClone->m_nValue=p->m_nValue;
		pClone->m_pNext=p->m_pNext;
		pClone->m_pSbling==NULL;

		p->m_pNext = pClone;

		p= pClone->m_pNext;
	}
}

void ConnectSiblingNodes(ComplexListNode* pHead)
{
	ComplexListNode* pNode = pHead;
	while (pNode != NULL)
	{
		ComplexListNode* pClone = pNode->m_pNext;
		if (pNode->m_pSbling!=NULL)
		{
			pClone->m_pSbling = pNode->m_pSbling->m_pNext;
		}
		pNode = pClone->m_pNext;
	}
}

ComplexListNode* ReconnectNodes(ComplexListNode* Head)
{
	ComplexListNode* pNode = Head;
	ComplexListNode* pCloneHead = NULL;
	ComplexListNode* pCloneNode = NULL;

	if (pNode!=NULL)
	{
		pCloneHead = pCloneNode = pNode->m_pNext;
		pNode->m_pNext = pCloneNode->m_pNext;
		pNode = pCloneNode->m_pNext;
	}

	while (pNode!=NULL)
	{
		pCloneNode->m_pNext = pNode->m_pNext;
		pCloneNode = pCloneNode->m_pNext;
		pNode->m_pNext = pCloneNode->m_pNext;
		pNode = pNode->m_pNext;
	}
	return pCloneHead;
}

ComplexListNode* Clone(ComplexListNode* pHead)
{
	CloneNode(pHead);
	ConnectSiblingNodes(pHead);
	return ReconnectNodes(pHead);
}

int main()
{
	system("pause");
	return 0;
}