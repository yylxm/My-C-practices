/*����һ��������β��ͷ��ӡ����ÿ���ڵ��ֵ�� */

#include<iostream>
#include<vector>
#include<stack>

using namespace std;


struct ListNode {
	int val;
    struct ListNode *next;
    ListNode(int x) :val(x), next(NULL) {}
  };


vector<int> printListFromTailToHead(struct ListNode* head) {
	vector<int> ret;
	stack<int> is;
	ListNode *p = head;
	while (p!=NULL)
	{
		is.push(p->val);
		p = p->next;
	}

	while (!is.empty())
	{
		ret.push_back(is.top());
		is.pop();
	}
	return ret;
}

int main()
{
	system("pause");
	return 0;
}