#include <iostream>

using namespace std;

struct ListNode
{
	int  m_nValue;
	ListNode * m_pNext;
};

void DeleteNode(ListNode** pListHead,ListNode* pToBeDelete)
{
	if(!pListHead|| !pToBeDelete)
		return;
	if(pToBeDelete->m_pNext!=NULL) //要删除的节点不是尾节点
	{
		ListNode* pNext=pToBeDelete->m_pNext;
		pToBeDelete->m_nValue=pNext->m_nValue;
		pToBeDelete->m_pNext=pNext->m_pNext;

		delete pNext;
		pNext=NULL;
	}

	else if(*pListHead == pToBeDelete) //链表只有一个节点，删除头结点（也是尾节点）
	{
		delete pToBeDelete;
		pToBeDelete = NULL;
		*pListHead=NULL;
	}
	else //链表中有多个节点，删除尾节点
	{
		ListNode *pNode = *pListHead;
		while (pNode->m_pNext!=pToBeDelete)
		{
			pNode=pNode->m_pNext;
		}

		pNode->m_pNext=NULL;
		delete pToBeDelete;
		pToBeDelete=NULL;
	}
}

int main()
{
	int n=5;

	ListNode* p= new ListNode;
	p->m_pNext=NULL;
	p->m_nValue=0;
	ListNode* head;
	head=p;
	while(n--)
	{		
		ListNode* q= new ListNode;	
		q->m_nValue=n+2;
		q->m_pNext=NULL;
		p->m_pNext=q;
		p=p->m_pNext;
        
	}
	
	p=head;
	while (p)
	{
		cout<<p->m_nValue<<" ";
		p=p->m_pNext;
	}



	system("pause");
	return 0;
}