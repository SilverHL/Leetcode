#include <iostream>

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	bool isValidBST(TreeNode *root) {
		if (root == NULL)
			return true;
		return validate(root, NULL, NULL);
	}

	bool validate(TreeNode *node, TreeNode *min, TreeNode *max)
	{
		if (!node)
			return true;
		if (max && node->val >= max->val || min && node->val <= min->val)
			return false;

		return validate(node->left, min, node) && validate(node->right, node, max);
	}
};