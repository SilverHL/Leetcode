#include <iostream>
#include <vector>
#include <stack>

using namespace std;

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
	vector<vector<int>> levelOrder(TreeNode *root)
	{
		TreeNode *cur = root;
		TreeNode *end = root;
		TreeNode *nextCur;

		deque<TreeNode *> deq;
		deq.push_back(cur);

		vector<vector<int>> res;
		vector<int> tmp;

		while (deq.size())
		{
			cur = deq.front();
			tmp.push_back(cur->val);
			deq.pop_front();
			
			if (cur->left)
			{
				deq.push_back(cur->left);
				nextCur = cur->left;
			}

			if (cur->right)
			{
				deq.push_back(cur->right);
				nextCur = cur->right;
			}

			if (end == cur)
			{
				res.push_back(tmp);
				end = nextCur;
				tmp.clear();
			}
		}

		return res;
	}
};