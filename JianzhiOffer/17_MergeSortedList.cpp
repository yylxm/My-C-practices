#include <iostream>

using namespace std;

struct ListNode
{
	int m_pValue;
	ListNode* m_pNext;
};

ListNode* Merge(ListNode* p1,ListNode* p2)//µÝ¹éºÏ²¢
{
	if(p1==NULL && p2==NULL) return NULL;
	if(p1==NULL) return p2;
	if(p2==NULL) return p1;

	ListNode* head=NULL;
	if(p1->m_pValue<=p2->m_pValue)
	{
		head=p1;
		head->m_pNext=Merge(p1->m_pNext,p2);
	}
	else
	{	
		head=p2;
		head->m_pNext=Merge(p1,p2->m_pNext);
	}

	return head;

}

int main()
{
	int n=5;

	ListNode* p= new ListNode;
	p->m_pNext=NULL;
	p->m_pValue=0;
	ListNode* head1;
	int k=1;
	head1=p;
	while(n--)
	{		
		ListNode* q= new ListNode;	
		q->m_pValue=k+1;
		q->m_pNext=NULL;
		p->m_pNext=q;
		p=p->m_pNext;
		k++;
        
	}

	int m=4;

	ListNode* p2= new ListNode;
	p2->m_pNext=NULL;
	p2->m_pValue=0;
	ListNode* head2;
	int k2=3;
	head2=p2;
	while(m--)
	{		
		ListNode* q= new ListNode;	
		q->m_pValue=k2+2;
		q->m_pNext=NULL;
		p2->m_pNext=q;
		p2=p2->m_pNext;
		k2++;
      
	}

	head1=Merge(head1,head2);
	//head1=head2;
	while (head1!=NULL)
	{
		cout<<head1->m_pValue<<" ";
		head1=head1->m_pNext;
	}
	cout<<endl;
	system("pause");
	return 0;
}