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
	int maxDepth(TreeNode* root) {
		if (root == NULL)
		{
			return 0;
		}
		int depthL = maxDepth(root->left);
		int depthR = maxDepth(root->right);

		return depthL > depthR ? depthL + 1 : depthR + 1;
	}

	bool isBalanced(TreeNode* root) {//通过二叉树的深度来判断，如果每个节点的左右子树的深度差都不超过1，则为一颗平衡二叉树
		if (root == NULL)
			return true;
		int depthL = maxDepth(root->left);
		int depthR = maxDepth(root->right);
		int diff = abs(depthL - depthR);
		if (diff > 1)
			return false;
		return isBalanced(root->left) && isBalanced(root->right);
	}

	bool isBalanced2(TreeNode* root,int *depth) {//剑指offer上给出的解法，后序遍历节点，遍历每个节点时，记录他的深度，一边遍历一边判断每个节点是不是平衡的。
		if (root == NULL)
		{
			*depth = 0;
			return true;
		}
		
		int left, right;
		if (isBalanced2(root->left, &left) && isBalanced2(root->right, &right))
		{
			int diff = abs(left - right);
			if (diff < 1)
			{
				*depth = max(left, right) + 1;
				return true;
			}
		}
		return false;
	}
};

int main()
{
	Solution s;
	TreeNode *T;
	s.CreateTree(T);
	int depth = 0;
	bool ret = s.isBalanced2(T,&depth);
	if (ret==true)
		cout << "Yes" << endl;
	else
		cout << "NO" << endl;
	system("pause");
	return 0;
}