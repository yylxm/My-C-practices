#include <iostream>
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
	void CreateTree(BinaryTree &Root)
	{
		int data;
		cin >> data;
		if (data == -1)
			Root = NULL;
		else
		{
			Root = new TreeNode(data);
			CreateTree(Root->left);
			CreateTree(Root->right);
		}	
	}
	
	TreeNode* invertTree(TreeNode* root) {
		if (root!=NULL)
		{
			if (root->left != NULL || root->right != NULL)
			{
				TreeNode *L, *R;
				L = invertTree(root->left);
				R = invertTree(root->right);

				root->left = R;
				root->right = L;
			}
		}	
		return root;
	}

	void PrintTree(TreeNode *root)
	{
		if (root != NULL)
		{
			cout << root->val << " ";
			PrintTree(root->left);
			PrintTree(root->right);
		}
	}
};
int main()
{
	Solution s;
	BinaryTree T;
	s.CreateTree(T);
	T = s.invertTree(T);
	s.PrintTree(T);
	system("pause");
	return 0;
}