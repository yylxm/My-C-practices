#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
* Definition for a binary tree node.
* */
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
	vector<int> rightSideView(TreeNode* root) {
		queue<TreeNode*> q;
		TreeNode* temp = new TreeNode(NULL);
		TreeNode* p = NULL;
		vector<int> ret;
		if (root==NULL)
		{
			return ret;
		}

		q.push(root);
		q.push(NULL);
		int pre;//用于保存每一层的最后一个数字
		while (!q.empty())
		{
			 p = q.front();
			 while (p!=NULL)
			 {
				 if (p->left!=NULL)
				 {
					 q.push(p->left);

				 }
				 if (p->right!=NULL)
				 {
					 q.push(p->right);
				 }
				 pre = p->val;
				 q.pop();
				 p = q.front();
			 }
			 ret.push_back(pre);
			 q.pop();
			 if (!q.empty())
			 {
				 
				 q.push(NULL);
			 }
		}
		return ret;
	}
};

int main()
{
	Solution s;
	TreeNode *T;
	s.CreateTree(T);
	vector<int> ret = s.rightSideView(T);
	for (int i = 0; i < ret.size(); i++)
	{
		cout << ret[i] << ",";
	}
	cout << endl;
	system("pause");
	return 0;
}