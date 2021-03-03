#include <iostream>


/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    bool isValidBST(TreeNode* root) {
        return isValid(root, nullptr, nullptr);        
    }

    bool isValid(TreeNode* root, TreeNode *min, TreeNode *max)
    {
        if (root == nullptr)  
            return true;
        if (min != nullptr && root->val <= min->val) return false;
        if (max != nullptr && root->val >= max->val) return false;

        return isValid(root->left, min, root) && 
                isValid(root->right, root, max);
    }
};
// @lc code=end

