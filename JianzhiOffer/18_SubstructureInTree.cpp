/*#include <iostream>

using namespace std;

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

bool DoesTree1HaveTree2(BinaryTreeNode* Root1,BinaryTreeNode* Root2)
{
	if(Root2==NULL)
		return true;
	if(Root1==NULL)
		return false;

	if(Root1->m_nValue!=Root2->m_nValue)
		return false;

	return DoesTree1HaveTree2(Root1->m_pLeft,Root2->m_pLeft)&&DoesTree1HaveTree2(Root1->m_pRight,Root2->m_pRight);
}

bool HasSubtree(BinaryTreeNode* Root1,BinaryTreeNode* Root2)
{
	bool result=false;
	if(Root1 !=NULL && Root2!=NULL)
	{
		if(Root1->m_nValue==Root2->m_nValue)
		{
			result=DoesTree1HaveTree2(Root1,Root2);
		}
		if(!result)
			result=HasSubtree(Root1->m_pLeft,Root2);
		if(!result)
			result=HasSubtree(Root2->m_pRight,Root2);
	}
	return result;
}

int main()
{
	char p[6]={0};
	cout<<sizeof(p)<<endl;
	system("pause");
	return 0;
}*/

#include <iostream>

using namespace std;

class A{
	int i;
	

	void foo(){}
	typedef char* (*f)(void*);
	
}a;
union U
	{
		char buff[3];
		int i;
	}u;
enum{red,green,blue,yellow,black,write,reblue,blackwrite,yellowblue}color;
int main(void)
{
	cout<<"sizeof(a):"<<sizeof(a)<<endl;
	cout<<"sizeof(u):"<<sizeof(u)<<endl;
	cout<<"sizeof(color):"<<sizeof(color)<<endl;
	system("pause");
	return 0;
}