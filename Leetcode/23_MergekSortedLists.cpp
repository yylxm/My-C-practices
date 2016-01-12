#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 */struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
		if(lists.empty()) return NULL;
        ListNode* head=lists[0];
		for(int i=1;i<lists.size();++i)
		{
			head=merge(head,lists[i]);
		}
		return head;
    }
	ListNode* merge(ListNode *head,ListNode* list)
	{
		if(head==NULL) return head;
		else if(list==NULL) return list;

		ListNode *pmergeHead=NULL;

		if(head->val<list->val)
		{
			pmergeHead=head;
			pmergeHead->next=merge(head->next,list);
		}
		else
		{
			pmergeHead=list;
			pmergeHead->next=merge(head,list->next);
		}
		return pmergeHead;
	}
};

int main()
{
	system("pause");
	return 0;
}