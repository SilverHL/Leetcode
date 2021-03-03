#include <queue>

using namespace std;

/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 */
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int depth = 1;
        deque<TreeNode *> path;
        path.push_back(root);

        while (!path.empty()) {
            int n = path.size();
            while (n--) {
                TreeNode *cur = path.front();
                path.pop_front();
                if (!cur->left && !cur->right) return depth;

                if (cur->left) path.push_back(cur->left);
                if (cur->right) path.push_back(cur->right);
            }
            depth++;
        }
        return depth; 
    }
};
// @lc code=end

