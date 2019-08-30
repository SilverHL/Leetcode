#include <iostream>
#include <stack>
#include <vector>

using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	vector<int> inorderTraversal(TreeNode *root)
	{
		stack<TreeNode*> stk;
		vector<int> res;
		if (root == NULL)
			return res;

		TreeNode * cur = root;
		while (stk.size() || cur)
		{
			if (cur)
			{
				stk.push(cur);
				cur = cur->left;
			}
			else 
			{
				TreeNode *node = stk.top();
				res.push_back(node->val);
				stk.pop();
				cur = node->right;
			}
		}

		return res;
	}
};