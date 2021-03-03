#include <algorithm>
#include <cmath>

/*
 * @lc app=leetcode.cn id=1026 lang=cpp
 *
 * [1026] 节点与其祖先之间的最大差值
 */

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    int maxAncestorDiff(TreeNode* root) {
        int left = maxAncestorDiff(root->left, root->val, root->val);
        int right = maxAncestorDiff(root->right, root->val, root->val);
        return left > right ? left : right;
    }

    int maxAncestorDiff(TreeNode *root, int mx, int mi) {
        if (root == NULL)
            return 0;
        if (root->val > mx) 
            mx = root->val;
        if (root->val < mi) 
            mi = root->val;

        if (root->left == NULL && root->right == NULL) 
            return mx - mi;
        
        int left = maxAncestorDiff(root->left, mx, mi);
        int right = maxAncestorDiff(root->right, mx, mi);

        return left > right ? left : right;
    }
};
// @lc code=end

