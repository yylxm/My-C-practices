#include<iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}//¹¹Ôìº¯Êý
};

class Solution{
public :
	ListNode *addTwoNumbers(ListNode *l1,ListNode *l2)
	{
		int temp;
		int flag=0;	
		ListNode *Head,*p;

		if(l1==NULL)return l2;
		else if(l2==NULL)return l1;
		else
		{
			temp=l1->val+l2->val;
			if(temp>9)
			{
				p=new ListNode(temp-10);
				flag=1;
			}
			else
				p=new ListNode(temp);
			l1=l1->next;
			l2=l2->next;

        }
		Head=p;	
		while(l1&&l2)
		{
			ListNode *node=new ListNode(0);
			int temp=l1->val+l2->val+flag;
			if(temp>9)
			{
				temp=temp-10;			
				node->val=temp;
			//	cout<<"jsa"<<p->val<<endl;
				flag=1;
			}
			else
			{
				node->val=temp;
				flag=0;
			}

			l1=l1->next;
			l2=l2->next;
			
			p->next=node;
			p=p->next;

			
		}
		while(l1)
		{
			ListNode *node=new ListNode(0);
			int temp=l1->val+flag;
			if(temp>9)
			{
				temp=temp-10;
				node->val=temp;
			    flag=1;
			}
			else
			{
				node->val=temp;
				flag=0;
			}
			
			
			p->next=node;	
			p=p->next;
			l1=l1->next;
		}		
		while(l2)
		{
			ListNode *node=new ListNode(0);
			int temp=l2->val+flag;
			if(temp>9)
			{
				temp=temp-10;
				node->val=temp;
				flag=1;
			}
			else
			{
				node->val=temp;
				flag=0;
			}

			p->next=node;	
			p=p->next;
			l2=l2->next;
		}		
		if (flag==1)
		{
			ListNode *node=new ListNode(1);
			p->next=node;
			p=p->next;
		}
		return Head;
	}
};

int main()
{
	ListNode *l1=new ListNode(0);
	ListNode *l2=new ListNode(0);
	ListNode *p=l1;
	ListNode *q=l2;
	ListNode *ret;
	int n=3,m=3;
	while(n>0)
	{
		ListNode *node=new ListNode(n+2);
		p->next=node;
		p=p->next;
		n--;
	}
	while(m>0)
	{
		ListNode *node=new ListNode(m+6);
		q->next=node;
		q=q->next;
		m--;
	}
	//while(l1!=NULL)
	//	{cout<<l1->val<<' ';
	//l1=l1->next;}
	//cout<<endl;
	Solution h;
	ret=h.addTwoNumbers(l1,l2);
	while(ret!=NULL)
	{
		cout<<ret->val<<' ';
		ret=ret->next;
	}
	cout<<endl;

	system("pause");
	return 0;

}