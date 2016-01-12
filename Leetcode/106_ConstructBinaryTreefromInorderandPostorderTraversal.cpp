#include <iostream>
#include <vector>

using namespace std;

/**
* Definition for a binary tree node.
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* build(vector<int> &inorder, int istart, int iend, vector<int> &postorder, int pstart, int pend)
	{
		TreeNode *T = new TreeNode(postorder[pend]);

		if (pstart == pend && istart == iend)
		{
			return T;
		}
		int k = 0;
		for (int i = istart; i <= iend; i++)
		{
			if (inorder[i] == postorder[pend])
				break;
			else
				k++;
		}
		if ((k - 1) >= 0)
			T->left = build(inorder, istart, istart + k - 1, postorder, pstart, pstart + k - 1);

		if ((iend - istart - k - 1) >= 0)
			T->right = build(inorder, istart + k + 1, iend, postorder, pstart + k , pend-1);

		return T;
	}

	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
	{
		TreeNode *T = NULL;
		if (inorder.size() == NULL || postorder.size() == NULL)
		{
			return T;
		}
		T = build(inorder, 0,inorder.size() - 1, postorder, 0, postorder.size() - 1);
		return T;
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
	int arr[] = { 4,5,2,6,7,3,1 };
	int arr2[] = { 4,2,5,1,6,3,7 };
	vector<int> ivec1(arr, arr + 7);
	vector<int>ivec2(arr2, arr2 + 7);
	Solution s;
	TreeNode *T = s.buildTree(ivec2, ivec1);
	s.preorder(T);
	system("pause");
	return 0;
}