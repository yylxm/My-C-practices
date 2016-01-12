#include <iostream>
#include <vector>
#include <stack>

using  namespace std;

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
	void CreateTree(BinaryTree & T)//二叉树的建立
	{
		char data;
		cin >> data;
		
		if (data == '#' )
			T == NULL;
		else
		{
			T = new TreeNode(data-'0');
			CreateTree(T->left);
			CreateTree(T->right);
		}
	}

	void inorder(TreeNode*root, vector<int>&ret)
	{
		if (root != NULL)
		{
			inorder(root->left,ret);
			ret.push_back(root->val);
			inorder(root->right,ret);
		}
	}

	vector<int> inorderTraversal(TreeNode* root) {//递归
		vector<int> ret;
		inorder(root, ret);
		return ret;
	}

	vector<int> inorderTraversal2(TreeNode *root)//非递归
	{
		stack<TreeNode *> s;
		TreeNode *p = root;
		vector<int> ret;
		while (p!=NULL || !s.empty())
		{
			
			while (p != NULL)
			{
				s.push(p);
				p = p->left;
			}
			if (!s.empty())
			{
				p = s.top();
				s.pop();
				ret.push_back(p->val);
				p = p->right;
			}
		}
		return ret;
	}

	
};

int main()
{
	Solution s;
	BinaryTree T;
	s.CreateTree(T);
	vector<int> ret;
	ret = s.inorderTraversal2(T);
	for (int i = 0; i < ret.size(); i++)
	{
		cout << ret[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}