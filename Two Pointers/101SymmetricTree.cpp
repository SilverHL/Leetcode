#include <iostream>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution
{
	bool begin(TreeNode *left, TreeNode *right)
	{
		if (left == NULL && right == NULL)
			return false;

		if (left != NULL && right != NULL)
		{
			if (left->val == right->val)
			{
				return begin(left->left, right->right) &&
					begin(left->right, right->left);
			}
		}

		return false;
	}
	


public:
	bool isSymmetric(TreeNode *root)
	{
		if (root == NULL)
			return true;
		return begin(root->left, root->right);
	}
};