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
	TreeNode* build(vector<int> &preorder, int pstart, int pend, vector<int> &inorder, int istart, int iend)
	{
		TreeNode *T = new TreeNode(preorder[pstart]);

		if (pstart==pend && istart==iend)
		{
			return T ;
		}
		int k = 0;
		for (int  i = istart; i <= iend; i++)
		{
			if (inorder[i] == preorder[pstart])
				break;
			else
				k++;
		}
		if ((k-1)>=0)
			T->left = build(preorder, pstart + 1, pstart + k, inorder, istart, istart + k - 1);

		if ( (pend - pstart - k -1) >= 0)
			T->right = build(preorder, pstart + k + 1, pend, inorder, istart + k + 1, iend);

		return T;
	}

	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
	{
		TreeNode *T = NULL;
		if (preorder.size() == NULL || inorder.size() == NULL)
		{
			return T;
		}
		T = build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
		return T;
	}

	void preorder(TreeNode* root)
	{
		if (root != NULL)
		{
			
			preorder(root->left);
			cout << root->val << " ";
			preorder(root->right);
		}
	}

};

int main()
{
	int arr[] = { 1, 2 };
	int arr2[] = { 1,2 };
	vector<int> ivec1(arr, arr + 2);
	vector<int>ivec2(arr2, arr2 + 2);
	Solution s;
	TreeNode *T = s.buildTree(ivec1, ivec2);
	s.preorder(T);
	system("pause");
	return 0;
}