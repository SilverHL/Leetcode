#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, 0, nums.size()-1);
    }

    TreeNode* build(vector<int>& nums, int left, int right) 
    {
        if (left > right) 
            return nullptr;

        auto tmp = max_element(nums.begin()+left, nums.begin()+right+1);
        int idx = tmp - nums.begin();

        TreeNode *root = new TreeNode(*tmp);
        root->left = build(nums, left, idx-1);
        root->right = build(nums, idx+1, right);

        return root;
    }
};
// @lc code=end

