#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * */struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {       
		if(head==NULL || head->next==NULL) return head;
        ListNode *first=head;		
		ListNode *pre=head;;
        ListNode *second;

		second=first->next;//单独处理头结点
		first->next=second->next;
		second->next=first;
		head=second;
		pre=first;
		first=first->next;

		while(first!=NULL&&first->next!=NULL)//注意&&的前后顺序
		{
			second=first->next;
		    first->next=second->next;
		    second->next=first;
			pre->next=second;
		    pre=first;
		    first=first->next;
		}
		return head;
    }
	ListNode *swapPairs2(ListNode *head) //递归法，清晰明了
    {
        if(!head) return NULL;

        if(head->next)
        {
            ListNode *temp = head, *nextHead = head->next->next;
            head = head->next;
            head->next = temp;
            head->next->next = swapPairs(nextHead);
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

	p->next=new ListNode(11);
    p=p->next;

	Solution s;
	l1=s.swapPairs(l1);
	while(l1!=NULL)
	{
		cout<<l1->val<<" ";
		l1=l1->next;
	}
	cout<<endl;
	system("pause");
	return 0;
}