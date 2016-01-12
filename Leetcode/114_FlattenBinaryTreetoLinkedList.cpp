#include <iostream>
#include <vector>
#include <algorithm>

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

	void flatten(TreeNode* root) {
		if (root == NULL)
		{
			return ;
		}
		flatten(root->left);
		flatten(root->right);

		TreeNode *tempR = root->right;
		root->right = root->left;
		root->left = nullptr;
		while (root->right)
		{
			root = root->right;
		}
		root->right= tempR;
		
	}

	void preorder(TreeNode* root)
	{
		if (root != NULL)
		{
			cout << root->val << " ";
			preorder(root->left);
			preorder(root->right);
		}
	}
};

int main()
{
	Solution s;
	TreeNode *T;
	s.CreateTree(T);
	s.flatten(T);
	s.preorder(T);
	system("pause");
	return 0;
}