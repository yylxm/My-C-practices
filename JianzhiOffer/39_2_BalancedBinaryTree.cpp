/*#include <iostream>

using namespace std;

struct TreeNode
{
	int m_Value;
	TreeNode* m_pLeft;
	TreeNode* m_pRight;
};

bool IsBalanced(TreeNode* pRoot, int *depth)
{
	if (pRoot == NULL)
	{
		return true;
		*depth = 0;
	}

	int left, right;
	if (IsBalanced(pRoot->m_pLeft, &left) && IsBalanced(pRoot->m_pRight, &right))
	{
		int diff = left - right;
		if (diff <= 1 && diff >= -1)
		{
			*depth = 1 + (left > right ? left : right);
			return true;
		}

	}
	return false;
}

bool IsBalanded(TreeNode *pRoot)
{
	int depth = 0;
	return IsBalanced(pRoot, &depth);
}

int main()
{
	system("pause");
	return 0;
}*/



#include<stdio.h>
#include <iostream>
using namespace std;
#define SQR(x) (x*x)

class B
{
public:
	int i;
	short j;
};
int main()
{
	int a, b = 2;
	a = SQR(b + 3);
	printf("a=%d\n", a);
	printf("%d\n", sizeof(B));
	system("pause");
	return 0;
}

