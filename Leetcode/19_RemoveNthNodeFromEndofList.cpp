#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) { //˼·1
        /*��������ת*/
		if(head==NULL) return head;//headΪ��ֱ�ӷ���
		if(head->next==NULL && n==1) //����ֻ����һ��Ԫ�أ�ֱ��ɾ��
		{
			head=NULL;
			return head;
		}
		ListNode *q; //���ڼ�¼ͷ���
		ListNode *nex;//��һ���ڵ�
		ListNode *pre=NULL;//ǰһ���ڵ�
		ListNode *cur=head;//��ǰ�ڵ�
		while(cur!=NULL)
		{
			nex=cur->next;
			cur->next=pre;
			pre=cur;
			cur=nex;			
		}
		head=pre;

       /*ɾ���ض�λ���ϵ�ֵ*/
		q=head;
		if(n==1)
		{
			head=head->next;
		}
		else
		{
			while(--n)
		    {
			    pre=q;
			    q=q->next;
		     }
		     pre->next=q->next;
		}
		


		/*�ٴν�������ת*/
	    pre=NULL;
		cur=head;
		while(cur!=NULL)
		{
			nex=cur->next;
			cur->next=pre;
			pre=cur;
			cur=nex;
		}
		head=pre;


		return head;
    }

	ListNode* removeNthFromEnd2(ListNode* head, int n) //˼·2
	{
		if(head==NULL) return head;
		
		ListNode *first,*last,*pre=NULL;
		first=last=head;
		n--;
		while(n--&&last!=NULL)
		{
			last=last->next;
		}

		while(last->next!=NULL)
		{
			pre=first;
			first=first->next;
			last=last->next;
		}
		if(pre ==NULL)
		{
			head=first->next;
			delete first;
		}
		else
		{
			pre->next=first->next;
			delete first;
		}
		
		return head;
	}
};

int main()
{
	ListNode *head=new ListNode(1);
	ListNode *p;
	p=head;
/*
	p->next=new ListNode(2);
    p=p->next;
	
	p->next=new ListNode(3);
	p=p->next;

	p->next=new ListNode(4);
	p=p->next;

	p->next=new ListNode(5);
    p=p->next;
*/
	Solution s;
	head=NULL;
	head=s.removeNthFromEnd2(head,1);

	while(head!=NULL)
	{
		cout<<head->val<<"->";
		head=head->next;
	}

	system("pause");
	return 0;
}