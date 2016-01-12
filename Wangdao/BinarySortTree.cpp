#include <iostream>
#include <stdio.h>

using namespace std;

typedef struct node
{
	node *left;
	node *right;
	int value;
}Bitreenode,*BinaryTree;

void printpost(node *n)
{
	if(n->left!=NULL)
		printpost(n->left);
	if(n->right!=NULL)
		printpost(n->right);
	printf("%d ",n->value);
}

void printin(node *n)
{
	if(n->left!=NULL)
		printin(n->left);
	printf("%d ",n->value);
	if(n->right!=NULL)
		printin(n->right);
	
}

void printfrist(node *n)
{
	printf("%d ",n->value);
	if(n->left!=NULL)
		printfrist(n->left);
	if(n->right!=NULL)
		printfrist(n->right);
}

void insert(BinaryTree &T,int a)
{	
	if (T==NULL)
	{
		T=new node;
		T->left=NULL;
		T->right=NULL;
		T->value=a;
	}
	if(a>T->value)
		insert(T->right,a);
	if(a<T->value)
		insert(T->left,a);
}

int main()
{
	int num;
	cin>>num;
	int array[100];
	for (int i=0 ;i<num;++i)
	{
		scanf("%d",&array[i]);
	}

	BinaryTree Tree;
	Tree=NULL;
	for (int i=0;i<num;++i)
	{
		insert(Tree,array[i]);
	}
	cout<<"Post:"<<endl;
	printpost(Tree);
	cout<<endl;
	cout<<"Inorder:"<<endl;
	printin(Tree);
	cout<<endl;
	cout<<"Frist:"<<endl;
	printfrist(Tree);

	system("pause");
	return 0;
}