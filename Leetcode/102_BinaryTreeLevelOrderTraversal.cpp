#include <iostream>
#include <vector>
#include <queue>

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

	void CreateTree(BinaryTree &T)//´´½¨¶þ²æÊ÷
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

	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int> >ret;
		vector<int > temp;
		if (root == NULL)
			return ret;
		queue< TreeNode *> q;
		TreeNode *p=root;
		//TreeNode *Tag = new TreeNode();

		q.push(p);
		q.push(NULL);
		while (!q.empty())
		{
			p = q.front();
			while (p != NULL)
			{
				q.pop();
				temp.push_back(p->val);
				if (p->left != NULL)
				{
					q.push(p->left);
				}
				if (p->right != NULL)
				{
					q.push(p->right);
				}
				p = q.front();
			}
			
			q.pop();
			ret.push_back(temp);
			temp.clear();

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
	TreeNode * T;
	s.CreateTree(T);
	vector<vector<int> > ret;
	ret = s.levelOrder(T);
	for (auto iter = ret.begin(); iter!= ret.end(); iter++)
	{
		for (auto iter2 =(*iter).begin(); iter2!=(*iter).end(); iter2++)
		{
			cout << *iter2 << " ";
		}
		cout << endl;
	}
	//cout << endl;
	system("pause");
	return 0;
}
