#include <iostream>

using namespace std;

/**
* Definition for singly-linked list.
*/
typedef struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 }*Node;

class Solution {
public:
	void create(Node &head)
	{
		int a;
		cin >> a;
		ListNode *p = NULL;
		ListNode *q;		
		int i = 0;
		while (a!=0)
		{		
			if (i==0)
			{
				head = new ListNode(a);
				p = head;
				i++;
			}
			else
			{
				q = new ListNode(a);
				p->next = q;
				p = p->next;
			}	
			cin >> a;
		}
		
	}

	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL || head->next ==NULL)
		{
			return head;
		}
		ListNode *p = head->next;
		ListNode *pre = head;
		ListNode *temp;

		while (p!=NULL)
		{
			if (p->val == pre->val)
			{
				temp = p;
				pre->next = p->next;
				p = p->next;
				delete temp;
			}
			else
			{
				pre = p;
				p = p->next;
			}
		}
		return head;
	}
};

int main()
{
	ListNode *T=NULL;
	Solution s;
	s.create(T);
	s.deleteDuplicates(T);
	while (T!=NULL)
	{
		cout << T->val;
		T = T->next;
	}
	system("pause");
	return 0;
}