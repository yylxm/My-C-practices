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
    ListNode* reverseKGroup(ListNode* head, int k) {
		if(k<=1||head==NULL || head->next==NULL) return head;
		int len=0;
        ListNode* p=head;
		while(p)//�����ܳ���
		{
			len++;
			p=p->next;
		}
		if(k>len) return head;

        /*���k���ڵ����ת*/
        p=head;
		ListNode *pre=p;
		ListNode *last=NULL;
		ListNode *mark=p;//��¼��ת����ĵ�һ���ڵ㣬�Ա㽫�������������������
		p=p->next;
		int n=1;
		while(n!=k&&p!=NULL)
		{
			last=p->next;
			p->next=pre;
			mark->next=last;
			pre=p;
			p=last;			
			n++;
		}


		if(len-k>=k)
			mark->next=reverseKGroup(p,k);//�ݹ����
		else
			mark->next=p;

		head=pre;
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

	p->next=new ListNode(13);
    p=p->next;

	p->next=new ListNode(15);
    p=p->next;

	Solution s;
	l1=s.reverseKGroup(l1,3);
	while(l1!=NULL)
	{
		cout<<l1->val<<" ";
		l1=l1->next;
	}
	cout<<endl;

	system("pause");
	return 0;
}