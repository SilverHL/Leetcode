#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, 0, inorder.size()-1, 
                    postorder, 0, postorder.size()-1);        
    }

    TreeNode *build(vector<int>& inorder, int inLeft, int inRight, 
                 vector<int>& postorder, int postLeft, int postRight)
    {
        if (inLeft > inRight || postLeft > postRight)
            return nullptr;
        
        int rootVal = postorder[postRight];
        int index = 0;
        for (int i = inLeft; i <= inRight; ++i) {
            if (inorder[i] == rootVal) {
                index = i;
                break;
            }
        }   

        int leftSize = index - inLeft;

        TreeNode* root = new TreeNode(rootVal);
        root->left = build(inorder, inLeft, index - 1, 
                           postorder, postLeft, postLeft + leftSize - 1);
        root->right = build(inorder, index + 1, inRight, 
                            postorder, postLeft + leftSize, postRight - 1);
        return root;
    }
};
// @lc code=end

