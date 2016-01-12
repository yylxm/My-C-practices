#include <iostream>
#include <vector>

using namespace std;
/**
* Definition for a binary tree node.
*/
typedef struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}*BinaryTree;

class Solution {
public:
	void CreateTree(BinaryTree & T)
	{
		char data;
		cin >> data;
		if (data == '#')
		{
			T = NULL;
		}
		else
		{
			T = new TreeNode(data - '0');
			CreateTree(T->left);
			CreateTree(T->right);
		}

	}

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {//µÝ¹é
		if (root==NULL)
		{
			return NULL;
		}
		if (root == p || root == q)
			return root;

		TreeNode *left = lowestCommonAncestor(root->left, p, q);
		TreeNode *right = lowestCommonAncestor(root->right, p, q);

		if (left && right)
			return root;
		return left ? left : right;
	}

	bool nodePath(TreeNode *root, TreeNode *p, vector<TreeNode* > &path)
	{
		if (root == NULL)
			return false;
		if (root->val!=p->val)
		{
			if (nodePath(root->left,p,path))
			{
				path.push_back(root);
				return true;
			}
			else 
			{
				if (nodePath(root->right, p, path))
				{
					path.push_back(root);
					return true;
				}
				else
					return false;		
			}		
		}
		else
		{
			path.push_back(root);
			return true;
		}	
	}

	TreeNode* lowestCommonAncestor2(TreeNode*root, TreeNode* p, TreeNode* q)//·ÇµÝ¹é
	{
		if (root == NULL)
			return NULL;
		if (root==p||root==q)
		{
			return root;
		}
		vector<TreeNode* > pPath;
		vector<TreeNode* > qPath;

		bool find = false;

		find = find | nodePath(root, p, pPath);
		find = find & nodePath(root, q, qPath);

		if (find)
		{
			if (pPath.size() < qPath.size())
			{
				int diff = qPath.size() - pPath.size();
				for (int i = diff, j = 0; i < qPath.size(); i++, j++)
				{
					if (pPath[j] == qPath[i])
						return pPath[j];
				}
			}
			else
			{
				int diff = pPath.size() - qPath.size();
				for (int i = diff, j = 0; i < pPath.size(); i++, j++)
				{
					if (qPath[j] == pPath[i])
						return qPath[j];
				}
			}
		}
		else
			return NULL;		
	}

};

int main()
{
	Solution s;
	TreeNode *T;
	s.CreateTree(T);
	char a, b;
	cin >> a >> b;
	TreeNode *p = new TreeNode(a - '0');
	TreeNode *q = new TreeNode(b - '0');
	TreeNode *ret=NULL;
	ret = s.lowestCommonAncestor(T, p, q);
	cout << ret->val << endl;
	
	system("pause");
	return 0;
}

