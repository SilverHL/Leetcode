#include <vector>
#include <algorithm>

using std::vector;
using std::max;
/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (!n || n == 1) return true;
        int maxPos = nums[0];

        for (int i = 0; i < n-1; ++i) {
            if (i <= maxPos) {
                maxPos = max(maxPos, nums[i]+i);
            } else
                break;
        }

        return maxPos >= n-1;
    }
};
// @lc code=end

