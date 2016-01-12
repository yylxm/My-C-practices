#include <iostream>
#include <stdio.h>

using namespace std;

typedef struct node
{
	char   value;
	node *left;
	node *right;
}Bitreenode,*Bitree;

void buildtree(Bitree &head,char f[],int f_b,int f_e,char m[],int m_b,int m_e)
{
	 int mark;	
	 if(m_b>m_e)
		 return ;
	 for (int i=m_b;i<=m_e;++i)//找到根节点
	 {
		 if(m[i]==f[f_b])
			 mark=i;
	 }
	 head=new node;
	 head->left=NULL;
	 head->right=NULL;
	 head->value=f[f_b];
	 buildtree(head->left,f,f_b+1,f_b+mark-m_b,m,m_b,mark-1);
	 buildtree(head->right,f,f_b+mark-m_b+1,f_e,m,mark+1,m_e);
	 //cout<<head->value;
}

void printlast(node *n)
{
	if(n->left!=NULL)
		printlast(n->left);
	if(n->right!=NULL)
		printlast(n->right);
	printf("%c",n->value);
	printf("\n");
}
void clear(node *n)
{
	if(n->left!=NULL)
		clear(n->left);
	if(n->right!=NULL)
		clear(n->right);
	delete n;
	n=NULL;
}

int main()
{
	char f[26];
	char m[26];
	scanf("%s",&f);
	scanf("%s",&m);
	int sf=strlen(f);
	int sm=strlen(m);
	Bitree tree;
	buildtree(tree,f,0,sf-1,m,0,sm-1);

	printlast(tree);
	clear(tree);

	system("pause");
	return 0;
}