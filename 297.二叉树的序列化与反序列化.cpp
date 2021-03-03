#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
using std::string;
using namespace std;
/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
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
class Codec {
public:

    // Encodes a tree to a single string.
    // preorder
    /*
    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(out, root);
        return out.str();

    }
    void serialize(ostringstream &out, TreeNode *root)
    {
        if (root == nullptr) 
        {
            out << "# ";
            return;
        }

        out << root->val << " ";
        serialize(out, root->left);
        serialize(out, root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }

    TreeNode* deserialize(istringstream &in)
    {
        string val;
        in >> val;

        if (val == "#") 
            return nullptr;
        TreeNode *root = new TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }
    */
   // postorder
    string serialize(TreeNode* root)
    {
        ostringstream out;
        serialize(root, out);
        cout << out.str();
        return out.str();
    }

    void serialize(TreeNode* root, ostringstream& out)
    {
        if (root == nullptr) {
            out << "# ";
            return;
        }
 
        serialize(root->left, out);
        serialize(root->right, out);

        out << root->val << " ";
    }

    TreeNode* deserialize(string data)
    {
        reverse(data.begin(), data.end());
        istringstream in(data);
        return deserialize(in);
    }

    TreeNode* deserialize(istringstream& in)
    {
        string val;
        in >> val;
        cout << val << endl;
        if (val == "#") {
            return nullptr;
        }
        int symbol = 1;
        if (val.back() == '-') symbol = -1;
        TreeNode* root = new TreeNode(stoi(val) * symbol);
        root->right = deserialize(in);
        root->left = deserialize(in); 
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

