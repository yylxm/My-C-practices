#include <iostream>

using namespace std;

struct ListNode
{
	int m_nValue;
	ListNode *m_pNext;
};

ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
{
	ListNode *pCopyHead1 = pHead1;
	ListNode *pCopyHead2 = pHead2;
	int countHead1 = 0;
	int countHead2 = 0;

	while (pCopyHead1!=NULL)//计算链表的长度
	{
		countHead1++;
		pCopyHead1 = pCopyHead1->m_pNext;
	}

	while (pCopyHead2!=NULL)
	{
		countHead2++;
		pCopyHead2 = pCopyHead2->m_pNext;
	}

	ListNode *pCopyHeadlong = pHead1;//重置链表操作头结点
	ListNode *pCopyHeadshort = pHead2;

	int difcount = countHead1 - countHead2;

	if (countHead1 < countHead2)
	{
		difcount = 0 - difcount;
		pCopyHeadlong = pHead2;
		pCopyHeadshort = pHead1;
	}

	while (difcount>0)
	{
		pCopyHeadlong = pCopyHeadlong->m_pNext;
	}

	while (pCopyHeadlong!=NULL && pCopyHeadshort!=NULL &&pCopyHeadlong!=pCopyHeadshort)
	{
		pCopyHeadlong = pCopyHeadlong->m_pNext;
		pCopyHeadshort = pCopyHeadshort->m_pNext;
	}

	ListNode *pFirstCommonNode = pCopyHeadlong;
	return pFirstCommonNode;

}

int main()
{
	system("pause");
	return 0;
}