#include <vector>
#include <climits>
#include <algorithm>

using std::vector;
/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.empty())
            return {};

        int left = 0;
        int right = 0;
        int n = nums.size();
        int mx = INT_MIN;

        while (right < n) 
        {
            mx = std::max(mx, nums[right]);
            right++;
            k--;

            if (k == 0) 
            {

                left++;
            }
        }
    }

};
// @lc code=end

