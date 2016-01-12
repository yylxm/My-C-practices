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
	if(pToBeDelete->m_pNext!=NULL) //Ҫɾ���Ľڵ㲻��β�ڵ�
	{
		ListNode* pNext=pToBeDelete->m_pNext;
		pToBeDelete->m_nValue=pNext->m_nValue;
		pToBeDelete->m_pNext=pNext->m_pNext;

		delete pNext;
		pNext=NULL;
	}

	else if(*pListHead == pToBeDelete) //����ֻ��һ���ڵ㣬ɾ��ͷ��㣨Ҳ��β�ڵ㣩
	{
		delete pToBeDelete;
		pToBeDelete = NULL;
		*pListHead=NULL;
	}
	else //�������ж���ڵ㣬ɾ��β�ڵ�
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