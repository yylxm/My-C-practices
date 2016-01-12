#include <iostream>

using namespace std;

struct ListNode
{
	int m_pValue;
	ListNode* m_pNext;
};

ListNode* ReverseList(ListNode*head)
{
	if(head==NULL || head->m_pNext==NULL) return head;

	ListNode* pre=head;
	ListNode* curr=head;
	ListNode* next=head->m_pNext;
	ListNode* ReverseListHead=NULL;

	while (curr->m_pNext!=NULL)
	{
		if(curr==head)
		{
			curr->m_pNext=NULL;
			pre=curr;
			curr=next;
			next=curr->m_pNext;
		}
		else
		{
			curr->m_pNext=pre;
			pre=curr;
			curr=next;
			next=next->m_pNext;
		}
	}
	curr->m_pNext=pre;//注意若无此句则会导致curr链接中断
	ReverseListHead=curr;
	return ReverseListHead;
}

int main()
{
	int n=5;

	ListNode* p= new ListNode;
	p->m_pNext=NULL;
	p->m_pValue=0;
	ListNode* head;
	head=p;
	while(n--)
	{		
		ListNode* q= new ListNode;	
		q->m_pValue=n+2;
		q->m_pNext=NULL;
		p->m_pNext=q;
		p=p->m_pNext;
        
	}
	p=ReverseList(head);
	while (p!=NULL)
	{
		cout<<p->m_pValue<<" ";
		p=p->m_pNext;
	}
	cout<<endl;
	system("pause");
	return 0;
}