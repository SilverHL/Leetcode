#include <vector>
#include <cstring>
#include <set>

using namespace std;

/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> path;
        vector<bool> vis(nums.size(), false);
        sort(nums.begin(), nums.end());
        bt(nums, path, vis);
        return res;
    }

    void bt(vector<int> &nums, vector<int> &path, vector<bool> &vis)
    {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (vis[i]) 
                continue;
            if (i > 0 && nums[i] == nums[i-1] && !vis[i-1])  
                continue;
            vis[i] = true;
            path.push_back(nums[i]);
            bt(nums, path, vis);
            vis[i] = false;
            path.pop_back();
        }
    }

};
// @lc code=end

