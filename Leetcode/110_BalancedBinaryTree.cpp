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
	int maxDepth(TreeNode* root) {
		if (root == NULL)
		{
			return 0;
		}
		int depthL = maxDepth(root->left);
		int depthR = maxDepth(root->right);

		return depthL > depthR ? depthL + 1 : depthR + 1;
	}

	bool isBalanced(TreeNode* root) {//ͨ����������������жϣ����ÿ���ڵ��������������Ȳ������1����Ϊһ��ƽ�������
		if (root == NULL)
			return true;
		int depthL = maxDepth(root->left);
		int depthR = maxDepth(root->right);
		int diff = abs(depthL - depthR);
		if (diff > 1)
			return false;
		return isBalanced(root->left) && isBalanced(root->right);
	}

	bool isBalanced2(TreeNode* root,int *depth) {//��ָoffer�ϸ����Ľⷨ����������ڵ㣬����ÿ���ڵ�ʱ����¼������ȣ�һ�߱���һ���ж�ÿ���ڵ��ǲ���ƽ��ġ�
		if (root == NULL)
		{
			*depth = 0;
			return true;
		}
		
		int left, right;
		if (isBalanced2(root->left, &left) && isBalanced2(root->right, &right))
		{
			int diff = abs(left - right);
			if (diff < 1)
			{
				*depth = max(left, right) + 1;
				return true;
			}
		}
		return false;
	}
};

int main()
{
	Solution s;
	TreeNode *T;
	s.CreateTree(T);
	int depth = 0;
	bool ret = s.isBalanced2(T,&depth);
	if (ret==true)
		cout << "Yes" << endl;
	else
		cout << "NO" << endl;
	system("pause");
	return 0;
}