#include <iostream>
#include <vector>

using namespace std;

/**
* Definition for a binary tree node.
**/
typedef struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 }*BinaryTree;

class Solution {
public:

	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == NULL && q == NULL)
		{
			return true;
		}
		else if (p == NULL || q == NULL)
			return false;
		else
		{
			if (p->val!=q->val)
			{
				return false;
			}

			bool isleft = isSameTree(p->left, q->left);
			bool isright = isSameTree(p->right, q->right);

			if (isleft && isright)
				return true;
			else
			{
				//isleft = isSameTree(p->left, q->right);
				//isright = isSameTree(p->right, q->left);

				//if (isleft && isright)
				//	return true;
				//else
					return false;
			}
		}

	}

	void CreateTree(BinaryTree &T)
	{
		char data;
		cin >> data;
		if (data == '#')
			T = NULL;
		else
		{
			T = new TreeNode(data - '0');
			CreateTree(T->left);
			CreateTree(T->right);
		}
	}
};

int main()
{
	TreeNode *T1 = NULL;
	TreeNode *T2 = NULL;
	Solution s;
	s.CreateTree(T1);
	s.CreateTree(T2);
	if (s.isSameTree(T1,T2))
	{
		cout << "Yes!" << endl;
	}
	else
		cout << "No!" << endl;

	system("pause");
	return 0;
}







