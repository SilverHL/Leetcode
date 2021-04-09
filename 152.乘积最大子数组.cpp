/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {

        if (nums.empty())
            return 0;
        int mx = nums[0];
        int mi = nums[0];
        int res = nums[0];
        int n = nums.size();

        for (int i = 1; i < n; ++i) {
            int p1 = mx * nums[i];
            int p2 = mi * nums[i];

            mx = max(nums[i], max(p1, p2));
            mi = min(nums[i], min(p1, p2));

            res = max(res, mx);
        }
        return res;
    }
};
// @lc code=end

