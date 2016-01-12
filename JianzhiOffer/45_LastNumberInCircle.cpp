#include <iostream>
#include <list>

using namespace std;

typedef struct node//建立链表
{
	node *next;
	int data;
	node() :data(-1), next(NULL){};
}node;

int LastRemaining(unsigned int n, unsigned int m)
{
	if (n < 1 || m < 1)
		return -1;

	int last = 0;
	for (int i = 2; i <= n; i++)
	{
		last = (last + m) % i;
	}

	return last;
}

int LastRemaining2(unsigned int n, unsigned m)
{
	if (n < 1 || m < 1)
		return -1;
	list<int> numbers;
	for (int i = 0; i <n; i++)
	{
		numbers.push_back(i);
	}

	auto iter = numbers.begin();
	while (numbers.size()>1)
	{
		for (int i = 1; i < m; i++)
		{
			iter++;
			if (iter==numbers.end())//如果遍历到链表末尾，则需返回到头部
			{
				iter = numbers.begin();
			}
		}

		auto next = ++iter;
		if (next==numbers.end())
		{
			next = numbers.begin();
		}

		--iter;
		numbers.erase(iter);
		iter = next;
	}
	return *iter;
}


node* Createlist(int n)//建立循环链表
{
	node *ret = NULL;	
	if (n > 1)
	{
		int i = 0;
		node *p = new node;
		p->data = i;
		ret = p;
		i++;
		while (i <= n-1)
		{
			node *q = new node;
			q->data = i;
			p->next = q;
			p = p->next;
			i++;
		}
		p->next = ret;
	}
	else
	{
		ret = new node;
		ret->data = 0;
		ret->next = ret;
	}
	return ret;
}

int LastRemaining3(unsigned int n, unsigned m)
{
	if (n < 1 || m < 1)
		return -1;
	node *head = Createlist(n);

	node *h = head;
	m %= n;
	while (h!=h->next)
	{
		int i = 1;
		for (int i = 1; i < m-1; i++)
		{
			h = h->next;
		}
		cout << h->next->data<<" ";
		node *temp = h->next;
		h->next = h->next->next;
		h = h->next;
		delete temp;
	}
	//cout << h->data<<endl;
	return h->data;
}


int main()
{
	int n, m;
	cin >> n >> m;
	int ret = LastRemaining2(n, m);
	cout << ret << endl;
	system("pause");
	return 0;
}