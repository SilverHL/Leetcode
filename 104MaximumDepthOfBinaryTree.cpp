#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x) {}
};

class Solution
{
public:
	int maxDepth(TreeNode *root)
	{
		if (root == NULL)
			return 0;
		int res = depth(root, 0);
		return res;
	}

	int depth(TreeNode *node, int dep)
	{
		if (node == NULL)
			return dep;
		return max(depth(node->left, dep + 1), depth(node->right, dep + 1));
	}
};