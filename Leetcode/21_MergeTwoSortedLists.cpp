#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Definition for singly-linked list.
 **/ struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL) return l2;
		if(l2==NULL) return l1;

		ListNode *head,*p;
		if(l1->val<l2->val)
		{	
			head=l1;
			l1=l1->next;
		}
		else
		{
			head=l2;
			l2=l2->next;
		}

		p=head;

		while(l1&&l2)
		{
			if(l1->val<l2->val)
			{
				p->next=l1;
				l1=l1->next;
				p=p->next;
			}
			else
			{
				p->next=l2;
				l2=l2->next;
				p=p->next;
			}
		}

		if(l1)
		{
			p->next=l1;
		}

		if(l2)
		{
			p->next=l2;
		}

		return head;
    }
};

int main()
{
	ListNode *l1=new ListNode(1);
	ListNode *p;
	p=l1;

	p->next=new ListNode(3);
    p=p->next;
	
	p->next=new ListNode(4);
	p=p->next;

	p->next=new ListNode(7);
	p=p->next;

	p->next=new ListNode(9);
    p=p->next;

	ListNode *l2=new ListNode(1);
	ListNode *q;
	q=l2;

	q->next=new ListNode(3);
    q=q->next;
	
	q->next=new ListNode(4);
	q=q->next;

	q->next=new ListNode(10);
	q=q->next;

	q->next=new ListNode(11);
    q=q->next;

	Solution s;
	l1=s.mergeTwoLists(l1,l2);

	while(l1!=NULL)
	{
		cout<<l1->val<<" ";
		l1=l1->next;
	}
	cout<<endl;
	system("pause");
	return 0;
}