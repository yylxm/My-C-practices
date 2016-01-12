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
	int minDepth(TreeNode* root) {
		if (root == NULL)
		{
			return 0;
		}
		if (root->left == NULL || root->right ==NULL)
		{
			return max(minDepth(root->left), minDepth(root->right)) + 1;
		}
		else
			return min(minDepth(root->left), minDepth(root->right)) + 1;
	}
};

int main()
{
	Solution s;
	TreeNode *T;
	s.CreateTree(T);
	int ret = s.minDepth(T);
	cout << ret << endl;
	system("pause");
	return 0;
}