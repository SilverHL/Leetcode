#include <cstring>
#include <vector>

using namespace std;
/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> path;
        bt(nums, path);
        return res;
    }

    void bt(vector<int> &nums, vector<int> &path) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (inVector(path, nums[i])) {
                continue;
            }
            path.push_back(nums[i]);
            bt(nums, path);
            path.pop_back();
        }
    }


    bool inVector(vector<int> &path, int i)
    {
        for (auto p : path) 
            if (p == i)  
                return true;
        return false;
    }
};
// @lc code=end

