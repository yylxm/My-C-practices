#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

struct node
{
	int weight;
	struct node *parent;
	struct node *left;
	struct node *right;
};


//struct cmp
//{
	bool comp(node *a,node *b)
    {
		return a->weight<b->weight;
    }
//};

int main()
{
	int num;
	int sum=0;
	deque<node*> ipq;
	cout<<"Enter the number:";
	cin>>num;
	int n;
	node *p;
	node *par;
	for (int i=1;i<=num;++i)
	{
		p=new node;
		scanf("%d",&p->weight);
		p->left=NULL;
		p->right=NULL;
		ipq.push_back(p);
	}
	sort(ipq.begin(),ipq.end(),comp);
	while (ipq.size()!=1)
	{
		par=new node;
		node *q1=ipq.front();
		ipq.pop_front();
		node *q2=ipq.front();
		ipq.pop_front();
		q1->parent=par;
		par->left=q1;
		par->right=q2;
		par->weight=q1->weight+q2->weight;
		sum=sum+par->weight;
		ipq.push_back(par);
		int size=ipq.size();
		sort(ipq.begin(),ipq.end(),comp);
	}

	cout<<sum<<endl;
	system("pause");
	return 0;
}