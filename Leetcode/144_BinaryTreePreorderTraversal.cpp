#include <iostream>
#include <vector>
#include <stack>

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

	void CreateTree(BinaryTree &T)//创建二叉树
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

	void preorder(TreeNode* root, vector<int> &ret)
	{
		if (root != NULL)
		{
			ret.push_back(root->val);
			preorder(root->left,ret);
			preorder(root->right,ret);
		}
	}

	vector<int> preorderTraversal(TreeNode* root) {//递归
		vector<int> ret;
		preorder(root, ret);
		return ret;
	}

	vector<int> preorderTraversal2(TreeNode* root) {//非递归
		vector<int> ret;
		stack<TreeNode *> s;
		TreeNode *p = root;
		while (p!=NULL || !s.empty())
		{
			while (p!=NULL)
			{
				ret.push_back(p->val);
				s.push(p);
				p = p->left;
			}

			if (!s.empty())
			{
				p = s.top();
				s.pop();
				p = p->right;
			}

		}
		return ret;
	}
};

int main()
{
	Solution s;
	TreeNode * T;
	s.CreateTree(T);
	vector<int> ret;
	ret = s.preorderTraversal2(T);
	for (int i = 0; i < ret.size(); i++)
	{
		cout << ret[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}