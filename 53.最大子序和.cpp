#include <climits>
/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxSubArray(nums, 0, nums.size()-1);
    }

    int maxSubArray(vector<int>& nums, int l, int r) 
    {
        if (l > r) {
            return INT_MIN;
        }

        int sum = 0, ml = 0, mr = 0;
        int m = l + (r - l) / 2;

        int lmax = maxSubArray(nums, l, m-1);
        int rmax = maxSubArray(nums, m+1, r);

        for (int i = m-1, sum = 0; i >= 0; --i) {
            sum += nums[i];
            ml = max(sum, ml);
        }

        for (int i = m+1, sum = 0; i <= r; ++i) {
            sum += nums[i];
            mr = max(sum, mr);
        }

        return max(max(lmax, rmax), ml + mr + nums[m]);
    }
};
// @lc code=end

