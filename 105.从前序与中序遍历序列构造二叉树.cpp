#include <vector>
#include <iostream>

using namespace std;
/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, 0, preorder.size()-1, 
              inorder, 0, inorder.size()-1); 
    }

    TreeNode* build(vector<int>& preorder, int preLeft, int preRight,
                    vector<int>& inorder, int inLeft, int inRight) {
        
        if (preLeft > preRight) 
            return NULL;
        if (inLeft > inRight) 
            return NULL;
        TreeNode *root = new TreeNode(preorder[preLeft]);

        int i = 0;
        for (i = inLeft; i <= inRight; ++i) 
            if (inorder[i] == preorder[preLeft]) 
                break;   
        i -= inLeft;
        root->left = build(preorder, preLeft + 1, i + preLeft,        
                           inorder, inLeft, inLeft + i - 1);
        root->right = build(preorder,i + preLeft + 1, preRight,
                            inorder, inLeft + i + 1, inRight);
        return root;
    }
};
// @lc code=end

