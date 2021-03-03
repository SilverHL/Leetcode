#include <iostream>
#include <cmath>
/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        int l = 1;
        int r = 1;

        while (left != nullptr) {
            l++;
            left = left->left;
        }
        while (right != nullptr)
        {
            r++;
            right = right->right;
        }

        if (l == r) {
            return (int)pow(2, l) - 1;
        } else {
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
};
// @lc code=end

