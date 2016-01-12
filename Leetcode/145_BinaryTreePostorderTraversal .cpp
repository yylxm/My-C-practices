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
	 bool tag;//采用标志位来进行后序遍历
     TreeNode(int x) : val(x),tag(false), left(NULL), right(NULL) {}
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
	
	void postorder(TreeNode*root, vector<int>&ret)
	{
		if (root != NULL)
		{
			postorder(root->left, ret);		
			postorder(root->right, ret);
			ret.push_back(root->val);
		}
	}

	vector<int> postorderTraversal(TreeNode* root) {//递归
		vector<int> ret;
		postorder(root, ret);
		return ret;
	}

	vector<int> postorderTraversal2(TreeNode* root) {//非递归
		stack<TreeNode *> s;
		TreeNode * p = root;
		vector<int> ret;
		while (p!=NULL|| !s.empty())
		{
			while (p!=NULL)
			{
				s.push(p);
				p = p->left;
			}

			if (!s.empty())
			{
				p = s.top();
				if (p->tag)
				{
					s.pop();
					ret.push_back(p->val);
					p = NULL;
				}
				else
				{
					p->tag = true;
					p = p->right;
				}
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
	ret = s.postorderTraversal2(T);
	for (int i = 0; i < ret.size(); i++)
	{
		cout << ret[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}