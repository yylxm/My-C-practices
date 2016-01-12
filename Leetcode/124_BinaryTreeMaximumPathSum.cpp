#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

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

	int maxtoRoot(TreeNode* root, int &Max)
	{
		if (!root) return 0;
		int left = maxtoRoot(root->left, Max);
		int right = maxtoRoot(root->right, Max);
		if (left < 0) left = 0;
		if (right < 0) right = 0;
		Max = max(Max, root->val + left + right);

		return root->val + max(right, left);
	}

	int maxPathSum(TreeNode* root) {
		int Max = INT_MIN;
		maxtoRoot(root, Max);
		return Max;
	}
};

int main()
{
	Solution s;
	TreeNode *T;
	s.CreateTree(T);
	int ret = s.maxPathSum(T);
	cout << ret << endl;
	
	system("pause");
	return 0;
}

