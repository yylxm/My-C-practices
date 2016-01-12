#include <iostream>
#include <vector>

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
	int maxDepth(TreeNode* root) {
		if (root ==NULL )
		{
			return 0;
		}
		int depthL = maxDepth(root->left);
		int depthR = maxDepth(root->right);

		return depthL > depthR ? depthL + 1 : depthR + 1;
	}
};

int main()
{
	Solution s;
	TreeNode *T;
	s.CreateTree(T);
	int ret = s.maxDepth(T);
	cout << ret << endl;
	system("pause");
	return 0;
}