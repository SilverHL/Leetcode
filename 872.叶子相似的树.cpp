#include <vector>
#include <stack>

using namespace std;

/*
 * @lc app=leetcode.cn id=872 lang=cpp
 *
 * [872] 叶子相似的树
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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1 = go_through(root1);
        vector<int> v2 = go_through(root2);

        return v1 == v2;



    }

    vector<int> go_through(TreeNode *root) {
        vector<int> leafs;
        stack<TreeNode *> stk;

        stk.push(root);
        while (!stk.empty()) {
            auto t = stk.top();
            stk.pop();

            if (t->left || t->right) {
                if (t->right) {
                    stk.push(t->right);
                }
                if (t->left) {
                    stk.push(t->left);
                }
            } else {
                leafs.push_back(t->val);
            }

        }
        return leafs;
    }
};
// @lc code=end


