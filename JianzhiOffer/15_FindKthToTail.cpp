#include <iostream>

using namespace std;

struct ListNode
{
	int m_pValue;
	ListNode* m_pNext;
};

ListNode* FindKthToTail(ListNode* head,int k)
{
	if(head==NULL||k==0) return NULL;
	ListNode* first;
	ListNode* second;
	first=second=head;
	while (k-1>0 && second->m_pNext!=NULL)
	{
		second=second->m_pNext;
		k--;
	}
	if(second->m_pNext==NULL)
		return NULL;

	while (second->m_pNext!=NULL)
	{
		first=first->m_pNext;
		second=second->m_pNext;
	}
	cout<<first->m_pValue<<endl;
	return first;
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

	p=FindKthToTail(head,0);
	if(p!=NULL)
		 cout<<p->m_pValue<<endl;
	system("pause");
	return 0;
}