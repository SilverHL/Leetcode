#include <iostream>
#include <map>
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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		map<int, int> inMap;
		for (int i = 0; i < inorder.size(); i++)
			inMap[inorder[i]]++;

		TreeNode *root = buildTree(preorder, 0, preorder.size(), inorder, 0, inorder.size(), inMap);
	}

	TreeNode *buildTree(vector<int> &preorder, int preStart, int preEnd, 
						vector<int> &inorder, int inStart, int inEnd, 
						map<int, int> inMap)
	{
		if (preStart > preEnd ||
			inStart > inEnd)
			return NULL;

		TreeNode *root = new TreeNode(preorder[preStart]);
		int inRoot = inMap[root->val];
		int numsLeft = inRoot - inStart;

		root->left = buildTree(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, inMap);
		root->right = buildTree(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inMap);

		return root;
	}
};